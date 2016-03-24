# CMakeLists.txt

cmake_minimum_required(VERSION 2.6)

project(simmit)

# The version number
set(VERSION_MAJOR 0)
set(VERSION_MINOR 9)
set(VERSION_PATCH 0)

if(VERSION_PATCH MATCHES "0")
	set(VERSION_NUMBER "${VERSION_MAJOR}.${VERSION_MINOR}")
else()
	set(VERSION_NUMBER "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
endif()

# put our local cmake find scripts at the beginning of the cmake
# module search path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib 
    CACHE PATH "Output directory for static libraries.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    CACHE PATH "Output directory for shared libraries.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    CACHE PATH "Output directory for executables and DLL's.")

#Set executable files and library files
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

# Find necessary packages
find_package(PythonInterp REQUIRED)
find_package(PythonLibsNew REQUIRED)
find_package(NumPy REQUIRED)
include_directories(SYSTEM ${PYTHON_INCLUDE_DIRS})

#message("status: ${PYTHON_LIBRARIES}")

include(FindBoost)
find_package(Boost COMPONENTS python numpy REQUIRED )
include_directories(SYSTEM ${Boost_INCLUDE_DIRS} )

find_package(smartplus) 
if(SMARTPLUS_FOUND)
	include_directories(SYSTEM ${SMARTPLUS_INCLUDE_DIRS})
else()	
	FIND_LIBRARY(SMARTPLUS_LIBRARY NAMES  smartplus PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
endif(SMARTPLUS_FOUND)

find_package(arma2numpy) 
if(ARMA2NUMPY_FOUND)
	include_directories(SYSTEM ${ARMA2NUMPY_INCLUDE_DIRS})
else()	
	FIND_LIBRARY(ARMA2NUMPY_LIBRARY NAMES  arma2numpy PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
endif(ARMA2NUMPY_FOUND)

# Build type
if(NOT CMAKE_BUILD_TYPE)  # Debug by default
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel"
        FORCE)
endif()

message(STATUS "Build type ${CMAKE_BUILD_TYPE}")

# Set the CFLAGS and CXXFLAGS depending on the options the user specified.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter")

# Debugging CFLAGS.  Turn optimizations off; turn debugging symbols on.
if(DEBUG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -std=c++11")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -std=c++11")
  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -std=c++11")

else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -v -std=c++11")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -std=c++11")
  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -std=c++11")
endif(DEBUG)

if(APPLE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_CXX_FLAGS} -framework Accelerate")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -framework Accelerate")
  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -framework Accelerate")
endif()

#Inclusion of public headers
include_directories(include)

#Command file to get all the files in the src/ and include/
file(GLOB_RECURSE source_files src/smartplus_wrappers/* include/simmit/smartplus_wrappers/*)

#Add the files to the lib
add_library(smartplus MODULE ${source_files})
#Wrapper library set_target properties
set_target_properties(smartplus PROPERTIES PREFIX "" SUFFIX ".so")
#link against smartplus (C++ lib) and arma2numpy, and Boost for the wrappers
target_link_libraries(smartplus ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${SMARTPLUS_LIBRARY} ${ARMA2NUMPY_LIBRARY})



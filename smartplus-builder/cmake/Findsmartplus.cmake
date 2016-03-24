#.rst:
# Findsmartplus
# -------------
#
# Find smartplus
#
# Find the smartplus C++ library
#
# Using smartplus:
#
# ::
#
#   find_package(smartplus REQUIRED)
#   include_directories(${SMARTPLUS_INCLUDE_DIRS})
#   add_executable(foo foo.cc)
#   target_link_libraries(foo ${SMARTPLUS_LIBRARIES})
#
# This module sets the following variables:
#
# ::
#
#   SMARTPLUS_FOUND - set to true if the library is found
#   SMARTPLUS_INCLUDE_DIRS - list of required include directories
#   SMARTPLUS_LIBRARIES - list of libraries to be linked

#=============================================================================
# Copyright 2016 Yves Chemisky <yves.chemisky@gmail.com>
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================

#Look into classical UNIX and MAC paths, what follows is for Windows users
find_library(SMARTPLUS_LIBRARY
  NAMES smartplus
  PATHS "$ENV{ProgramFiles}/smartplus/lib"  "$ENV{ProgramFiles}/smartplus/lib64" "$ENV{ProgramFiles}/smartplus"
  )
find_path(SMARTPLUS_INCLUDE_DIR
  NAMES smartplus
  PATHS "$ENV{ProgramFiles}/smartplus/include"
  )
#======================

if (SMARTPLUS_FOUND)
  set(SMARTPLUS_INCLUDE_DIRS ${SMARTPLUS_INCLUDE_DIR})
  set(SMARTPLUS_LIBRARIES ${SMARTPLUS_LIBRARY})
endif ()


# Hide internal variables
mark_as_advanced(
  SMARTPLUS_INCLUDE_DIR
  SMARTPLUS_LIBRARY)

#======================
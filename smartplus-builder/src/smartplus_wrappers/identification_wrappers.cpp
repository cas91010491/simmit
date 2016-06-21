
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>
#include <simmit/arma2numpy/list_vector.hpp>

#include <simmit/smartplus_wrappers/Libraries/Identification/identification.hpp>
#include <simmit/smartplus_wrappers/Libraries/Identification/constants.hpp>
#include <simmit/smartplus_wrappers/Libraries/Identification/parameters.hpp>
#include <simmit/smartplus_wrappers/Libraries/Identification/optimize.hpp>

namespace bp = boost::python;
namespace bn = boost::numpy;
using namespace std;
using namespace arma;
using namespace smartpy;

BOOST_PYTHON_MODULE(identify) {

    Py_Initialize();
    bn::initialize();
    
    // Generation of the constant class
    bp::class_<smart::constants>("constants")
        .def(bp::init<const int &, const int &>())
        .def("__init__", build_constants_full)
        .def_readwrite("number", &smart::constants::number)
        .def_readwrite("value", &smart::constants::value)
        .def_readwrite("key", &smart::constants::key)
        .def_readwrite("ninput_files", &smart::constants::ninput_files)
        .add_property("input_values", constants_get_input_values, constants_set_input_values)
        .add_property("input_files", constants_get_input_files, constants_set_input_files)
     ;

    // Generation of the parameters class
    bp::class_<smart::parameters>("parameters")
        .def(bp::init<const int &, const double &, const double &>())
        .def("__init__", build_parameters_full)
        .def_readwrite("number", &smart::parameters::number)
        .def_readwrite("value", &smart::parameters::value)
        .def_readwrite("min_value", &smart::parameters::min_value)
        .def_readwrite("max_value", &smart::parameters::max_value)
        .def_readwrite("key", &smart::parameters::key)
        .def_readwrite("ninput_files", &smart::parameters::ninput_files)
        .add_property("input_files", parameters_get_input_files, parameters_set_input_files)
    ;
    
    // Register the identification solver
    bp::def("identification_solver", identification_solver);
    
    // Register the calc cost
    bp::def("calc_cost", calc_cost);
    
    //Functions related to constants
    bp::def("read_constants", read_constants_py);
    bp::def("copy_constants", copy_constants_py);
    bp::def("apply_constants", apply_constants_py);
    
    //Functions related to parameters
    bp::def("read_parameters", read_parameters_py);
    bp::def("copy_parameters", copy_parameters_py);
    bp::def("apply_parameters", apply_parameters_py);
    
    // Register the function specific for the solver
    bp::def("cost_solver", cost_solver);
    
    
}


///@file constants.cpp
///@brief Handle of input constants exposed in python
///@version 0.9

#include <iostream>
#include <fstream>
#include <assert.h>
#include <math.h>
#include <armadillo>

#include <simmit/arma2numpy/list_vector.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>
#include <smartplus/Libraries/Identification/parameters.hpp>
#include <simmit/smartplus_wrappers/Libraries/Identification/parameters.hpp>

using namespace std;
using namespace arma;

namespace smartpy{
    
//-------------------------------------------------------------
smart::parameters build_parameters_full(const int &mnumber, const double &mmin_value, const double &mmax_value, const std::string &mkey, const int &mninput_files, const boost::python::list &minput_files)
//-------------------------------------------------------------
{
    smart::parameters a;
    a.number = mnumber;
    a.min_value = mmin_value;
    a.max_value = mmax_value;
    a.value = (a.min_value+a.max_value)/2.;
    a.key = mkey;
    a.ninput_files = mninput_files;
    a.input_files = arma2numpy::py_list_to_std_vector_string(minput_files);
    return a;
}

//------------------------------------------------------
boost::python::list parameters_get_input_files(smart::parameters &self) {
    return arma2numpy::std_vector_to_py_list_string(self.input_files);
}
//------------------------------------------------------

//------------------------------------------------------
void parameters_set_input_files(smart::parameters &self, const boost::python::list &minput_values) {
    self.input_files = arma2numpy::py_list_to_std_vector_string(minput_values);
    self.ninput_files = self.input_files.size();
}
//------------------------------------------------------
    
    
} //namespace smartpy
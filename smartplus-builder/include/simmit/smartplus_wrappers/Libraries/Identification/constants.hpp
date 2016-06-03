

///@file constants.hpp
///@brief Handle of input constants exposed in python
///@version 1.0

#pragma once

#include <iostream>
#include <armadillo>
#include <smartplus/Libraries/Identification/constants.hpp>
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

smart::constants build_constants_full(const int &, const double &, const boost::numpy::ndarray &, const std::string &, const int &, const boost::python::list &);
    
boost::numpy::ndarray constants_get_input_values(smart::constants &);

boost::python::list constants_get_input_files(smart::constants &);

void constants_set_input_values(smart::constants &, const boost::numpy::ndarray &);

void constants_set_input_files(smart::constants &, const boost::python::list &);
    
} //namespace smart

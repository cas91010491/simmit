

///@file constants.hpp
///@brief Handle of input constants exposed in python
///@version 1.0

#pragma once

#include <iostream>
#include <armadillo>
#include <smartplus/Libraries/Identification/parameters.hpp>
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

smart::parameters build_parameters_full(const int &, const double&, const double &, const std::string&, const int &, const boost::python::list &);

boost::python::list parameters_get_input_files(smart::parameters &);

void parameters_set_input_files(smart::parameters &, const boost::python::list &);
    
} //namespace smart

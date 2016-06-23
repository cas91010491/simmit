#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//This function computes the response of materials for an homogeneous mixed thermomechanical loading path
void solver(const boost::python::str &, const boost::numpy::ndarray &, const int &, const double &, const double &, const double &, const double &, const double &, const boost::python::str &, const boost::python::str &, const boost::python::str &, const boost::python::str &);
 
//void solver();
    
} //namespace smartpy
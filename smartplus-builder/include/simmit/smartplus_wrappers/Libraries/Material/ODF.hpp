#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//This function computes the response of materials for an homogeneous mixed thermomechanical loading path
    boost::numpy::ndarray get_densities(const boost::numpy::ndarray &, const boost::python::str &, const boost::python::str &, const bool &radian);
    
void ODF_discretization(const int &, const int &, const double &, const double &, const boost::python::str &, const boost::numpy::ndarray &, const boost::python::str &, const boost::python::str &, const boost::python::str &, const boost::python::str &, const int &);
    
} //namespace smartpy
#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//This function reads material properties to prepare a simulation
    void read_matprops(int &, boost::numpy::ndarray &, int &, double &, double &, double &, double &, double &, const boost::python::str &, const boost::python::str &);
    
} //namespace smartpy
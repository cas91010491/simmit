#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//This function computes the response of materials for an homogeneous mixed thermomechanical loading path
double cost_solver(const boost::numpy::ndarray &);
    
} //namespace smartpy
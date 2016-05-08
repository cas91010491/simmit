#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//This function reads material properties to prepare a simulation
void read_matprops(int &nprops, boost::numpy::ndarray &, int &, double &, double &, double &, double &, double &);
    
} //namespace smartpy
#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//return the elastic stiffness tensor of a composite material
    boost::numpy::ndarray L_eff(const boost::python::str &, const boost::numpy::ndarray &, const int &, const double &, const double &, const double &, const double &, const double &, const boost::python::str &);
    
} //namespace smartpy
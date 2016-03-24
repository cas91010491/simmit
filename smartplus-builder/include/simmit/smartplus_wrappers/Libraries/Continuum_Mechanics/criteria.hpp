#pragma once
#include <string>
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{
    
//This function returns the Prager equivalent stress.
double Prager_stress(const boost::numpy::ndarray &, const double &, const double &);

//This function returns the derivative of the Prager equivalent stress.
boost::numpy::ndarray dPrager_stress(const boost::numpy::ndarray &, const double &, const double &);

//This function returns the Prager equivalent stress.
double Tresca_stress(const boost::numpy::ndarray &);

//This function returns the derivative of the Prager equivalent stress.
boost::numpy::ndarray dTresca_stress(const boost::numpy::ndarray &);
    
//This function computes the selected equivalent stress function
double Eq_stress(const boost::numpy::ndarray &, const std::string &, const boost::numpy::ndarray &);

//This function computes the deriavtive of the selected equivalent stress function
boost::numpy::ndarray dEq_stress(const boost::numpy::ndarray &, const std::string &, const boost::numpy::ndarray &);
    
} //namespace smartpy
#pragma once
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

namespace smartpy{

//This function returns the 3*3 rotation arma::matrix
boost::python::numpy::ndarray fillR_axis(const double &, const int &);

//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'stress'
//boost::python::numpy::ndarray fillQS(const double &, const int &);

//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'stress'
boost::python::numpy::ndarray fillQS(const boost::python::numpy::ndarray &);

//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'strain'
//boost::python::numpy::ndarray fillQE(const double &, const int &);
    
//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'strain'
boost::python::numpy::ndarray fillQE(const boost::python::numpy::ndarray &);

//These functions rotates a 6*6 stiffness arma::matrix (L)
//boost::python::numpy::ndarray rotateL(const boost::python::numpy::ndarray &, const double &, const int &);
boost::python::numpy::ndarray rotateL(const boost::python::numpy::ndarray &, const boost::python::numpy::ndarray &);
boost::python::numpy::ndarray rotate_l2g_L(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
boost::python::numpy::ndarray rotate_g2l_L(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates a 6*6 compliance arma::matrix (M)
//boost::python::numpy::ndarray rotateM(const boost::python::numpy::ndarray &, const double &, const int &);
boost::python::numpy::ndarray rotateM(const boost::python::numpy::ndarray &, const boost::python::numpy::ndarray &);
boost::python::numpy::ndarray rotate_l2g_M(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
boost::python::numpy::ndarray rotate_g2l_M(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates a 6*6 strain concentration (A)
//boost::python::numpy::ndarray rotateA(const boost::python::numpy::ndarray &, const double &, const int &);
boost::python::numpy::ndarray rotateA(const boost::python::numpy::ndarray &, const boost::python::numpy::ndarray &);
boost::python::numpy::ndarray rotate_l2g_A(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
boost::python::numpy::ndarray rotate_g2l_A(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates a 6*6 stress concentration (B)
//boost::python::numpy::ndarray rotateB(const boost::python::numpy::ndarray &, const double &, const int &);
boost::python::numpy::ndarray rotateB(const boost::python::numpy::ndarray &, const boost::python::numpy::ndarray &);
boost::python::numpy::ndarray rotate_l2g_B(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
boost::python::numpy::ndarray rotate_g2l_B(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates strain arma::vectors
//boost::python::numpy::ndarray rotate_strain(const boost::python::numpy::ndarray &, const double &, const int &);
boost::python::numpy::ndarray rotate_strain(const boost::python::numpy::ndarray &, const boost::python::numpy::ndarray &);
boost::python::numpy::ndarray rotate_l2g_strain(const boost::python::numpy::ndarray &, const double &, const double &, const double &);

//These functions rotates stress arma::vectors
//boost::python::numpy::ndarray rotate_stress(const boost::python::numpy::ndarray &, const double &, const int &);
boost::python::numpy::ndarray rotate_stress(const boost::python::numpy::ndarray &, const boost::python::numpy::ndarray &);
boost::python::numpy::ndarray rotate_l2g_stress(const boost::python::numpy::ndarray &, const double &, const double &, const double &);
    
} //namespace smartpy
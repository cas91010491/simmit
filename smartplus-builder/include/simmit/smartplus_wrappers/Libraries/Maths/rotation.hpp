#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//This function returns the 3*3 rotation arma::matrix
boost::numpy::ndarray fillR_axis(const double &, const int &);

//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'stress'
//boost::numpy::ndarray fillQS(const double &, const int &);

//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'stress'
boost::numpy::ndarray fillQS(const boost::numpy::ndarray &);

//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'strain'
//boost::numpy::ndarray fillQE(const double &, const int &);
    
//This function returns the 6*6 rotation arma::matrix of a arma::vector of type 'strain'
boost::numpy::ndarray fillQE(const boost::numpy::ndarray &);

//These functions rotates a 6*6 stiffness arma::matrix (L)
//boost::numpy::ndarray rotateL(const boost::numpy::ndarray &, const double &, const int &);
boost::numpy::ndarray rotateL(const boost::numpy::ndarray &, const boost::numpy::ndarray &);
boost::numpy::ndarray rotate_l2g_L(const boost::numpy::ndarray &, const double &, const double &, const double &);
boost::numpy::ndarray rotate_g2l_L(const boost::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates a 6*6 compliance arma::matrix (M)
//boost::numpy::ndarray rotateM(const boost::numpy::ndarray &, const double &, const int &);
boost::numpy::ndarray rotateM(const boost::numpy::ndarray &, const boost::numpy::ndarray &);
boost::numpy::ndarray rotate_l2g_M(const boost::numpy::ndarray &, const double &, const double &, const double &);
boost::numpy::ndarray rotate_g2l_M(const boost::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates a 6*6 strain concentration (A)
//boost::numpy::ndarray rotateA(const boost::numpy::ndarray &, const double &, const int &);
boost::numpy::ndarray rotateA(const boost::numpy::ndarray &, const boost::numpy::ndarray &);
boost::numpy::ndarray rotate_l2g_A(const boost::numpy::ndarray &, const double &, const double &, const double &);
boost::numpy::ndarray rotate_g2l_A(const boost::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates a 6*6 stress concentration (B)
//boost::numpy::ndarray rotateB(const boost::numpy::ndarray &, const double &, const int &);
boost::numpy::ndarray rotateB(const boost::numpy::ndarray &, const boost::numpy::ndarray &);
boost::numpy::ndarray rotate_l2g_B(const boost::numpy::ndarray &, const double &, const double &, const double &);
boost::numpy::ndarray rotate_g2l_B(const boost::numpy::ndarray &, const double &, const double &, const double &);
    
//These functions rotates strain arma::vectors
//boost::numpy::ndarray rotate_strain(const boost::numpy::ndarray &, const double &, const int &);
boost::numpy::ndarray rotate_strain(const boost::numpy::ndarray &, const boost::numpy::ndarray &);
boost::numpy::ndarray rotate_l2g_strain(const boost::numpy::ndarray &, const double &, const double &, const double &);

//These functions rotates stress arma::vectors
//boost::numpy::ndarray rotate_stress(const boost::numpy::ndarray &, const double &, const int &);
boost::numpy::ndarray rotate_stress(const boost::numpy::ndarray &, const boost::numpy::ndarray &);
boost::numpy::ndarray rotate_l2g_stress(const boost::numpy::ndarray &, const double &, const double &, const double &);
    
} //namespace smartpy
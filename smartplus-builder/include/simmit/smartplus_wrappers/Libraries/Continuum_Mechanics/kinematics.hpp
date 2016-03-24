#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{
    
//This function computes the gradient of displacement (Lagrangian) from the deformation gradient tensor
boost::numpy::ndarray G_UdX(const boost::numpy::ndarray &);

//This function computes the gradient of displacement (Eulerian) from the deformation gradient tensor
boost::numpy::ndarray G_Udx(const boost::numpy::ndarray &);

//This function computes the Right Cauchy-Green C
boost::numpy::ndarray R_Cauchy_Green(const boost::numpy::ndarray &);

//This function computes the Left Cauchy-Green B
boost::numpy::ndarray L_Cauchy_Green(const boost::numpy::ndarray &);

//This function computes the common Right (or Left) Cauchy-Green invariants
boost::numpy::ndarray Inv_X(const boost::numpy::ndarray &);

//This function computes the Cauchy deformation tensor c
boost::numpy::ndarray Cauchy(const boost::numpy::ndarray &);

//This function computes the Green-Lagrange finite strain tensor E
boost::numpy::ndarray Green_Lagrange(const boost::numpy::ndarray &);

//This function computes the Euler-Almansi finite strain tensor A
boost::numpy::ndarray Euler_Almansi(const boost::numpy::ndarray &);

//This function computes the velocity difference (F,DF,DTime)
boost::numpy::ndarray finite_L(const boost::numpy::ndarray &, const boost::numpy::ndarray &, const double &);

//This function computes the spin tensor W (correspond to Jaumann rate) (F,DF,DTime)
boost::numpy::ndarray finite_W(const boost::numpy::ndarray &, const boost::numpy::ndarray &, const double &);

//This function computes the spin tensor Omega (corrspond to Green-Naghdi rate)
// Note : here R is the is the rigid body rotation in the RU or VR polar decomposition of the deformation gradient F (R,DR,DTime)
boost::numpy::ndarray finite_Omega(const boost::numpy::ndarray &, const boost::numpy::ndarray &, const double &);

//This function computes the deformation rate D (F,DF,DTime)
boost::numpy::ndarray finite_D(const boost::numpy::ndarray &, const boost::numpy::ndarray &, const double &);

//This function computes the increment of finite rotation (Omega0, Omega1, DTime)
boost::numpy::ndarray finite_DQ(const boost::numpy::ndarray &, const boost::numpy::ndarray &, const double &);
    
} //namespace smartpy

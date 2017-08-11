
#include <armadillo>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Maths/rotation.hpp>
#include <simmit/smartplus_wrappers/Libraries/Maths/rotation.hpp>

namespace bn = boost::python::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//This function returns the 3*3 rotation matrix
bn::ndarray fillR_axis(const double &alpha, const int & axis) {
    return mat2array(smart::fillR(alpha,axis));
}
    
//This function returns the 3*3 rotation matrix
//bn::ndarray fillR_euler(const double &psi, const double &theta, const double &phi) {
//    return mat2array(smart::fillR(alpha,axis));
//}

//This function returns the 6*6 rotation matrix of a vector of type 'stress'
/*bn::ndarray fillQS(const double &alpha, const int & axis) {
    return mat2array(smart::fillQS(alpha,axis));
}*/

//This function returns the 6*6 rotation matrix of a vector of type 'stress'
bn::ndarray fillQS(const bn::ndarray &ndR) {
    mat R = array2mat(ndR);
    return mat2array(smart::fillQS(R));
}
    
//This function returns the 6*6 rotation matrix of a vector of type 'strain'
/*bn::ndarray fillQE(const double alpha, const int & axis) {
    return mat2array(smart::fillQE(alpha,axis));
}*/

//This function returns the 6*6 rotation matrix of a vector of type 'strain'
bn::ndarray fillQE(const bn::ndarray &ndR) {
    mat R = array2mat(ndR);
    return mat2array(smart::fillQE(R));
}

//This function rotates a 6*6 stiffness matrix (L)
/*bn::ndarray rotateL(const bn::ndarray &ndL, const double &alpha, const int & axis) {
    mat L = array2mat(ndL);
    return mat2array(smart::rotateL(L,alpha,axis);
}*/

//This function rotates a 6*6 stiffness matrix (L)
bn::ndarray rotateL(const bn::ndarray &ndL, const bn::ndarray &ndR) {
    mat L = array2mat(ndL);
    mat R = array2mat(ndR);
    return mat2array(smart::rotateL(L,R));
}

//This function rotates a 6*6 compliance matrix (M)
/*bn::ndarray rotateM(const bn::ndarray &ndM, const double &alpha, const int & axis) {
    mat M = array2mat(ndM);
    return mat2array(smart::rotateM(M,alpha,axis);
}*/

//This function rotates a 6*6 compliance matrix (M)
bn::ndarray rotateM(const bn::ndarray &ndM, const bn::ndarray &ndR) {
    mat M = array2mat(ndM);
    mat R = array2mat(ndR);
    return mat2array(smart::rotateM(M,R));
}

//This function rotates a 6*6 strain concentration (A)
/*bn::ndarray rotateA(const bn::ndarray &ndA, const double &alpha, const int & axis) {
    mat A = array2mat(ndA);
    return mat2array(smart::rotateA(A,alpha,axis);
}*/

//This function rotates a 6*6 strain concentration (A)
bn::ndarray rotateA(const bn::ndarray &ndA, const bn::ndarray &ndR) {
    mat A = array2mat(ndA);
    mat R = array2mat(ndR);
    return mat2array(smart::rotateA(A,R));
}

//This function rotates a 6*6 stress concentration (B)
/*bn::ndarray rotateB(const bn::ndarray &ndB, const double &alpha, const int & axis) {
    mat B = array2mat(ndB);
    return mat2array(smart::rotateB(B,alpha,axis);
}*/

//This function rotates a 6*6 stress concentration (B)
bn::ndarray rotateB(const bn::ndarray &ndB, const bn::ndarray &ndR) {
    mat B = array2mat(ndB);
    mat R = array2mat(ndR);
    return mat2array(smart::rotateB(B,R));
}

//This function rotates stress vectors
/*bn::ndarray rotate_stress(const bn::ndarray &nd, const double alpha, const int & axis) {
    vec v = array2vec(nd);
    return vec2array(smart::rotate_stress(v,alpha,axis));
}*/
                 
//This function rotates stress vectors
bn::ndarray rotate_stress(const bn::ndarray &nd, const bn::ndarray &ndR) {
    vec v = array2vec(nd);
    mat R = array2mat(ndR);
    return vec2array(smart::rotate_stress(v,R));
}

//This function rotates strain vectors
/*bn::ndarray rotate_strain(const bn::ndarray &nd, const double alpha, const int & axis) {
    vec v = array2vec(nd);
    return vec2array(smart::rotate_strain(v,alpha,axis));
}*/

//This function rotates stress vectors
bn::ndarray rotate_strain(const bn::ndarray &nd, const bn::ndarray &ndR) {
    vec v = array2vec(nd);
    mat R = array2mat(ndR);
    return vec2array(smart::rotate_strain(v,R));
}

//This function rotates strain vectors from a local to global set of coordinates (using Euler angles)
bn::ndarray rotate_l2g_strain(const bn::ndarray &ndE, const double &psi, const double &theta, const double &phi) {
    vec E = array2vec(ndE);
    return vec2array(smart::rotate_l2g_strain(E,psi,theta,phi));
}

//This function rotates strain vectors from a global to local set of coordinates (using Euler angles)
bn::ndarray rotate_g2l_strain(const bn::ndarray &ndE, const double &psi, const double &theta, const double &phi) {
    vec E = array2vec(ndE);
    return vec2array(smart::rotate_g2l_strain(E,psi,theta,phi));
}

//This function rotates stress vectors from a local to global set of coordinates (using Euler angles)
bn::ndarray rotate_l2g_stress(const bn::ndarray &ndS, const double &psi, const double &theta, const double &phi) {
 vec S = array2vec(ndS);
 return vec2array(smart::rotate_l2g_strain(S,psi,theta,phi));
}

//This function rotates stress vectors from a global to local set of coordinates (using Euler angles)
bn::ndarray rotate_g2l_stress(const bn::ndarray &ndS, const double &psi, const double &theta, const double &phi) {
 vec S = array2vec(ndS);
 return vec2array(smart::rotate_g2l_stress(S,psi,theta,phi));
}

//This function rotates stiffness matrices (L) from a local to global set of coordinates (using Euler angles)
bn::ndarray rotate_l2g_L(const bn::ndarray &ndL, const double &psi, const double &theta, const double &phi) {
    mat L = array2mat(ndL);
    return mat2array(smart::rotate_l2g_L(L,psi,theta,phi));
}

//This function rotates stiffness matrices (L) from a global to local set of coordinates (using Euler angles)
bn::ndarray rotate_g2l_L(const bn::ndarray &ndL, const double &psi, const double &theta, const double &phi) {
    mat L = array2mat(ndL);
    return mat2array(smart::rotate_g2l_L(L,psi,theta,phi));
}

//This function rotates compliance matrices (M) from a local to global set of coordinates (using Euler angles)
bn::ndarray rotate_l2g_M(const bn::ndarray &ndM, const double &psi, const double &theta, const double &phi) {
    mat M = array2mat(ndM);
    return mat2array(smart::rotate_l2g_M(M,psi,theta,phi));
}

//This function rotates compliance matrices (M) from a global to local set of coordinates (using Euler angles)
bn::ndarray rotate_g2l_M(const bn::ndarray &ndM, const double &psi, const double &theta, const double &phi) {
    mat M = array2mat(ndM);
    return mat2array(smart::rotate_g2l_M(M,psi,theta,phi));
}

//This function rotates strain concentration matrices (A) from a local to global set of coordinates (using Euler angles)
bn::ndarray rotate_l2g_A(const bn::ndarray &ndA, const double &psi, const double &theta, const double &phi) {
    mat A = array2mat(ndA);
    return mat2array(smart::rotate_l2g_A(A,psi,theta,phi));
}

//This function rotates strain concentration matrices (A) from a global to local set of coordinates (using Euler angles)
bn::ndarray rotate_g2l_A(const bn::ndarray &ndA, const double &psi, const double &theta, const double &phi) {
    mat A = array2mat(ndA);
    return mat2array(smart::rotate_g2l_A(A,psi,theta,phi));
}

//This function rotates stress concentration matrices (B) from a local to global set of coordinates (using Euler angles)
bn::ndarray rotate_l2g_B(const bn::ndarray &ndB, const double &psi, const double &theta, const double &phi) {
 mat B = array2mat(ndB);
 return mat2array(smart::rotate_l2g_B(B,psi,theta,phi));
}

//This function rotates stress concentration matrices (B) from a global to local set of coordinates (using Euler angles)
bn::ndarray rotate_g2l_B(const bn::ndarray &ndB, const double &psi, const double &theta, const double &phi) {
 mat B = array2mat(ndB);
 return mat2array(smart::rotate_g2l_B(B,psi,theta,phi));
}
    
} //namepsace smartpy
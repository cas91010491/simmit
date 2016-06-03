
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Continuum_Mechanics/constitutive.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/constitutive.hpp>

namespace bn = boost::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//Returns the fourth order identity tensor written in Voigt notation Ireal
bn::ndarray Ireal() {
    mat m = smart::Ireal();
    return mat2array(m);
}

//Returns the volumic of the identity tensor Ireal written in Voigt notation
bn::ndarray Ivol() {
    mat m = smart::Ivol();
    return mat2array(m);
}

//Returns the deviatoric of the identity tensor Ireal written in Voigt notation
bn::ndarray Idev() {
    mat m = smart::Idev();
    return mat2array(m);
}

//Returns the fourth order identity tensor Iˆ written in Voigt notation
bn::ndarray Ireal2() {
    mat m = smart::Ireal2();
    return mat2array(m);
}

//Returns the deviatoric of the identity tensor Iˆ written in Voigt notation
bn::ndarray Idev2() {
    mat m = smart::Idev2();
    return mat2array(m);
}

//Returns the expansion vector
bn::ndarray Ith() {
    vec v = smart::Ith();
    return vec2array(v);
}

//Returns the stress 2 strain operator
bn::ndarray Ir2() {
    vec v = smart::Ir2();
    return vec2array(v);
}

//Returns the strain 2 stress operator
bn::ndarray Ir05() {
    vec v = smart::Ir05();
    return vec2array(v);
}

//Provides the elastic stiffness tensor for an isotropic material.
//The two first arguments are a couple of Lamé coefficients. The third argument specify which couple has been provided and the order of coefficients.
//Exhaustive list of possible third argument :
// ‘Enu’,’nuE,’Kmu’,’muK’, ‘KG’, ‘GK’, ‘lambdamu’, ‘mulambda’, ‘lambdaG’, ‘Glambda’.
bn::ndarray L_iso(const double &C1, const double &C2, string conv){
    mat m = smart::L_iso(C1,C2,conv);
    return mat2array(m);
}

//Provides the elastic compliance tensor for an isotropic material.
//The two first arguments are a couple of Lamé coefficients. The third argument specify which couple has been provided and the order of coefficients.
//Exhaustive list of possible third argument :
//‘Enu’,’nuE,’Kmu’,’muK’, ‘KG’, ‘GK’, ‘lambdamu’, ‘mulambda’, ‘lambdaG’, ‘Glambda’.
bn::ndarray M_iso(const double &C1, const double &C2, string conv){
    mat m = smart::M_iso(C1,C2,conv);
    return mat2array(m);
}

//Returns the elastic stiffness tensor for a cubic material.
//Arguments are the stiffness coefficients C11, C12 and C44.
bn::ndarray L_cubic(const double &C11, const double &C12, const double &C44){
    mat m = smart::L_cubic(C11,C12,C44);
    return mat2array(m);
}

//Returns the elastic compliance tensor for an isotropic material.
//Arguments are the stiffness coefficients C11, C12 and C44.
bn::ndarray M_cubic(const double &C11, const double &C12, const double &C44){
    mat m = smart::M_cubic(C11,C12,C44);
    return mat2array(m);
}

//Returns the elastic stiffness tensor for an orthotropic material.
//Arguments are the stiffness coefficients Cii or E and nu's
bn::ndarray L_ortho(const double &C11, const double &C12, const double &C13, const double &C22, const double &C23, const double &C33, const double &C44, const double &C55, const double &C66, string conv){
    mat m = smart::L_ortho(C11,C12,C13,C22,C23,C33,C44,C55,C66,conv);
    return mat2array(m);
}

//Returns the elastic compliance tensor for an orthotropic material.
//Arguments are the stiffness coefficients Cii or E and nu's
bn::ndarray M_ortho(const double &C11, const double &C12, const double &C13, const double &C22, const double &C23, const double &C33, const double &C44, const double &C55, const double &C66, string conv){
    mat m = smart::M_ortho(C11,C12,C13,C22,C23,C33,C44,C55,C66,conv);
    return mat2array(m);
}

//Returns the elastic stiffness tensor for an isotropic transverse material.
//Arguments are longitudinal Young modulus EL, transverse young modulus, Poisson’s ratio for loading along the longitudinal axis nuTL, Poisson’s ratio for loading along the transverse axis nuTT, shear modulus GLT and the axis of symmetry.
bn::ndarray L_isotrans(const double &EL, const double &ET, const double &nuTL, const double &nuTT, const double &GLT, const int &axis){
    mat m = smart::L_isotrans(EL,ET,nuTL,nuTT,GLT,axis);
    return mat2array(m);
}

//Returns the elastic compliance tensor for an isotropic transverse material.
//Arguments are longitudinal Young modulus EL, transverse young modulus, Poisson’s ratio for loading along the longitudinal axis nuTL, Poisson’s ratio for loading along the transverse axis nuTT, shear modulus GLT and the axis of symmetry.
bn::ndarray M_isotrans(const double &EL, const double &ET, const double &nuTL, const double &nuTT, const double &GLT, const int &axis){
    mat m = smart::M_isotrans(EL,ET,nuTL,nuTT,GLT,axis);
    return mat2array(m);
}
//Provides the viscous tensor H an isotropic material.
//The two first arguments are a couple of viscous coefficients (the first is bulk, the second is shear).
bn::ndarray H_iso(const double &etaB, const double &etaS){
    mat m = smart::H_iso(etaB,etaS);
    return mat2array(m);
}

} //namepsace smartpy
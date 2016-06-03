
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Continuum_Mechanics/recovery_props.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/recovery_props.hpp>

namespace bn = boost::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//Check the material symetries and the type of elastic response for a given stiffness tensor
void check_symetries(const bn::ndarray &nL, std::string &umat_type, int &axis, int &maj_sym) {
    
    mat L = array2mat(nL);
    smart::check_symetries(L, umat_type, axis, maj_sym);
}

//return a list of elastic properties for the isotropic case (E,nu) from a stiffness tensor
bn::ndarray L_iso_props(const bn::ndarray &nLt) {

    mat Lt = array2mat(nLt);
    vec props = smart::L_iso_props(Lt);
    return vec2array(props);
}
    
//return a list of elastic properties for the isotropic case (E,nu) from a compliance tensor
bn::ndarray M_iso_props(const bn::ndarray &nMt) {
    mat Mt = array2mat(nMt);
    vec props = smart::M_iso_props(Mt);
    return vec2array(props);
}

//return a list of elastic properties for the transversely isotropic case (EL,ET,nuTL,nuTT,GLT) from a stiffness tensor
bn::ndarray L_isotrans_props(const bn::ndarray &nLt, const int &axis) {
    mat Lt = array2mat(nLt);
    vec props = smart::L_isotrans_props(Lt, axis);
    return vec2array(props);
}
    
//return a list of elastic properties for the transversely isotropic case (EL,ET,nuTL,nuTT,GLT) from a compliance tensor
bn::ndarray M_isotrans_props(const bn::ndarray &nMt, const int &axis) {
    mat Mt = array2mat(nMt);
    vec props = smart::M_isotrans_props(Mt, axis);
    return vec2array(props);
}

//return a list of elastic properties for the cubic case (E,nu,G) from a stiffness tensor
bn::ndarray L_cubic_props(const bn::ndarray &nLt) {
    
    mat Lt = array2mat(nLt);
    vec props = smart::L_cubic_props(Lt);
    return vec2array(props);
}
    
//return a list of elastic properties for the cubic case (E,nu,G) from a compliance tensor
bn::ndarray M_cubic_props(const bn::ndarray &nMt) {
    
    mat Mt = array2mat(nMt);
    vec props = smart::M_cubic_props(Mt);
    return vec2array(props);
}
 
//return a list of elastic properties for the orthtropic case (E1,E2,E3,nu12,nu13,nu23,G12,G13,G23) from a stiffness tensor
bn::ndarray L_ortho_props(const bn::ndarray &nLt) {
    
    mat Lt = array2mat(nLt);
    vec props = smart::L_cubic_props(Lt);
    return vec2array(props);
}

//return a list of elastic properties for the orthtropic case (E1,E2,E3,nu12,nu13,nu23,G12,G13,G23) from a compliance tensor
bn::ndarray M_ortho_props(const bn::ndarray &nMt) {
    
    mat Mt = array2mat(nMt);
    vec props = smart::M_cubic_props(Mt);
    return vec2array(props);
}
    
//return a list of elastic properties for the anisotropic case (E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,deviations) from a compliance tensor
bn::ndarray M_aniso_props(const bn::ndarray &nMt) {
    
    mat Mt = array2mat(nMt);
    vec props = smart::M_aniso_props(Mt);
    return vec2array(props);
}


} //namepsace smartpy
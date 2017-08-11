
#include <armadillo>
#include <string>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Continuum_Mechanics/criteria.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/criteria.hpp>

namespace bn = boost::python::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//This function returns the Prager equivalent stress.
double Prager_stress(const bn::ndarray &nd, const double &b, const double &n) {
    vec v = array2vec(nd);
    return smart::Prager_stress(v,b,n);
}

//This function returns the derivative of the Prager equivalent stress.
bn::ndarray dPrager_stress(const bn::ndarray &nd, const double &b, const double &n) {
    vec v = array2vec(nd);
    return vec2array(smart::dPrager_stress(v,b,n));
}

//This function returns the Tresca equivalent stress.
double Tresca_stress(const bn::ndarray &nd) {
    vec v = array2vec(nd);
    return smart::Tresca_stress(v);
}

//This function returns the derivative of the Tresca equivalent stress.
bn::ndarray dTresca_stress(const bn::ndarray &nd) {
    vec v = array2vec(nd);
    return vec2array(smart::dTresca_stress(v));
}
    
//This function computes the selected equivalent stress function
double Eq_stress(const bn::ndarray &nd, const string &eq_type, const bn::ndarray &ndparam) {
    vec v = array2vec(nd);
    vec param = array2vec(ndparam);
    return smart::Eq_stress(v,eq_type,param);
}

//This function computes the deriavtive of the selected equivalent stress function
bn::ndarray dEq_stress(const bn::ndarray &nd, const string &eq_type, const bn::ndarray &ndparam) {
    vec v = array2vec(nd);
    vec param = array2vec(ndparam);
    return vec2array(smart::dEq_stress(v,eq_type,param));
}

} //namepsace smartpy
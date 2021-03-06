
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Continuum_Mechanics/damage.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/damage.hpp>

namespace bn = boost::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//This function returns damage evolution (/dt) considering a Weibull damage law
double damage_weibull(const bn::ndarray &nd, const double &damage, const double &alpha, const double &beta, const double &DTime, const std::string &criterion) {
    vec stress = array2vec(nd);
    return smart::damage_weibull(stress,damage,alpha,beta,DTime,criterion);
}

//This function returns damage evolution (/dt) considering Kachanov's creep damage law
double damage_kachanov(const bn::ndarray &nds, const bn::ndarray &nde, const double &damage, const double &A0, const double &r, const std::string &criterion) {
    vec stress = array2vec(nds);
    vec strain = array2vec(nde);
    return smart::damage_kachanov(stress,strain,damage,A0,r,criterion);
}

//This function returns the constant damage evolution (/dN) considering Woehler- Miner's damage law
double damage_miner(const double &S_max, const double &S_mean, const double &S_ult, const double &b, const double &B0, const double &beta, const double &Sl_0) {
    return smart::damage_miner(S_max,S_mean,S_ult,b,B0,beta,Sl_0);
}

//This function returns the constant damage evolution (/dN) considering Coffin-Manson's damage law
double damage_manson(const double &S_amp, const double &C2, const double &gamma2) {
    return smart::damage_manson(S_amp,C2,gamma2);
}

} //namepsace smartpy
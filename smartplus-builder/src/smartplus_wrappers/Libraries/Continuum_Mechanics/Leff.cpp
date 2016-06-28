
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Phase/phase_characteristics.hpp>
#include <smartplus/Libraries/Phase/state_variables_M.hpp>
#include <smartplus/Umat/umat_L_elastic.hpp>

#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/Leff.hpp>

namespace bp = boost::python;
namespace bn = boost::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//Check the material symetries and the type of elastic response for a given stiffness tensor
bn::ndarray L_eff(const bp::str &umat_name_py, const bn::ndarray &props_py, const int &nstatev, const double &psi_rve, const double &theta_rve, const double &phi_rve, const double &rho, const double &c_p, const bp::str &path_data_py) {

    vec props = array2vec(props_py);
    
    std::string umat_name = bp::extract<std::string>(umat_name_py);
    std::string path_data = bp::extract<std::string>(path_data_py);
    double T_init = 273.15;
    
    smart::phase_characteristics rve;
    rve.sptr_matprops->update(0, umat_name, 1, psi_rve, theta_rve, phi_rve, props.n_elem, props, rho, c_p);
    rve.construct(0,1);
    rve.sptr_sv_global->update(zeros(6), zeros(6), zeros(6), zeros(6), T_init, 0., 0., 0., nstatev, zeros(nstatev), zeros(nstatev));
    
    auto sv_M = std::dynamic_pointer_cast<smart::state_variables_M>(rve.sptr_sv_global);
    
    //Second we call a recursive method that find all the elastic moduli iof the phases
    smart::get_L_elastic(rve);
    
    return mat2array(sv_M->Lt);
}

} //namepsace smartpy
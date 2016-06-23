
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Solver/read.hpp>
#include <simmit/smartplus_wrappers/Libraries/Solver/read.hpp>

namespace bp = boost::python;
namespace bn = boost::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//This function reads material properties to prepare a simulation
void read_matprops(int &nprops, bn::ndarray &props, int &nstatev, double &psi_rve, double &theta_rve, double &phi_rve, double &rho, double &c_p, const bp::str &path_data_py, const bp::str &materialfile_py) {
    vec v = array2vec(props);
    string umat_name;
    string path_data = bp::extract<std::string>(path_data_py);
    string materialfile = bp::extract<std::string>(materialfile_py);
    smart::read_matprops(umat_name, nprops, v, nstatev, psi_rve, theta_rve, phi_rve, rho, c_p, path_data, materialfile);
    props = vec2array(v);
}
        
} //namepsace smartpy
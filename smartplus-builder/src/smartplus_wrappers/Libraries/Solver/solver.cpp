
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Solver/read.hpp>
#include <smartplus/Libraries/Solver/solver.hpp>
#include <simmit/smartplus_wrappers/Libraries/Solver/solver.hpp>

namespace bn = boost::numpy;
namespace bp = boost::python;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//This function computes the response of materials for an homogeneous mixed thermomechanical loading path    
void solver(const bp::str &umat_name_py, const bn::ndarray &props, const int &nstatev, const double &psi_rve, const double &theta_rve, const double &phi_rve, const double &rho, const double &c_p, const bp::str &pathfile_py, const bp::str &outputfile_py) {
    vec v = array2vec(props);

    std::string umat_name = bp::extract<std::string>(umat_name_py);
    std::string pathfile = bp::extract<std::string>(pathfile_py);
    std::string outputfile = bp::extract<std::string>(outputfile_py);
    smart::solver(umat_name, v, nstatev, psi_rve, theta_rve, phi_rve, rho, c_p, pathfile, outputfile);
}

} //namepsace smartpy
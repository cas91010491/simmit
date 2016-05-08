
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <arma2numpy/numpy_arma.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/constitutive.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/contimech.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/criteria.hpp>

#include <simmit/smartplus_wrappers/Libraries/Homogenization/eshelby.hpp>

#include <simmit/smartplus_wrappers/Libraries/Solver/read.hpp>
#include <simmit/smartplus_wrappers/Libraries/Solver/solver.hpp>

namespace bp = boost::python;
namespace bn = boost::numpy;
using namespace std;
using namespace arma;
using namespace smartpy;

BOOST_PYTHON_MODULE(smartplus) {

//    Py_Initialize();
    bn::initialize();
    
    // Register the from-python converters for constitutive
    bp::def("Ireal", Ireal);
    bp::def("Ivol", Ivol);
    bp::def("Idev", Idev);
    bp::def("Ireal2", Ireal2);
    bp::def("Idev2", Idev2);
    bp::def("Ith", Ith);
    bp::def("Ir2", Ir2);
    bp::def("Ir05", Ir05);
    bp::def("L_iso", L_iso);
    bp::def("M_iso", M_iso);
    bp::def("L_cubic", L_cubic);
    bp::def("M_cubic", M_cubic);
    bp::def("L_ortho", L_ortho);
    bp::def("M_ortho", M_ortho);
    bp::def("L_isotrans", L_isotrans);
    bp::def("M_isotrans", M_isotrans);
    bp::def("H_iso", H_iso);
    
    // Register the from-python converters for contimech
    bp::def("tr", tr);
    bp::def("dev", dev);
    bp::def("Mises_stress", Mises_stress);
    bp::def("eta_stress", eta_stress);
    bp::def("Mises_strain", Mises_strain);
    bp::def("eta_strain", eta_strain);
    bp::def("v2t_strain", v2t_strain);
    bp::def("t2v_strain", t2v_strain);
    bp::def("v2t_stress", v2t_stress);
    bp::def("t2v_stress", t2v_stress);
    bp::def("J2_stress", J2_stress);
    bp::def("J2_strain", J2_strain);
    bp::def("J3_stress", J3_stress);
    bp::def("J3_strain", J3_strain);
    bp::def("Macaulay_p", Macaulay_p);
    bp::def("Macaulay_n", Macaulay_n);
    bp::def("sign", smartpy::sign);
    bp::def("normal_ellipsoid", normal_ellipsoid);
    bp::def("sigma_int", sigma_int);
    bp::def("p_ikjl", p_ikjl);
    
    // Register the from-python converters for criteria
    bp::def("Prager_stress", Prager_stress);
    bp::def("dPrager_stress", dPrager_stress);
    bp::def("Tresca_stress", Tresca_stress);
    bp::def("dTresca_stress", dTresca_stress);
    bp::def("Eq_stress", Eq_stress);
    bp::def("dEq_stress", dEq_stress);

    // Register the from-python converters for eshelby
    bp::def("Eshelby_sphere", Eshelby_sphere);
    bp::def("Eshelby_cylinder", Eshelby_cylinder);
    bp::def("Eshelby_prolate", Eshelby_prolate);
    bp::def("Eshelby_oblate", Eshelby_oblate);
    bp::def("Eshelby", Eshelby);
    bp::def("T_II", T_II);
    
    // Register the from-python converters for read and solver
    bp::def("read_matprops", read_matprops);
    bp::def("solver", solver);
    

    
}
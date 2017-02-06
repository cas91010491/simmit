
#include <armadillo>
#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/constitutive.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/contimech.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/criteria.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/recovery_props.hpp>
#include <simmit/smartplus_wrappers/Libraries/Continuum_Mechanics/Leff.hpp>

#include <simmit/smartplus_wrappers/Libraries/Maths/rotation.hpp>

#include <simmit/smartplus_wrappers/Libraries/Material/ODF.hpp>

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
    
    // Register the from-python converters for recovery_props
    bp::def("check_symetries", check_symetries);
    bp::def("L_iso_props", L_iso_props);
    bp::def("M_iso_props", M_iso_props);
    bp::def("L_isotrans_props", L_isotrans_props);
    bp::def("M_isotrans_props", M_isotrans_props);
    bp::def("L_cubic_props", L_cubic_props);
    bp::def("M_cubic_props", M_cubic_props);
    bp::def("L_ortho_props", L_ortho_props);
    bp::def("M_ortho_props", M_ortho_props);
    bp::def("M_aniso_props", M_aniso_props);
    
    // Register the L_eff for composites
    bp::def("L_eff", L_eff);

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
    
    // Register the from-python converters for ODF functions
    bp::def("get_densities", get_densities);
    bp::def("ODF_discretization", ODF_discretization);
    
    //Register the from-python converters for rotation
    bp::def("fillR_axis", fillR_axis);
    bp::def("fillQS", fillQS);
    bp::def("fillQE", fillQE);
//    bp::def("rotate_vec", rotate_vec);
//    bp::def("rotate_mat", rotate_mat);
    bp::def("rotate_strain", rotate_strain);
    bp::def("rotate_stress", rotate_stress);
    bp::def("rotateL", rotateL);
    bp::def("rotateM", rotateM);
    bp::def("rotateA", rotateA);
    bp::def("rotateB", rotateB);
}
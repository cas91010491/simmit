#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//Check the material symetries and the type of elastic response for a given stiffness tensor
boost::python::dict check_symetries(const boost::numpy::ndarray &);

//return a list of elastic properties for the isotropic case (E,nu) from a stiffness tensor
boost::numpy::ndarray L_iso_props(const boost::numpy::ndarray &);

//return a list of elastic properties for the isotropic case (E,nu) from a compliance tensor
boost::numpy::ndarray M_iso_props(const boost::numpy::ndarray &);
    
//return a list of elastic properties for the transversely isotropic case (EL,ET,nuTL,nuTT,GLT) from a stiffness tensor
boost::numpy::ndarray L_isotrans_props(const boost::numpy::ndarray &, const int &);

//return a list of elastic properties for the transversely isotropic case (EL,ET,nuTL,nuTT,GLT) from a compliance tensor
boost::numpy::ndarray M_isotrans_props(const boost::numpy::ndarray &, const int &);

//return a list of elastic properties for the cubic case (E,nu,G) from a stiffness tensor
boost::numpy::ndarray L_cubic_props(const boost::numpy::ndarray &);

//return a list of elastic properties for the cubic case (E,nu,G) from a compliance tensor
boost::numpy::ndarray M_cubic_props(const boost::numpy::ndarray &);

//return a list of elastic properties for the orthtropic case (E1,E2,E3,nu12,nu13,nu23,G12,G13,G23) from a stiffness tensor
boost::numpy::ndarray L_ortho_props(const boost::numpy::ndarray &);

//return a list of elastic properties for the orthtropic case (E1,E2,E3,nu12,nu13,nu23,G12,G13,G23) from a compliance tensor
boost::numpy::ndarray M_ortho_props(const boost::numpy::ndarray &);

//return a list of elastic properties for the anisotropic case (E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,deviations) from a compliance tensor
boost::numpy::ndarray M_aniso_props(const boost::numpy::ndarray &);
    
} //namespace smartpy
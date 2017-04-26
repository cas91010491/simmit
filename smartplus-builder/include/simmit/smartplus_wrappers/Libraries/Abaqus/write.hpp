#pragma once
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

namespace smartpy{

//This function reads material properties to prepare a simulation
    void write_material(const boost::python::str &, const boost::python::numpy::ndarray &props, const int &nstatev, const double &psi_rve, const double &theta_rve, const double &phi_rve, const boost::python::str &path_data_py, const boost::python::str &inp_file_py);
    
void write_material_fromfile(const boost::python::str &, const boost::python::str &, const boost::python::str &);

void write_materials_fromfile(const int &, const int &, const int &, const boost::python::str &, const boost::python::str &);

//void write_steps_fromfile(const boost::python::str &, const boost::python::str &, const boost::python::str &);
    
} //namespace smartpy

#include <armadillo>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Abaqus/materials.hpp>
#include <smartplus/Libraries/Abaqus/section_characteristics.hpp>
#include <smartplus/Libraries/Abaqus/write.hpp>
#include <smartplus/Libraries/Solver/read.hpp>
#include <simmit/smartplus_wrappers/Libraries/Abaqus/write.hpp>

namespace bp = boost::python;
namespace bn = boost::python::numpy;
using namespace std;
using namespace arma;
using namespace smart;
using namespace arma2numpy;

namespace smartpy {

//This function reads material properties to prepare a simulation
void write_material(const bp::str &umat_name_py, const bn::ndarray &props, const int &nstatev, const double &psi_rve, const double &theta_rve, const double &phi_rve, const bp::str &path_data_py, const bp::str &inp_file_py) {
    vec v = array2vec(props);
    string umat_name = bp::extract<std::string>(umat_name_py);
    string path_data = bp::extract<std::string>(path_data_py);
    string inp_file = bp::extract<std::string>(inp_file_py);
    
    aba_material temp;
    temp.update(0, 100000, umat_name, 1, psi_rve, theta_rve, phi_rve, v.n_elem, nstatev, v);
    section_characteristics section_rve("ABAPC0", 100000, temp, "");
    write_section(section_rve, path_data, inp_file);
}

void write_material_fromfile(const bp::str &path_data_py, const bp::str &materialfile_py, const bp::str &inp_file_py) {

    string umat_name = "";
    int nprops = 0;
    vec props;
    int nstatev = 0;
    double psi_rve = 0.;
    double theta_rve = 0.;
    double phi_rve = 0.;
    string path_data = bp::extract<std::string>(path_data_py);
    string materialfile = bp::extract<std::string>(materialfile_py);
    string inp_file = bp::extract<std::string>(inp_file_py);
    
    smart::read_matprops(umat_name, nprops, props, nstatev, psi_rve, theta_rve, phi_rve, path_data, materialfile);
    
    aba_material temp;
    temp.update(0, 100000, umat_name, 1, psi_rve, theta_rve, phi_rve, props.n_elem, nstatev, props);
    section_characteristics section_rve("ABAPC0", 100000, temp, "");
    //write_section(section_rve, path_data, inp_file);
}
    
void write_materials_fromfile(const int &nsections, const int &nscale, const int &geom_type, const bp::str &path_data_py, const bp::str &inp_file_py) {
    
    string path_data = bp::extract<std::string>(path_data_py);
    string inp_file = bp::extract<std::string>(inp_file_py);
    section_characteristics section_rve;
    update_sections(section_rve, nsections, nscale, geom_type, path_data);
    write_sections(section_rve, path_data, inp_file);
}
        
} //namepsace smartpy
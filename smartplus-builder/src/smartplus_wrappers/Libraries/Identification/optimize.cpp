

///@file optimize.cpp
///@brief functions for optimization
///@version 1.0

#include <iostream>
#include <fstream>
#include <assert.h>
#include <math.h>
#include <armadillo>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

#include <smartplus/Libraries/Identification/read.hpp>
#include <smartplus/Libraries/Identification/individual.hpp>
#include <smartplus/Libraries/Identification/opti_data.hpp>
#include <smartplus/Libraries/Identification/constants.hpp>
#include <smartplus/Libraries/Identification/parameters.hpp>
#include <smartplus/Libraries/Identification/optimize.hpp>
#include <smartplus/Libraries/Identification/script.hpp>

#include <simmit/arma2numpy/numpy_arma.hpp>
#include <simmit/smartplus_wrappers/Libraries/Identification/optimize.hpp>

namespace bp = boost::python;
namespace bn = boost::python::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy{
    
double cost_solver(const bn::ndarray &p_py) {
    
    //transform p in a vec
    vec p = array2vec(p_py);
    
    int n_param = 0;
    int n_consts = 0;
    int n_files = 0;
    
    smart::ident_essentials(n_param, n_consts, n_files, "data", "ident_essentials.inp");
    
    if(n_param != int(p.n_elem)) {
        cout << "Error : n_param ( = " << n_param << " informed in the file : ident_essentials.inp do not match with the size of p : " << p.n_elem << endl;
        return 0.;
    }
    
    vector<smart::parameters> params(n_param);  //vector of parameters
    vector<smart::constants> consts(n_consts);  //vector of constants
    //Read the parameters and constants
    read_parameters(n_param, params);
    read_constants(n_consts, consts, n_files);
    
    //Get the data structures
    std::vector<smart::opti_data> data_exp(n_files);
    std::vector<smart::opti_data> data_weight(n_files);
    std::vector<smart::opti_data> data_num(n_files);
    
    Col<int> weight_types(3);
    vec weight_files = zeros(n_files);
    vector<vec> weight_cols(n_files);
    
    smart::read_data_exp(n_files, data_exp);
    smart::read_data_weights(n_files, weight_types, weight_files, weight_cols, data_weight, data_exp);
    smart::read_data_num(n_files, data_exp, data_num);
    
    /// Get the data vectors
    ///Import of the experimental data
    string data_exp_folder="exp_data";
    string data_num_folder="num_data";
    string materialfile="material.dat";
    string data_num_name="simul.txt";
    string simul_type = "SOLVE";

    string path_data="data";
    string path_keys="keys";
    string path_results="results";
    
    string data_num_name_ext = data_num_name.substr(data_num_name.length()-4,data_num_name.length());
    string data_num_name_root = data_num_name.substr(0,data_num_name.length()-4); //to remove the extension
    
    smart::individual ind(n_param, 1, 0.);
    ind.p = p;
    smart::run_simulation(simul_type, ind, n_files, params, consts, data_num, data_num_folder, data_num_name, path_data, path_keys, materialfile);
    
    //Get the experimental data and build the exp vector, and get the size of vectors
    int sizev = 0;
    read_data_exp(n_files, data_exp);
    for(int i=0; i<n_files; i++) {
        data_exp[i].import(data_exp_folder);
        sizev += data_exp[i].ndata * data_exp[i].ninfo;
    }
    
    //Get the weight data and build the weight vector
    for(int i=0; i<n_files; i++) {
        data_weight[i].import(data_exp_folder);
    }
    
    ///Computation of the cost function
    vec vexp = smart::calcV(data_exp, data_exp, n_files, sizev);
    vec vnum = smart::calcV(data_num, data_exp, n_files, sizev);
    vec W = smart::calcW(sizev, n_files, weight_types, weight_files, weight_cols, data_weight, data_exp);
    
    return smart::calcC(vexp, vnum, W);
}
    
double cost_odf(const bn::ndarray &p_py) {
    
    //transform p in a vec
    vec p = array2vec(p_py);
    
    int n_param = 0;
    int n_consts = 0;
    int n_files = 0;
    
    smart::ident_essentials(n_param, n_consts, n_files, "data", "ident_essentials.inp");
    
    if(n_param != int(p.n_elem)) {
        cout << "Error : n_param ( = " << n_param << " informed in the file : ident_essentials.inp do not match with the size of p : " << p.n_elem << endl;
        return 0.;
    }
    
    vector<smart::parameters> params(n_param);  //vector of parameters
    vector<smart::constants> consts(n_consts);  //vector of constants
    //Read the parameters and constants
    read_parameters(n_param, params);
    read_constants(n_consts, consts, n_files);
    
    //Get the data structures
    std::vector<smart::opti_data> data_exp(n_files);
    std::vector<smart::opti_data> data_weight(n_files);
    std::vector<smart::opti_data> data_num(n_files);
    
    Col<int> weight_types(3);
    vec weight_files = zeros(n_files);
    vector<vec> weight_cols(n_files);
    
    smart::read_data_exp(n_files, data_exp);
    smart::read_data_weights(n_files, weight_types, weight_files, weight_cols, data_weight, data_exp);
    smart::read_data_num(n_files, data_exp, data_num);
    
    /// Get the data vectors
    ///Import of the experimental data
    string data_exp_folder="exp_data";
    string data_num_folder="num_data";
    string materialfile="material.dat";
    string data_num_name="simul.txt";
    string simul_type = "SOLVE";
    
    string path_data="data";
    string path_keys="keys";
    string path_results="results";
    
    string data_num_name_ext = data_num_name.substr(data_num_name.length()-4,data_num_name.length());
    string data_num_name_root = data_num_name.substr(0,data_num_name.length()-4); //to remove the extension
    
    smart::individual ind(n_param, 1, 0.);
    ind.p = p;
    smart::run_simulation(simul_type, ind, n_files, params, consts, data_num, data_num_folder, data_num_name, path_data, path_keys, materialfile);
    
    //Get the experimental data and build the exp vector, and get the size of vectors
    int sizev = 0;
    read_data_exp(n_files, data_exp);
    for(int i=0; i<n_files; i++) {
        data_exp[i].import(data_exp_folder);
        sizev += data_exp[i].ndata * data_exp[i].ninfo;
    }
    
    //Get the weight data and build the weight vector
    for(int i=0; i<n_files; i++) {
        data_weight[i].import(data_exp_folder);
    }
    
    ///Computation of the cost function
    vec vexp = smart::calcV(data_exp, data_exp, n_files, sizev);
    vec vnum = smart::calcV(data_num, data_exp, n_files, sizev);
    vec W = smart::calcW(sizev, n_files, weight_types, weight_files, weight_cols, data_weight, data_exp);
    
    return smart::calcC(vexp, vnum, W);
}
    
} //namespace smart_py
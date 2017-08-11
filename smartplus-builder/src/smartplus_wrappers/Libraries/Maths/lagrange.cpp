
#include <armadillo>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <simmit/arma2numpy/numpy_arma.hpp>

#include <smartplus/Libraries/Maths/lagrange.hpp>
#include <simmit/smartplus_wrappers/Libraries/Maths/lagrange.hpp>

namespace bn = boost::python::numpy;
using namespace std;
using namespace arma;
using namespace arma2numpy;

namespace smartpy {

//This function is used to determine an exponential Lagrange Multiplier (like contact in Abaqus)
double lagrange_exp(const double &h, const double &c, const double &p0) {
    return smart::lagrange_exp(h,c,p0);
}

//This function is used to determine the first derivative of an exponential Lagrange Multiplier
double dlagrange_exp(const double &h, const double &c, const double &p0) {
    return smart::dlagrange_exp(h,c,p0);
}
    
//This function is used to determine a power-law Lagrange Multiplier for problem such x >= 0
double lagrange_pow_0(const double &x, const double &c, const double &p0, const double &n, const double &alpha) {
    return smart::lagrange_pow_0(x,c,p0,n,alpha);
}

//This function is used to determine the first derivative of a power-law Lagrange Multiplier for problem such x >= 0
double dlagrange_pow_0(const double &x, const double &c, const double &p0, const double &n, const double &alpha) {
    return smart::dlagrange_pow_0(x,c,p0,n,alpha);
}

//This function is used to determine a power-law Lagrange Multiplier for problem such x <= 1
double lagrange_pow_1(const double &x, const double &c, const double &p0, const double &n, const double &alpha) {
    return smart::lagrange_pow_1(x,c,p0,n,alpha);
}

//This function is used to determine the first derivative of a power-law Lagrange Multiplier for problem such x <= 1
double dlagrange_pow_1(const double &x, const double &c, const double &p0, const double &n, const double &alpha) {
    return smart::dlagrange_pow_1(x,c,p0,n,alpha);
}

//This function is used to determine the SECOND derivative of a power-law Lagrange Multiplier for problem such x <= 1
double d2lagrange_pow_1(const double &x, const double &c, const double &p0, const double &n, const double &alpha) {
    return smart::d2lagrange_pow_1(x,c,p0,n,alpha);
}
    
    
} //namepsace smartpy
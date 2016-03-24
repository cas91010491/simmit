#pragma once
#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace smartpy{

//Eshelby tensor for a sphere
boost::numpy::ndarray Eshelby_sphere(const double &);

//	Eshelby tensor determination. The cylinder is oriented in such a way that the axis direction is the 1 direction. a2=a3 here
boost::numpy::ndarray Eshelby_cylinder(const double &);

//	Eshelby tensor determination. The prolate shape is oriented in such a way that the axis direction is the 1 direction. a1>a2=a3 here
boost::numpy::ndarray Eshelby_prolate(const double &, const double &);

//	Eshelby tensor determination. The oblate shape is oriented in such a way that the axis direction is the 1 direction. a1<a2=a3 here
boost::numpy::ndarray Eshelby_oblate(const double &, const double &);

//Numerical Eshelby tensor determination
boost::numpy::ndarray Eshelby(const boost::numpy::ndarray &, const double &, const double &, const double &, const int &, const int &);

//Numerical Hill Interaction tensor determination
boost::numpy::ndarray T_II(const boost::numpy::ndarray &, const double &, const double &, const double &, const int &, const int &);

} //namespace smart

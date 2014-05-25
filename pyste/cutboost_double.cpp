
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cutboost.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(cutboost_double)
{
    class_< SPUC::cutboost<double,double> >("cutboost_double", init<  >())
        .def(init< const SPUC::cutboost<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type, SPUC::float_type >())
        .def(init< SPUC::float_type, SPUC::float_type >())
        .def_readwrite("ap", &SPUC::cutboost<double,double>::ap)
        .def_readwrite("k", &SPUC::cutboost<double,double>::k)
        .def_readwrite("g", &SPUC::cutboost<double,double>::g)
        .def_readwrite("a", &SPUC::cutboost<double,double>::a)
        .def("clock", &SPUC::cutboost<double,double>::clock)
        .def("set_depth", &SPUC::cutboost<double,double>::set_depth)
        .def("set_freq", &SPUC::cutboost<double,double>::set_freq)
    ;

}


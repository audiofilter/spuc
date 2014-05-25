
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cutboost.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(cutboost_float)
{
    class_< SPUC::cutboost<float,float> >("cutboost_float", init<  >())
        .def(init< const SPUC::cutboost<float,float>& >())
        .def(init< float, float, float >())
        .def(init< float, float >())
        .def_readwrite("ap", &SPUC::cutboost<float,float>::ap)
        .def_readwrite("k", &SPUC::cutboost<float,float>::k)
        .def_readwrite("g", &SPUC::cutboost<float,float>::g)
        .def_readwrite("a", &SPUC::cutboost<float,float>::a)
        .def("clock", &SPUC::cutboost<float,float>::clock)
        .def("set_depth", &SPUC::cutboost<float,float>::set_depth)
        .def("set_freq", &SPUC::cutboost<float,float>::set_freq)
    ;

}


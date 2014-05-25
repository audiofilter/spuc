
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cutboost.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(cutboost_int)
{
    class_< SPUC::cutboost<int,float> >("cutboost_int", init<  >())
        .def(init< const SPUC::cutboost<int,float>& >())
        .def(init< float, float, float >())
        .def(init< float, float >())
        .def_readwrite("ap", &SPUC::cutboost<int,float>::ap)
        .def_readwrite("k", &SPUC::cutboost<int,float>::k)
        .def_readwrite("g", &SPUC::cutboost<int,float>::g)
        .def_readwrite("a", &SPUC::cutboost<int,float>::a)
        .def("clock", &SPUC::cutboost<int,float>::clock)
        .def("set_depth", &SPUC::cutboost<int,float>::set_depth)
        .def("set_freq", &SPUC::cutboost<int,float>::set_freq)
    ;

}


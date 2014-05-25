
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass_2nd.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_2nd_int)
{
    class_< SPUC::allpass_2nd<int,float> >("allpass_2nd_int", init<  >())
        .def(init< const SPUC::allpass_2nd<int,float>& >())
        .def(init< float, float, optional< long int > >())
        .def(init< const char* >())
        .def_readwrite("fb2", &SPUC::allpass_2nd<int,float>::fb2)
        .def_readwrite("fb1", &SPUC::allpass_2nd<int,float>::fb1)
        .def_readwrite("fb0", &SPUC::allpass_2nd<int,float>::fb0)
        .def_readwrite("scale", &SPUC::allpass_2nd<int,float>::scale)
        .def_readwrite("Q", &SPUC::allpass_2nd<int,float>::Q)
        .def_readwrite("OQ", &SPUC::allpass_2nd<int,float>::OQ)
        .def("set_round_bits", &SPUC::allpass_2nd<int,float>::set_round_bits)
        .def("reset", &SPUC::allpass_2nd<int,float>::reset)
        .def("set_a", &SPUC::allpass_2nd<int,float>::set_a)
        .def("set_b", &SPUC::allpass_2nd<int,float>::set_b)
        .def("set_coeffs", &SPUC::allpass_2nd<int,float>::set_coeffs)
        .def("print", &SPUC::allpass_2nd<int,float>::print)
        .def("clock", &SPUC::allpass_2nd<int,float>::clock)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass_2nd.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_2nd_float)
{
    class_< SPUC::allpass_2nd<float,float> >("allpass_2nd_float", init<  >())
        .def(init< const SPUC::allpass_2nd<float,float>& >())
        .def(init< float, float, optional< long int > >())
        .def(init< const char* >())
        .def_readwrite("fb2", &SPUC::allpass_2nd<float,float>::fb2)
        .def_readwrite("fb1", &SPUC::allpass_2nd<float,float>::fb1)
        .def_readwrite("fb0", &SPUC::allpass_2nd<float,float>::fb0)
        .def_readwrite("scale", &SPUC::allpass_2nd<float,float>::scale)
        .def_readwrite("Q", &SPUC::allpass_2nd<float,float>::Q)
        .def_readwrite("OQ", &SPUC::allpass_2nd<float,float>::OQ)
        .def("set_round_bits", &SPUC::allpass_2nd<float,float>::set_round_bits)
        .def("reset", &SPUC::allpass_2nd<float,float>::reset)
        .def("set_a", &SPUC::allpass_2nd<float,float>::set_a)
        .def("set_b", &SPUC::allpass_2nd<float,float>::set_b)
        .def("set_coeffs", &SPUC::allpass_2nd<float,float>::set_coeffs)
        .def("print", &SPUC::allpass_2nd<float,float>::print)
        .def("clock", &SPUC::allpass_2nd<float,float>::clock)
    ;

}


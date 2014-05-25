
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_2nd.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_2nd_float)
{
    class_< SPUC::iir_2nd<float,float> >("iir_2nd_float", init< const SPUC::iir_2nd<float,float>& >())
        .def(init< float, float, float, float, float, optional< long int > >())
        .def(init< optional< float, float > >())
        .def(init< const char* >())
        .def_readwrite("fb2", &SPUC::iir_2nd<float,float>::fb2)
        .def_readwrite("fb1", &SPUC::iir_2nd<float,float>::fb1)
        .def_readwrite("fb0", &SPUC::iir_2nd<float,float>::fb0)
        .def("set_round_bits", &SPUC::iir_2nd<float,float>::set_round_bits)
        .def("get_round_bits", &SPUC::iir_2nd<float,float>::get_round_bits)
        .def("get_b0", &SPUC::iir_2nd<float,float>::get_b0)
        .def("reset", &SPUC::iir_2nd<float,float>::reset)
        .def("set_a", &SPUC::iir_2nd<float,float>::set_a)
        .def("set_b", &SPUC::iir_2nd<float,float>::set_b)
        .def("set_coeffs", &SPUC::iir_2nd<float,float>::set_coeffs)
        .def("print", &SPUC::iir_2nd<float,float>::print)
        .def("clock", &SPUC::iir_2nd<float,float>::clock)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_2nd.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_2nd_int)
{
    class_< SPUC::iir_2nd<int,float> >("iir_2nd_int", init< const SPUC::iir_2nd<int,float>& >())
        .def(init< float, float, float, float, float, optional< long int > >())
        .def(init< optional< float, float > >())
        .def(init< const char* >())
        .def_readwrite("fb2", &SPUC::iir_2nd<int,float>::fb2)
        .def_readwrite("fb1", &SPUC::iir_2nd<int,float>::fb1)
        .def_readwrite("fb0", &SPUC::iir_2nd<int,float>::fb0)
        .def("set_round_bits", &SPUC::iir_2nd<int,float>::set_round_bits)
        .def("get_round_bits", &SPUC::iir_2nd<int,float>::get_round_bits)
        .def("get_b0", &SPUC::iir_2nd<int,float>::get_b0)
        .def("reset", &SPUC::iir_2nd<int,float>::reset)
        .def("set_a", &SPUC::iir_2nd<int,float>::set_a)
        .def("set_b", &SPUC::iir_2nd<int,float>::set_b)
        .def("set_coeffs", &SPUC::iir_2nd<int,float>::set_coeffs)
        .def("print", &SPUC::iir_2nd<int,float>::print)
        .def("clock", &SPUC::iir_2nd<int,float>::clock)
    ;

}


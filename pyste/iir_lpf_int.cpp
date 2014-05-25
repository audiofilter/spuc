
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_lpf.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_lpf_int)
{
    class_< SPUC::iir_lpf<int,float> >("iir_lpf_int", init< const SPUC::iir_lpf<int,float>& >())
        .def(init< optional< float, long int > >())
        .def("get_a0", &SPUC::iir_lpf<int,float>::get_a0)
        .def("get_b0", &SPUC::iir_lpf<int,float>::get_b0)
        .def("clock", &SPUC::iir_lpf<int,float>::clock)
        .def("set_coeff", &SPUC::iir_lpf1<int,float>::set_coeff)
        .def("set_round_bits", &SPUC::iir_lpf1<int,float>::set_round_bits)
        .def("print", &SPUC::iir_lpf1<int,float>::print)
        .def("reset", &SPUC::iir_lpf1<int,float>::reset)
    ;

}


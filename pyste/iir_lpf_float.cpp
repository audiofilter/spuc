
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_lpf.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_lpf_float)
{
    class_< SPUC::iir_lpf<float,float> >("iir_lpf_float", init< const SPUC::iir_lpf<float,float>& >())
        .def(init< optional< float, long int > >())
        .def("get_a0", &SPUC::iir_lpf<float,float>::get_a0)
        .def("get_b0", &SPUC::iir_lpf<float,float>::get_b0)
        .def("clock", &SPUC::iir_lpf<float,float>::clock)
        .def("set_coeff", &SPUC::iir_lpf1<float,float>::set_coeff)
        .def("set_round_bits", &SPUC::iir_lpf1<float,float>::set_round_bits)
        .def("print", &SPUC::iir_lpf1<float,float>::print)
        .def("reset", &SPUC::iir_lpf1<float,float>::reset)
    ;

}


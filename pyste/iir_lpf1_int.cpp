
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_lpf1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_lpf1_int)
{
    class_< SPUC::iir_lpf1<int,float> >("iir_lpf1_int", init< const SPUC::iir_lpf1<int,float>& >())
        .def(init< optional< float, long int > >())
        .def(init< const char* >())
        .def("set_coeff", &SPUC::iir_lpf1<int,float>::set_coeff)
        .def("set_round_bits", &SPUC::iir_lpf1<int,float>::set_round_bits)
        .def("print", &SPUC::iir_lpf1<int,float>::print)
        .def("clock", &SPUC::iir_lpf1<int,float>::clock)
        .def("reset", &SPUC::iir_lpf1<int,float>::reset)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_coeff.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_coeff_float)
{
    class_< SPUC::fir_coeff<float> >("fir_coeff_float", init<  >())
        .def(init< const SPUC::fir_coeff<float>& >())
        .def(init< long int >())
        .def(init< const char* >())
        .def_readwrite("coeff", &SPUC::fir_coeff<float>::coeff)
        .def_readwrite("num_taps", &SPUC::fir_coeff<float>::num_taps)
        .def("settap", (void (SPUC::fir_coeff<float>::*)(long int, float) )&SPUC::fir_coeff<float>::settap)
        .def("gettap", &SPUC::fir_coeff<float>::gettap)
        .def("coeff_sum", &SPUC::fir_coeff<float>::coeff_sum)
        .def("set_size", &SPUC::fir_coeff<float>::set_size)
        .def("get_size", &SPUC::fir_coeff<float>::get_size)
        .def("read_taps", &SPUC::fir_coeff<float>::read_taps)
        .def("quantize", &SPUC::fir_coeff<float>::quantize)
        .def("print", &SPUC::fir_coeff<float>::print)
        .def("settap", (void (SPUC::fir_coeff<float>::*)(SPUC::smart_array<float>) )&SPUC::fir_coeff<float>::settap)
        .def("freqz_mag", &SPUC::fir_coeff<float>::freqz_mag)
    ;

}


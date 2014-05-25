
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_coeff.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_coeff_int)
{
    class_< SPUC::fir_coeff<int> >("fir_coeff_int", init<  >())
        .def(init< const SPUC::fir_coeff<int>& >())
        .def(init< long int >())
        .def(init< const char* >())
        .def_readwrite("coeff", &SPUC::fir_coeff<int>::coeff)
        .def_readwrite("num_taps", &SPUC::fir_coeff<int>::num_taps)
        .def("settap", (void (SPUC::fir_coeff<int>::*)(long int, int) )&SPUC::fir_coeff<int>::settap)
        .def("gettap", &SPUC::fir_coeff<int>::gettap)
        .def("coeff_sum", &SPUC::fir_coeff<int>::coeff_sum)
        .def("set_size", &SPUC::fir_coeff<int>::set_size)
        .def("get_size", &SPUC::fir_coeff<int>::get_size)
        .def("read_taps", &SPUC::fir_coeff<int>::read_taps)
        .def("quantize", &SPUC::fir_coeff<int>::quantize)
        .def("print", &SPUC::fir_coeff<int>::print)
        .def("settap", (void (SPUC::fir_coeff<int>::*)(SPUC::smart_array<int>) )&SPUC::fir_coeff<int>::settap)
        .def("freqz_mag", &SPUC::fir_coeff<int>::freqz_mag)
    ;

}


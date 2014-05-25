
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_decim.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_decim_float)
{
    class_< SPUC::fir_decim<float,float> >("fir_decim_float", init<  >())
        .def(init< const SPUC::fir_decim<float,float>& >())
        .def(init< long int >())
        .def(init< const char* >())
        .def_readwrite("coeff", &SPUC::fir<float,float>::coeff)
        .def_readwrite("z", &SPUC::fir<float,float>::z)
        .def_readwrite("output", &SPUC::fir<float,float>::output)
        .def_readwrite("Q", &SPUC::fir<float,float>::Q)
        .def_readwrite("num_taps", &SPUC::fir<float,float>::num_taps)
        .def("input", &SPUC::fir_decim<float,float>::input)
        .def("decim", &SPUC::fir_decim<float,float>::decim)
        .def("settap", (void (SPUC::fir<float,float>::*)(long int, float) )&SPUC::fir<float,float>::settap)
        .def("settaps", &SPUC::fir<float,float>::settaps)
        .def("number_of_taps", &SPUC::fir<float,float>::number_of_taps)
        .def("gettap", &SPUC::fir<float,float>::gettap)
        .def("reset", &SPUC::fir<float,float>::reset)
        .def("coeff_sum", &SPUC::fir<float,float>::coeff_sum)
        .def("out", &SPUC::fir<float,float>::out)
        .def("check", &SPUC::fir<float,float>::check)
        .def("set_round_bits", &SPUC::fir<float,float>::set_round_bits)
        .def("set_size", &SPUC::fir<float,float>::set_size)
        .def("get_size", &SPUC::fir<float,float>::get_size)
        .def("clock", &SPUC::fir<float,float>::clock)
        .def("update", &SPUC::fir<float,float>::update)
        .def("iir", &SPUC::fir<float,float>::iir)
        .def("read_taps", &SPUC::fir<float,float>::read_taps)
        .def("print", &SPUC::fir<float,float>::print)
        .def("settap", (void (SPUC::fir<float,float>::*)(SPUC::smart_array<float>) )&SPUC::fir<float,float>::settap)
    ;

}


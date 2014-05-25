
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_decim.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_decim_int)
{
    class_< SPUC::fir_decim<int,float> >("fir_decim_int", init<  >())
        .def(init< const SPUC::fir_decim<int,float>& >())
        .def(init< long int >())
        .def(init< const char* >())
        .def_readwrite("coeff", &SPUC::fir<int,float>::coeff)
        .def_readwrite("z", &SPUC::fir<int,float>::z)
        .def_readwrite("output", &SPUC::fir<int,float>::output)
        .def_readwrite("Q", &SPUC::fir<int,float>::Q)
        .def_readwrite("num_taps", &SPUC::fir<int,float>::num_taps)
        .def("input", &SPUC::fir_decim<int,float>::input)
        .def("decim", &SPUC::fir_decim<int,float>::decim)
        .def("settap", (void (SPUC::fir<int,float>::*)(long int, float) )&SPUC::fir<int,float>::settap)
        .def("settaps", &SPUC::fir<int,float>::settaps)
        .def("number_of_taps", &SPUC::fir<int,float>::number_of_taps)
        .def("gettap", &SPUC::fir<int,float>::gettap)
        .def("reset", &SPUC::fir<int,float>::reset)
        .def("coeff_sum", &SPUC::fir<int,float>::coeff_sum)
        .def("out", &SPUC::fir<int,float>::out)
        .def("check", &SPUC::fir<int,float>::check)
        .def("set_round_bits", &SPUC::fir<int,float>::set_round_bits)
        .def("set_size", &SPUC::fir<int,float>::set_size)
        .def("get_size", &SPUC::fir<int,float>::get_size)
        .def("clock", &SPUC::fir<int,float>::clock)
        .def("update", &SPUC::fir<int,float>::update)
        .def("iir", &SPUC::fir<int,float>::iir)
        .def("read_taps", &SPUC::fir<int,float>::read_taps)
        .def("print", &SPUC::fir<int,float>::print)
        .def("settap", (void (SPUC::fir<int,float>::*)(SPUC::smart_array<float>) )&SPUC::fir<int,float>::settap)
    ;

}


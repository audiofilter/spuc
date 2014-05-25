
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_adapt.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_adapt_int)
{
    class_< SPUC::fir_adapt<int,double> >("fir_adapt_int", init<  >())
        .def(init< const SPUC::fir_adapt<int,double>& >())
        .def(init< long int, int >())
        .def_readwrite("u", &SPUC::fir_adapt<int,double>::u)
        .def_readwrite("coeff", &SPUC::fir<int,double>::coeff)
        .def_readwrite("z", &SPUC::fir<int,double>::z)
        .def_readwrite("output", &SPUC::fir<int,double>::output)
        .def_readwrite("Q", &SPUC::fir<int,double>::Q)
        .def_readwrite("num_taps", &SPUC::fir<int,double>::num_taps)
        .def("reset", &SPUC::fir_adapt<int,double>::reset)
        .def("set_gain", &SPUC::fir_adapt<int,double>::set_gain)
        .def("update_lms", &SPUC::fir_adapt<int,double>::update_lms)
        .def("update_lms_sign_coeff", &SPUC::fir_adapt<int,double>::update_lms_sign_coeff)
        .def("settap", (void (SPUC::fir<int,double>::*)(long int, double) )&SPUC::fir<int,double>::settap)
        .def("settaps", &SPUC::fir<int,double>::settaps)
        .def("number_of_taps", &SPUC::fir<int,double>::number_of_taps)
        .def("gettap", &SPUC::fir<int,double>::gettap)
        .def("coeff_sum", &SPUC::fir<int,double>::coeff_sum)
        .def("out", &SPUC::fir<int,double>::out)
        .def("check", &SPUC::fir<int,double>::check)
        .def("set_round_bits", &SPUC::fir<int,double>::set_round_bits)
        .def("set_size", &SPUC::fir<int,double>::set_size)
        .def("get_size", &SPUC::fir<int,double>::get_size)
        .def("clock", &SPUC::fir<int,double>::clock)
        .def("update", &SPUC::fir<int,double>::update)
        .def("iir", &SPUC::fir<int,double>::iir)
        .def("read_taps", &SPUC::fir<int,double>::read_taps)
        .def("print", &SPUC::fir<int,double>::print)
        .def("settap", (void (SPUC::fir<int,double>::*)(SPUC::smart_array<double>) )&SPUC::fir<int,double>::settap)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_adapt.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_adapt_float)
{
    class_< SPUC::fir_adapt<float,double> >("fir_adapt_float", init<  >())
        .def(init< const SPUC::fir_adapt<float,double>& >())
        .def(init< long int, float >())
        .def_readwrite("u", &SPUC::fir_adapt<float,double>::u)
        .def_readwrite("coeff", &SPUC::fir<float,double>::coeff)
        .def_readwrite("z", &SPUC::fir<float,double>::z)
        .def_readwrite("output", &SPUC::fir<float,double>::output)
        .def_readwrite("Q", &SPUC::fir<float,double>::Q)
        .def_readwrite("num_taps", &SPUC::fir<float,double>::num_taps)
        .def("reset", &SPUC::fir_adapt<float,double>::reset)
        .def("set_gain", &SPUC::fir_adapt<float,double>::set_gain)
        .def("update_lms", &SPUC::fir_adapt<float,double>::update_lms)
        .def("update_lms_sign_coeff", &SPUC::fir_adapt<float,double>::update_lms_sign_coeff)
        .def("settap", (void (SPUC::fir<float,double>::*)(long int, double) )&SPUC::fir<float,double>::settap)
        .def("settaps", &SPUC::fir<float,double>::settaps)
        .def("number_of_taps", &SPUC::fir<float,double>::number_of_taps)
        .def("gettap", &SPUC::fir<float,double>::gettap)
        .def("coeff_sum", &SPUC::fir<float,double>::coeff_sum)
        .def("out", &SPUC::fir<float,double>::out)
        .def("check", &SPUC::fir<float,double>::check)
        .def("set_round_bits", &SPUC::fir<float,double>::set_round_bits)
        .def("set_size", &SPUC::fir<float,double>::set_size)
        .def("get_size", &SPUC::fir<float,double>::get_size)
        .def("clock", &SPUC::fir<float,double>::clock)
        .def("update", &SPUC::fir<float,double>::update)
        .def("iir", &SPUC::fir<float,double>::iir)
        .def("read_taps", &SPUC::fir<float,double>::read_taps)
        .def("print", &SPUC::fir<float,double>::print)
        .def("settap", (void (SPUC::fir<float,double>::*)(std::vector<double>) )&SPUC::fir<float,double>::settap)
    ;

}


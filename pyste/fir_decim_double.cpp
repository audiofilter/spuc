
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_decim.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_decim_double)
{
    class_< SPUC::fir_decim<double,double> >("fir_decim_double", init<  >())
        .def(init< const SPUC::fir_decim<double,double>& >())
        .def(init< long int >())
        .def(init< const char* >())
        .def_readwrite("coeff", &SPUC::fir<double,double>::coeff)
        .def_readwrite("z", &SPUC::fir<double,double>::z)
        .def_readwrite("output", &SPUC::fir<double,double>::output)
        .def_readwrite("Q", &SPUC::fir<double,double>::Q)
        .def_readwrite("num_taps", &SPUC::fir<double,double>::num_taps)
        .def("input", &SPUC::fir_decim<double,double>::input)
        .def("decim", &SPUC::fir_decim<double,double>::decim)
        .def("settap", (void (SPUC::fir<double,double>::*)(long int, SPUC::float_type) )&SPUC::fir<double,double>::settap)
        .def("settaps", &SPUC::fir<double,double>::settaps)
        .def("number_of_taps", &SPUC::fir<double,double>::number_of_taps)
        .def("gettap", &SPUC::fir<double,double>::gettap)
        .def("reset", &SPUC::fir<double,double>::reset)
        .def("coeff_sum", &SPUC::fir<double,double>::coeff_sum)
        .def("out", &SPUC::fir<double,double>::out)
        .def("check", &SPUC::fir<double,double>::check)
        .def("set_round_bits", &SPUC::fir<double,double>::set_round_bits)
        .def("set_size", &SPUC::fir<double,double>::set_size)
        .def("get_size", &SPUC::fir<double,double>::get_size)
        .def("clock", &SPUC::fir<double,double>::clock)
        .def("update", &SPUC::fir<double,double>::update)
        .def("iir", &SPUC::fir<double,double>::iir)
        .def("read_taps", &SPUC::fir<double,double>::read_taps)
        .def("print", &SPUC::fir<double,double>::print)
        .def("settap", (void (SPUC::fir<double,double>::*)(std::vector<double>) )&SPUC::fir<double,double>::settap)
    ;

}


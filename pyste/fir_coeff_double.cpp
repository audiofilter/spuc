
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_coeff.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_coeff_double)
{
    class_< SPUC::fir_coeff<double> >("fir_coeff_double", init<  >())
        .def(init< const SPUC::fir_coeff<double>& >())
        .def(init< long int >())
        .def(init< const char* >())
        .def_readwrite("coeff", &SPUC::fir_coeff<double>::coeff)
        .def_readwrite("num_taps", &SPUC::fir_coeff<double>::num_taps)
        .def("settap", (void (SPUC::fir_coeff<double>::*)(long int, double) )&SPUC::fir_coeff<double>::settap)
        .def("gettap", &SPUC::fir_coeff<double>::gettap)
        .def("coeff_sum", &SPUC::fir_coeff<double>::coeff_sum)
        .def("set_size", &SPUC::fir_coeff<double>::set_size)
        .def("get_size", &SPUC::fir_coeff<double>::get_size)
        .def("read_taps", &SPUC::fir_coeff<double>::read_taps)
        .def("quantize", &SPUC::fir_coeff<double>::quantize)
        .def("print", &SPUC::fir_coeff<double>::print)
        .def("settap", (void (SPUC::fir_coeff<double>::*)(std::vector<double>) )&SPUC::fir_coeff<double>::settap)
        .def("freqz_mag", &SPUC::fir_coeff<double>::freqz_mag)
    ;

}


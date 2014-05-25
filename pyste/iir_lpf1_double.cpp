
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_lpf1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_lpf1_double)
{
    class_< SPUC::iir_lpf1<double,double> >("iir_lpf1_double", init< const SPUC::iir_lpf1<double,double>& >())
        .def(init< optional< SPUC::float_type, long int > >())
        .def(init< const char* >())
        .def("set_coeff", &SPUC::iir_lpf1<double,double>::set_coeff)
        .def("set_round_bits", &SPUC::iir_lpf1<double,double>::set_round_bits)
        .def("print", &SPUC::iir_lpf1<double,double>::print)
        .def("clock", &SPUC::iir_lpf1<double,double>::clock)
        .def("reset", &SPUC::iir_lpf1<double,double>::reset)
    ;

}


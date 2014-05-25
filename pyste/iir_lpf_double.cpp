
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_lpf.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_lpf_double)
{
    class_< SPUC::iir_lpf<double,double> >("iir_lpf_double", init< const SPUC::iir_lpf<double,double>& >())
        .def(init< optional< SPUC::float_type, long int > >())
        .def("get_a0", &SPUC::iir_lpf<double,double>::get_a0)
        .def("get_b0", &SPUC::iir_lpf<double,double>::get_b0)
        .def("clock", &SPUC::iir_lpf<double,double>::clock)
        .def("set_coeff", &SPUC::iir_lpf1<double,double>::set_coeff)
        .def("set_round_bits", &SPUC::iir_lpf1<double,double>::set_round_bits)
        .def("print", &SPUC::iir_lpf1<double,double>::print)
        .def("reset", &SPUC::iir_lpf1<double,double>::reset)
    ;

}


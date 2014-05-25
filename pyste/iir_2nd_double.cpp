
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_2nd.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_2nd_double)
{
    class_< SPUC::iir_2nd<double,double> >("iir_2nd_double", init< const SPUC::iir_2nd<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type, SPUC::float_type, SPUC::float_type, SPUC::float_type, optional< long int > >())
        .def(init< optional< SPUC::float_type, SPUC::float_type > >())
        .def(init< const char* >())
        .def_readwrite("fb2", &SPUC::iir_2nd<double,double>::fb2)
        .def_readwrite("fb1", &SPUC::iir_2nd<double,double>::fb1)
        .def_readwrite("fb0", &SPUC::iir_2nd<double,double>::fb0)
        .def("set_round_bits", &SPUC::iir_2nd<double,double>::set_round_bits)
        .def("get_round_bits", &SPUC::iir_2nd<double,double>::get_round_bits)
        .def("get_b0", &SPUC::iir_2nd<double,double>::get_b0)
        .def("reset", &SPUC::iir_2nd<double,double>::reset)
        .def("set_a", &SPUC::iir_2nd<double,double>::set_a)
        .def("set_b", &SPUC::iir_2nd<double,double>::set_b)
        .def("set_coeffs", &SPUC::iir_2nd<double,double>::set_coeffs)
        .def("print", &SPUC::iir_2nd<double,double>::print)
        .def("clock", &SPUC::iir_2nd<double,double>::clock)
    ;

}


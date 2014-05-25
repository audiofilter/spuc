
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass_2nd.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_2nd_double)
{
    class_< SPUC::allpass_2nd<double,double> >("allpass_2nd_double", init<  >())
        .def(init< const SPUC::allpass_2nd<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type, optional< long int > >())
        .def(init< const char* >())
        .def_readwrite("fb2", &SPUC::allpass_2nd<double,double>::fb2)
        .def_readwrite("fb1", &SPUC::allpass_2nd<double,double>::fb1)
        .def_readwrite("fb0", &SPUC::allpass_2nd<double,double>::fb0)
        .def_readwrite("scale", &SPUC::allpass_2nd<double,double>::scale)
        .def_readwrite("Q", &SPUC::allpass_2nd<double,double>::Q)
        .def_readwrite("OQ", &SPUC::allpass_2nd<double,double>::OQ)
        .def("set_round_bits", &SPUC::allpass_2nd<double,double>::set_round_bits)
        .def("reset", &SPUC::allpass_2nd<double,double>::reset)
        .def("set_a", &SPUC::allpass_2nd<double,double>::set_a)
        .def("set_b", &SPUC::allpass_2nd<double,double>::set_b)
        .def("set_coeffs", &SPUC::allpass_2nd<double,double>::set_coeffs)
        .def("print", &SPUC::allpass_2nd<double,double>::print)
        .def("clock", &SPUC::allpass_2nd<double,double>::clock)
    ;

}


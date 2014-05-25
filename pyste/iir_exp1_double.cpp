
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_exp1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_exp1_double)
{
    class_< SPUC::iir_exp1<double,double> >("iir_exp1_double", init< const SPUC::iir_exp1<double,double>& >())
        .def(init< optional< SPUC::float_type, long int > >())
        .def(init< const char* >())
        .def("set_coeff", &SPUC::iir_exp1<double,double>::set_coeff)
        .def("set_round_bits", &SPUC::iir_exp1<double,double>::set_round_bits)
        .def("print", &SPUC::iir_exp1<double,double>::print)
        .def("clock", &SPUC::iir_exp1<double,double>::clock)
        .def("reset", &SPUC::iir_exp1<double,double>::reset)
    ;

}


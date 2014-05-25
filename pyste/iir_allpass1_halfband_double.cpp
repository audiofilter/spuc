
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1_halfband.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_halfband_double)
{
    class_< SPUC::iir_allpass1_halfband<double,double> >("iir_allpass1_halfband_double", init< const SPUC::iir_allpass1_halfband<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type, optional< long int > >())
        .def_readwrite("even", &SPUC::iir_allpass1_halfband<double,double>::even)
        .def("reset", &SPUC::iir_allpass1_halfband<double,double>::reset)
        .def("clock", &SPUC::iir_allpass1_halfband<double,double>::clock)
        .def("ready", &SPUC::iir_allpass1_halfband<double,double>::ready)
    ;

}


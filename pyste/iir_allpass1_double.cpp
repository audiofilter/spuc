
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_double)
{
    class_< SPUC::iir_allpass1<double,double> >("iir_allpass1_double", init< const SPUC::iir_allpass1<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type, optional< long int > >())
        .def(init< SPUC::float_type >())
        .def("reset", &SPUC::iir_allpass1<double,double>::reset)
        .def("clock", &SPUC::iir_allpass1<double,double>::clock)
    ;

}


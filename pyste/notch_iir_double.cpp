
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/notch_iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(notch_iir_double)
{
    class_< SPUC::notch_iir<double,double> >("notch_iir_double", init< const SPUC::notch_iir<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type >())
        .def_readwrite("filter", &SPUC::notch_iir<double,double>::filter)
        .def_readwrite("gain", &SPUC::notch_iir<double,double>::gain)
        .def("clock", &SPUC::notch_iir<double,double>::clock)
    ;

}


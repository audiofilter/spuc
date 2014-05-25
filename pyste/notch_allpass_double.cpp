
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/notch_allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(notch_allpass_double)
{
    class_< SPUC::notch_allpass<double,double> >("notch_allpass_double", init<  >())
        .def(init< const SPUC::notch_allpass<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type >())
        .def(init< SPUC::float_type >())
        .def_readwrite("ap", &SPUC::notch_allpass<double,double>::ap)
        .def("clock", &SPUC::notch_allpass<double,double>::clock)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vco.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vco_double)
{
    class_< SPUC::vco<double> >("vco_double", init< const SPUC::vco<double>& >())
        .def(init< optional< long int, long int > >())
        .def("reset", &SPUC::vco<double>::reset)
        .def("set_frequency", &SPUC::vco<double>::set_frequency)
        .def("reset_frequency", &SPUC::vco<double>::reset_frequency)
        .def("get_phase", &SPUC::vco<double>::get_phase)
        .def("load", &SPUC::vco<double>::load)
        .def("clock", (SPUC::complex<double> (SPUC::vco<double>::*)(double) )&SPUC::vco<double>::clock)
        .def("clock", (SPUC::complex<double> (SPUC::vco<double>::*)() )&SPUC::vco<double>::clock)
    ;

}


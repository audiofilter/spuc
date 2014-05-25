
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vco.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vco_float)
{
    class_< SPUC::vco<float> >("vco_float", init< const SPUC::vco<float>& >())
        .def(init< optional< long int, long int > >())
        .def("reset", &SPUC::vco<float>::reset)
        .def("set_frequency", &SPUC::vco<float>::set_frequency)
        .def("reset_frequency", &SPUC::vco<float>::reset_frequency)
        .def("get_phase", &SPUC::vco<float>::get_phase)
        .def("load", &SPUC::vco<float>::load)
        .def("clock", (SPUC::complex<float> (SPUC::vco<float>::*)(float) )&SPUC::vco<float>::clock)
        .def("clock", (SPUC::complex<float> (SPUC::vco<float>::*)() )&SPUC::vco<float>::clock)
    ;

}


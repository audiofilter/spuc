
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vco.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vco_int)
{
    class_< SPUC::vco<int> >("vco_int", init< const SPUC::vco<int>& >())
        .def(init< optional< long int, long int > >())
        .def("reset", &SPUC::vco<int>::reset)
        .def("set_frequency", &SPUC::vco<int>::set_frequency)
        .def("reset_frequency", &SPUC::vco<int>::reset_frequency)
        .def("get_phase", &SPUC::vco<int>::get_phase)
        .def("load", &SPUC::vco<int>::load)
        .def("clock", (SPUC::complex<int> (SPUC::vco<int>::*)(int) )&SPUC::vco<int>::clock)
        .def("clock", (SPUC::complex<int> (SPUC::vco<int>::*)() )&SPUC::vco<int>::clock)
    ;

}


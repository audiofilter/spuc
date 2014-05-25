
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/nco.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(nco)
{
    class_< SPUC::nco >("nco", init< const SPUC::nco& >())
        .def(init< optional< long int > >())
        .def_readwrite("phase", &SPUC::nco::phase)
        .def("reset", &SPUC::nco::reset)
        .def("set_frequency", &SPUC::nco::set_frequency)
        .def("reset_frequency", &SPUC::nco::reset_frequency)
        .def("get_phase", &SPUC::nco::get_phase)
        .def("load", &SPUC::nco::load)
        .def("clock", (long int (SPUC::nco::*)(long int) )&SPUC::nco::clock)
        .def("clock", (long int (SPUC::nco::*)() )&SPUC::nco::clock)
    ;

}


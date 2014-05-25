
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1_halfband.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_halfband_int)
{
    class_< SPUC::iir_allpass1_halfband<int,float> >("iir_allpass1_halfband_int", init< const SPUC::iir_allpass1_halfband<int,float>& >())
        .def(init< float, float, optional< long int > >())
        .def_readwrite("even", &SPUC::iir_allpass1_halfband<int,float>::even)
        .def("reset", &SPUC::iir_allpass1_halfband<int,float>::reset)
        .def("clock", &SPUC::iir_allpass1_halfband<int,float>::clock)
        .def("ready", &SPUC::iir_allpass1_halfband<int,float>::ready)
    ;

}


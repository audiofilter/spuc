
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1_halfband.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_halfband_float)
{
    class_< SPUC::iir_allpass1_halfband<float,float> >("iir_allpass1_halfband_float", init< const SPUC::iir_allpass1_halfband<float,float>& >())
        .def(init< float, float, optional< long int > >())
        .def_readwrite("even", &SPUC::iir_allpass1_halfband<float,float>::even)
        .def("reset", &SPUC::iir_allpass1_halfband<float,float>::reset)
        .def("clock", &SPUC::iir_allpass1_halfband<float,float>::clock)
        .def("ready", &SPUC::iir_allpass1_halfband<float,float>::ready)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass2.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass2_float)
{
    class_< SPUC::iir_allpass2<float,float> >("iir_allpass2_float", init< const SPUC::iir_allpass2<float,float>& >())
        .def(init< float, float, float, float, optional< long int > >())
        .def("reset", &SPUC::iir_allpass2<float,float>::reset)
        .def("clock", &SPUC::iir_allpass2<float,float>::clock)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_float)
{
    class_< SPUC::iir_allpass1<float,float> >("iir_allpass1_float", init< const SPUC::iir_allpass1<float,float>& >())
        .def(init< float, float, optional< long int > >())
        .def(init< float >())
        .def("reset", &SPUC::iir_allpass1<float,float>::reset)
        .def("clock", &SPUC::iir_allpass1<float,float>::clock)
    ;

}


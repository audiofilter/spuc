
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass2.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass2_int)
{
    class_< SPUC::iir_allpass2<int,float> >("iir_allpass2_int", init< const SPUC::iir_allpass2<int,float>& >())
        .def(init< float, float, float, float, optional< long int > >())
        .def("reset", &SPUC::iir_allpass2<int,float>::reset)
        .def("clock", &SPUC::iir_allpass2<int,float>::clock)
    ;

}


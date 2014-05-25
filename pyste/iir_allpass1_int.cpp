
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_int)
{
    class_< SPUC::iir_allpass1<int,float> >("iir_allpass1_int", init< const SPUC::iir_allpass1<int,float>& >())
        .def(init< float, float, optional< long int > >())
        .def(init< float >())
        .def("reset", &SPUC::iir_allpass1<int,float>::reset)
        .def("clock", &SPUC::iir_allpass1<int,float>::clock)
    ;

}


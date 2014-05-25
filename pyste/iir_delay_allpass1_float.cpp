
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_delay_allpass1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_delay_allpass1_float)
{
    class_< SPUC::iir_delay_allpass1<float,float> >("iir_delay_allpass1_float", init< const SPUC::iir_delay_allpass1<float,float>& >())
        .def(init< float, float, optional< long int, long int > >())
        .def("reset", &SPUC::iir_delay_allpass1<float,float>::reset)
        .def("clock", &SPUC::iir_delay_allpass1<float,float>::clock)
    ;

}


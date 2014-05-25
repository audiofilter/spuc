
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/notch_iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(notch_iir_float)
{
    class_< SPUC::notch_iir<float,float> >("notch_iir_float", init< const SPUC::notch_iir<float,float>& >())
        .def(init< float, float >())
        .def_readwrite("filter", &SPUC::notch_iir<float,float>::filter)
        .def_readwrite("gain", &SPUC::notch_iir<float,float>::gain)
        .def("clock", &SPUC::notch_iir<float,float>::clock)
    ;

}


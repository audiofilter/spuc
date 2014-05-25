
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/notch_iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(notch_iir_int)
{
    class_< SPUC::notch_iir<int,float> >("notch_iir_int", init< const SPUC::notch_iir<int,float>& >())
        .def(init< float, float >())
        .def_readwrite("filter", &SPUC::notch_iir<int,float>::filter)
        .def_readwrite("gain", &SPUC::notch_iir<int,float>::gain)
        .def("clock", &SPUC::notch_iir<int,float>::clock)
    ;

}


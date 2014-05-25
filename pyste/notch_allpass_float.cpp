
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/notch_allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(notch_allpass_float)
{
    class_< SPUC::notch_allpass<float,float> >("notch_allpass_float", init<  >())
        .def(init< const SPUC::notch_allpass<float,float>& >())
        .def(init< float, float >())
        .def(init< float >())
        .def_readwrite("ap", &SPUC::notch_allpass<float,float>::ap)
        .def("clock", &SPUC::notch_allpass<float,float>::clock)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/notch_allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(notch_allpass_int)
{
    class_< SPUC::notch_allpass<int,float> >("notch_allpass_int", init<  >())
        .def(init< const SPUC::notch_allpass<int,float>& >())
        .def(init< float, float >())
        .def(init< float >())
        .def_readwrite("ap", &SPUC::notch_allpass<int,float>::ap)
        .def("clock", &SPUC::notch_allpass<int,float>::clock)
    ;

}


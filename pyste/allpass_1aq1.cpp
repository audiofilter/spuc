
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass_1aq1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_1aq1)
{
    class_< SPUC::allpass_1aq1 >("allpass_1aq1", init<  >())
        .def(init< const SPUC::allpass_1aq1& >())
        .def("init", &SPUC::allpass_1aq1::init)
        .def("clock", &SPUC::allpass_1aq1::clock)
    ;

}


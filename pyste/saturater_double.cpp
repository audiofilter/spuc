
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/saturater.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(saturater_double)
{
    class_< SPUC::saturater<double> >("saturater_double", init<  >())
        .def(init< const SPUC::saturater<double>& >())
        .def("saturated", &SPUC::saturater<double>::saturated)
        .staticmethod("saturated")
    ;

}


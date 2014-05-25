
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/rounder.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(rounder_double)
{
    class_< SPUC::rounder<double> >("rounder_double", init<  >())
        .def(init< const SPUC::rounder<double>& >())
        .def("rounded", &SPUC::rounder<double>::rounded)
        .staticmethod("rounded")
    ;

}


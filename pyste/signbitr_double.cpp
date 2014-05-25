
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/signbitr.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(signbitr_double)
{
    class_< SPUC::signbitr<double> >("signbitr_double", init<  >())
        .def(init< const SPUC::signbitr<double>& >())
        .def("signbitd", &SPUC::signbitr<double>::signbitd)
        .staticmethod("signbitd")
    ;

}


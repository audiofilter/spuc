
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/conjr.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(conjr_double)
{
    class_< SPUC::conjr<double> >("conjr_double", init<  >())
        .def(init< const SPUC::conjr<double>& >())
        .def("conjd", &SPUC::conjr<double>::conjd)
        .staticmethod("conjd")
    ;

}


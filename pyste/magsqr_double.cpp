
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/magsqr.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(magsqr_double)
{
    class_< SPUC::magsqr<double> >("magsqr_double", init<  >())
        .def(init< const SPUC::magsqr<double>& >())
        .def("magsqd", &SPUC::magsqr<double>::magsqd)
        .staticmethod("magsqd")
    ;

}


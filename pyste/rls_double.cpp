
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/rls.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(rls_double)
{
    class_< SPUC::rls<double> >("rls_double", init< const SPUC::rls<double>& >())
        .def(init< const int, SPUC::float_type >())
        .def("update", &SPUC::rls<double>::update)
        .def("adapt", &SPUC::rls<double>::adapt)
    ;

}


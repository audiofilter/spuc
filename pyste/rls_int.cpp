
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/rls.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(rls_int)
{
    class_< SPUC::rls<int> >("rls_int", init< const SPUC::rls<int>& >())
        .def(init< const int, float >())
        .def("update", &SPUC::rls<int>::update)
        .def("adapt", &SPUC::rls<int>::adapt)
    ;

}


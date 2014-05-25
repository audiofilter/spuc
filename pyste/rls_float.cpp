
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/rls.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(rls_float)
{
    class_< SPUC::rls<float> >("rls_float", init< const SPUC::rls<float>& >())
        .def(init< const int, float >())
        .def("update", &SPUC::rls<float>::update)
        .def("adapt", &SPUC::rls<float>::adapt)
    ;

}


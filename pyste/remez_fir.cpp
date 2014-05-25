
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/remez_fir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(remez_fir)
{
    class_< SPUC::remez_fir >("remez_fir", init<  >())
        .def(init< const SPUC::remez_fir& >())
        .def("remez", &SPUC::remez_fir::remez)
        .staticmethod("remez")
    ;

}


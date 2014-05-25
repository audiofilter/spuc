
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/create_remez_lpfir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(create_remez_lpfir)
{
    def("create_remez_lpfir", &SPUC::create_remez_lpfir);
}


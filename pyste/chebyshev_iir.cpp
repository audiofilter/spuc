
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/chebyshev_iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(chebyshev_iir)
{
    def("chebyshev_s", &SPUC::chebyshev_s);
    def("chebyshev_iir", &SPUC::chebyshev_iir);
}


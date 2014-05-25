
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/elliptic_allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(elliptic_allpass)
{
    def("elliptic_allpass", &SPUC::elliptic_allpass);
}


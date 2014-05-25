
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/butterworth_allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(butterworth_allpass)
{
    def("butterworth_allpass", &SPUC::butterworth_allpass);
}


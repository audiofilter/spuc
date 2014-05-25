
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/butterworth_iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(butterworth_iir)
{
    def("butterworth_s", &SPUC::butterworth_s);
    def("butterworth_iir", &SPUC::butterworth_iir);
}


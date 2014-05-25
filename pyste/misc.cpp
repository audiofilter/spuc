
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/misc.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(misc)
{
    def("swap", &SPUC::swap);
    def("erf1", &SPUC::erf1);
    def("reduce", &SPUC::reduce);
    def("quicksort", &SPUC::quicksort);
    def("erfc1", &SPUC::erfc1);
}


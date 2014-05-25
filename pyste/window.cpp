
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/window.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(window)
{
    def("chebc", &SPUC::chebc);
    def("blackman", &SPUC::blackman);
    def("hanning", &SPUC::hanning);
    def("cheby", &SPUC::cheby);
    def("kaiser", &SPUC::kaiser);
    def("hamming", &SPUC::hamming);
    def("io", &SPUC::io);
}


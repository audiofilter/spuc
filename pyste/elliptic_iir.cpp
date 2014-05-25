
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/elliptic_iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(elliptic_iir)
{
    def("s_plane", &SPUC::s_plane);
    def("lamda_plane", &SPUC::lamda_plane);
    def("elliptic_iir", &SPUC::elliptic_iir);
    def("ellik", &SPUC::ellik);
    def("ellpk", &SPUC::ellpk);
    def("msqrt", &SPUC::msqrt);
    def("ellpj", &SPUC::ellpj);
}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cfft.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(cfft)
{
    class_< SPUC::cfft >("cfft", init< const SPUC::cfft& >())
        .def(init< int, optional< SPUC::float_type, SPUC::float_type, SPUC::float_type, SPUC::float_type > >())
        .def("fft", &SPUC::cfft::fft)
        .def("ifft", &SPUC::cfft::ifft)
        .def("length", &SPUC::cfft::length)
        .def("hermitian", &SPUC::cfft::hermitian)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_complex_float)
{
    class_< SPUC::vector<SPUC::complex<float> > >("vector_complex_float", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<SPUC::complex<float> >& >())
        .def("len", &SPUC::vector<SPUC::complex<float> >::len)
        .def("size", &SPUC::vector<SPUC::complex<float> >::size)
        .def("reset", &SPUC::vector<SPUC::complex<float> >::reset)
        .def("ones", &SPUC::vector<SPUC::complex<float> >::ones)
        .def("__call__", &SPUC::vector<SPUC::complex<float> >::operator ())
    ;

}


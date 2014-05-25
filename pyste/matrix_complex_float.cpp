
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_complex_float)
{
    class_< SPUC::matrix<SPUC::complex<float> > >("matrix_complex_float", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<SPUC::complex<float> >& >())
        .def("num_cols", &SPUC::matrix<SPUC::complex<float> >::num_cols)
        .def("num_rows", &SPUC::matrix<SPUC::complex<float> >::num_rows)
        .def("len", &SPUC::matrix<SPUC::complex<float> >::len)
        .def("reset", &SPUC::matrix<SPUC::complex<float> >::reset)
        .def("__call__", (SPUC::complex<float> (SPUC::matrix<SPUC::complex<float> >::*)(int, int) const)&SPUC::matrix<SPUC::complex<float> >::operator ())
        .def("__call__", (SPUC::complex<float> (SPUC::matrix<SPUC::complex<float> >::*)(int) const)&SPUC::matrix<SPUC::complex<float> >::operator ())
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_complex_int)
{
    class_< SPUC::matrix<SPUC::complex<int> > >("matrix_complex_int", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<SPUC::complex<int> >& >())
        .def("num_cols", &SPUC::matrix<SPUC::complex<int> >::num_cols)
        .def("num_rows", &SPUC::matrix<SPUC::complex<int> >::num_rows)
        .def("len", &SPUC::matrix<SPUC::complex<int> >::len)
        .def("reset", &SPUC::matrix<SPUC::complex<int> >::reset)
        .def("__call__", (SPUC::complex<int> (SPUC::matrix<SPUC::complex<int> >::*)(int, int) const)&SPUC::matrix<SPUC::complex<int> >::operator ())
        .def("__call__", (SPUC::complex<int> (SPUC::matrix<SPUC::complex<int> >::*)(int) const)&SPUC::matrix<SPUC::complex<int> >::operator ())
    ;

}


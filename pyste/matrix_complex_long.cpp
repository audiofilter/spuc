
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_complex_long)
{
    class_< SPUC::matrix<SPUC::complex<long int> > >("matrix_complex_long", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<SPUC::complex<long int> >& >())
        .def("num_cols", &SPUC::matrix<SPUC::complex<long int> >::num_cols)
        .def("num_rows", &SPUC::matrix<SPUC::complex<long int> >::num_rows)
        .def("len", &SPUC::matrix<SPUC::complex<long int> >::len)
        .def("reset", &SPUC::matrix<SPUC::complex<long int> >::reset)
        .def("__call__", (SPUC::complex<long int> (SPUC::matrix<SPUC::complex<long int> >::*)(int, int) const)&SPUC::matrix<SPUC::complex<long int> >::operator ())
        .def("__call__", (SPUC::complex<long int> (SPUC::matrix<SPUC::complex<long int> >::*)(int) const)&SPUC::matrix<SPUC::complex<long int> >::operator ())
    ;

}


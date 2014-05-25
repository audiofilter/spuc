
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_complex_double)
{
    class_< SPUC::matrix<SPUC::complex<double> > >("matrix_complex_double", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<SPUC::complex<double> >& >())
        .def("num_cols", &SPUC::matrix<SPUC::complex<double> >::num_cols)
        .def("num_rows", &SPUC::matrix<SPUC::complex<double> >::num_rows)
        .def("len", &SPUC::matrix<SPUC::complex<double> >::len)
        .def("reset", &SPUC::matrix<SPUC::complex<double> >::reset)
        .def("__call__", (SPUC::complex<double> (SPUC::matrix<SPUC::complex<double> >::*)(int, int) const)&SPUC::matrix<SPUC::complex<double> >::operator ())
        .def("__call__", (SPUC::complex<double> (SPUC::matrix<SPUC::complex<double> >::*)(int) const)&SPUC::matrix<SPUC::complex<double> >::operator ())
    ;

}


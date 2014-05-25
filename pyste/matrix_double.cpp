
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_double)
{
    class_< SPUC::matrix<double> >("matrix_double", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<double>& >())
        .def("num_cols", &SPUC::matrix<double>::num_cols)
        .def("num_rows", &SPUC::matrix<double>::num_rows)
        .def("len", &SPUC::matrix<double>::len)
        .def("reset", &SPUC::matrix<double>::reset)
        .def("__call__", (double (SPUC::matrix<double>::*)(int, int) const)&SPUC::matrix<double>::operator ())
        .def("__call__", (double (SPUC::matrix<double>::*)(int) const)&SPUC::matrix<double>::operator ())
    ;

}


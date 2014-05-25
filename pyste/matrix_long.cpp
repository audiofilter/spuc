
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_long)
{
    class_< SPUC::matrix<long int> >("matrix_long", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<long int>& >())
        .def("num_cols", &SPUC::matrix<long int>::num_cols)
        .def("num_rows", &SPUC::matrix<long int>::num_rows)
        .def("len", &SPUC::matrix<long int>::len)
        .def("reset", &SPUC::matrix<long int>::reset)
        .def("__call__", (long int (SPUC::matrix<long int>::*)(int, int) const)&SPUC::matrix<long int>::operator ())
        .def("__call__", (long int (SPUC::matrix<long int>::*)(int) const)&SPUC::matrix<long int>::operator ())
    ;

}


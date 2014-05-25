
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_int)
{
    class_< SPUC::matrix<int> >("matrix_int", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<int>& >())
        .def("num_cols", &SPUC::matrix<int>::num_cols)
        .def("num_rows", &SPUC::matrix<int>::num_rows)
        .def("len", &SPUC::matrix<int>::len)
        .def("reset", &SPUC::matrix<int>::reset)
        .def("__call__", (int (SPUC::matrix<int>::*)(int, int) const)&SPUC::matrix<int>::operator ())
        .def("__call__", (int (SPUC::matrix<int>::*)(int) const)&SPUC::matrix<int>::operator ())
    ;

}


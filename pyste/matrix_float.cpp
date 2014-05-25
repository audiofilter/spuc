
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/matrix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(matrix_float)
{
    class_< SPUC::matrix<float> >("matrix_float", init<  >())
        .def(init< int, int >())
        .def(init< const SPUC::matrix<float>& >())
        .def("num_cols", &SPUC::matrix<float>::num_cols)
        .def("num_rows", &SPUC::matrix<float>::num_rows)
        .def("len", &SPUC::matrix<float>::len)
        .def("reset", &SPUC::matrix<float>::reset)
        .def("__call__", (float (SPUC::matrix<float>::*)(int, int) const)&SPUC::matrix<float>::operator ())
        .def("__call__", (float (SPUC::matrix<float>::*)(int) const)&SPUC::matrix<float>::operator ())
    ;

}


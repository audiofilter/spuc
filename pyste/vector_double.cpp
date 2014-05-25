
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_double)
{
    class_< SPUC::vector<double> >("vector_double", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<double>& >())
        .def("len", &SPUC::vector<double>::len)
        .def("size", &SPUC::vector<double>::size)
        .def("reset", &SPUC::vector<double>::reset)
        .def("ones", &SPUC::vector<double>::ones)
        .def("__call__", &SPUC::vector<double>::operator ())
    ;

}


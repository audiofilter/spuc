
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_int)
{
    class_< SPUC::vector<int> >("vector_int", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<int>& >())
        .def("len", &SPUC::vector<int>::len)
        .def("size", &SPUC::vector<int>::size)
        .def("reset", &SPUC::vector<int>::reset)
        .def("ones", &SPUC::vector<int>::ones)
        .def("__call__", &SPUC::vector<int>::operator ())
    ;

}


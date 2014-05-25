
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_long)
{
    class_< SPUC::vector<long int> >("vector_long", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<long int>& >())
        .def("len", &SPUC::vector<long int>::len)
        .def("size", &SPUC::vector<long int>::size)
        .def("reset", &SPUC::vector<long int>::reset)
        .def("ones", &SPUC::vector<long int>::ones)
        .def("__call__", &SPUC::vector<long int>::operator ())
    ;

}


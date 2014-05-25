
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_float)
{
    class_< SPUC::vector<float> >("vector_float", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<float>& >())
        .def("len", &SPUC::vector<float>::len)
        .def("size", &SPUC::vector<float>::size)
        .def("reset", &SPUC::vector<float>::reset)
        .def("ones", &SPUC::vector<float>::ones)
        .def("__call__", &SPUC::vector<float>::operator ())
    ;

}


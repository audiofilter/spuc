
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/circ_buffer.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(circ_buffer_int)
{
    class_< SPUC::circ_buffer<int> >("circ_buffer_int", init<  >())
        .def(init< const SPUC::circ_buffer<int>& >())
        .def(init< int >())
        .def(init< int, int >())
        .def("size", &SPUC::circ_buffer<int>::size)
        .def("put", &SPUC::circ_buffer<int>::put)
    ;

}


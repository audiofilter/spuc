
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/circ_buffer.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(circ_buffer_float)
{
    class_< SPUC::circ_buffer<float> >("circ_buffer_float", init<  >())
        .def(init< const SPUC::circ_buffer<float>& >())
        .def(init< int >())
        .def(init< int, float >())
        .def("size", &SPUC::circ_buffer<float>::size)
        .def("put", &SPUC::circ_buffer<float>::put)
    ;

}


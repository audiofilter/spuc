
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/circ_buffer.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(circ_buffer_double)
{
    class_< SPUC::circ_buffer<double> >("circ_buffer_double", init<  >())
        .def(init< const SPUC::circ_buffer<double>& >())
        .def(init< int >())
        .def(init< int, double >())
        .def("size", &SPUC::circ_buffer<double>::size)
        .def("put", &SPUC::circ_buffer<double>::put)
    ;

}


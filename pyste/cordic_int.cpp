
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cordic.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(cordic_int)
{
    class_< SPUC::cordic<int> >("cordic_int", init< const SPUC::cordic<int>& >())
        .def(init< optional< int > >())
        .def_readwrite("arctan_lut", &SPUC::cordic<int>::arctan_lut)
        .def_readwrite("stage", &SPUC::cordic<int>::stage)
        .def_readwrite("stages", &SPUC::cordic<int>::stages)
        .def_readwrite("vector_angle", &SPUC::cordic<int>::vector_angle)
        .def("vector_mag", &SPUC::cordic<int>::vector_mag)
        .def("vector_arg", &SPUC::cordic<int>::vector_arg)
        .def("rotate", &SPUC::cordic<int>::rotate)
    ;

}


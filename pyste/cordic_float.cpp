
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cordic.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(cordic_float)
{
    class_< SPUC::cordic<float> >("cordic_float", init< const SPUC::cordic<float>& >())
        .def(init< optional< int > >())
        .def_readwrite("arctan_lut", &SPUC::cordic<float>::arctan_lut)
        .def_readwrite("stage", &SPUC::cordic<float>::stage)
        .def_readwrite("stages", &SPUC::cordic<float>::stages)
        .def_readwrite("vector_angle", &SPUC::cordic<float>::vector_angle)
        .def("vector_mag", &SPUC::cordic<float>::vector_mag)
        .def("vector_arg", &SPUC::cordic<float>::vector_arg)
        .def("rotate", &SPUC::cordic<float>::rotate)
    ;

}


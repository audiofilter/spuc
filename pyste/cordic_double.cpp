
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cordic.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(cordic_double)
{
    class_< SPUC::cordic<double> >("cordic_double", init< const SPUC::cordic<double>& >())
        .def(init< optional< int > >())
        .def_readwrite("arctan_lut", &SPUC::cordic<double>::arctan_lut)
        .def_readwrite("stage", &SPUC::cordic<double>::stage)
        .def_readwrite("stages", &SPUC::cordic<double>::stages)
        .def_readwrite("vector_angle", &SPUC::cordic<double>::vector_angle)
        .def("vector_mag", &SPUC::cordic<double>::vector_mag)
        .def("vector_arg", &SPUC::cordic<double>::vector_arg)
        .def("rotate", &SPUC::cordic<double>::rotate)
    ;

}


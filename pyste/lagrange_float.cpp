
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/lagrange.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(lagrange_float)
{
    class_< SPUC::lagrange<float,float> >("lagrange_float", init<  >())
        .def(init< const SPUC::lagrange<float,float>& >())
        .def(init< long int, optional< long int > >())
        .def_readwrite("num_taps", &SPUC::lagrange<float,float>::num_taps)
        .def_readwrite("coeff", &SPUC::lagrange<float,float>::coeff)
        .def("reset", &SPUC::lagrange<float,float>::reset)
        .def("out", &SPUC::lagrange<float,float>::out)
        .def("check", &SPUC::lagrange<float,float>::check)
        .def("set_size", &SPUC::lagrange<float,float>::set_size)
        .def("input", &SPUC::lagrange<float,float>::input)
        .def("update", &SPUC::lagrange<float,float>::update)
        .def("fir", &SPUC::lagrange<float,float>::fir)
        .def("rephase", &SPUC::lagrange<float,float>::rephase)
        .def("calculate_coeff", &SPUC::lagrange<float,float>::calculate_coeff)
        .def("print", &SPUC::lagrange<float,float>::print)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/lagrange.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(lagrange_int)
{
    class_< SPUC::lagrange<int,float> >("lagrange_int", init<  >())
        .def(init< const SPUC::lagrange<int,float>& >())
        .def(init< long int, optional< long int > >())
        .def_readwrite("num_taps", &SPUC::lagrange<int,float>::num_taps)
        .def_readwrite("coeff", &SPUC::lagrange<int,float>::coeff)
        .def("reset", &SPUC::lagrange<int,float>::reset)
        .def("out", &SPUC::lagrange<int,float>::out)
        .def("check", &SPUC::lagrange<int,float>::check)
        .def("set_size", &SPUC::lagrange<int,float>::set_size)
        .def("input", &SPUC::lagrange<int,float>::input)
        .def("update", &SPUC::lagrange<int,float>::update)
        .def("fir", &SPUC::lagrange<int,float>::fir)
        .def("rephase", &SPUC::lagrange<int,float>::rephase)
        .def("calculate_coeff", &SPUC::lagrange<int,float>::calculate_coeff)
        .def("print", &SPUC::lagrange<int,float>::print)
    ;

}


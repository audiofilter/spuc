
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/lagrange.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(lagrange_double)
{
    class_< SPUC::lagrange<double,double> >("lagrange_double", init<  >())
        .def(init< const SPUC::lagrange<double,double>& >())
        .def(init< long int, optional< long int > >())
        .def_readwrite("num_taps", &SPUC::lagrange<double,double>::num_taps)
        .def_readwrite("coeff", &SPUC::lagrange<double,double>::coeff)
        .def("reset", &SPUC::lagrange<double,double>::reset)
        .def("out", &SPUC::lagrange<double,double>::out)
        .def("check", &SPUC::lagrange<double,double>::check)
        .def("set_size", &SPUC::lagrange<double,double>::set_size)
        .def("input", &SPUC::lagrange<double,double>::input)
        .def("update", &SPUC::lagrange<double,double>::update)
        .def("fir", &SPUC::lagrange<double,double>::fir)
        .def("rephase", &SPUC::lagrange<double,double>::rephase)
        .def("calculate_coeff", &SPUC::lagrange<double,double>::calculate_coeff)
        .def("print", &SPUC::lagrange<double,double>::print)
    ;

}


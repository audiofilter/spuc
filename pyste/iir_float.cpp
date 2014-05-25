
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_float)
{
    class_< SPUC::iir<float,double> >("iir_float", init< const SPUC::iir<float,double>& >())
        .def(init< SPUC::iir_coeff& >())
        .def(init< optional< long int > >())
        .def_readwrite("order", &SPUC::iir<float,double>::order)
        .def_readwrite("odd", &SPUC::iir<float,double>::odd)
        .def_readwrite("n2", &SPUC::iir<float,double>::n2)
        .def_readwrite("sos", &SPUC::iir<float,double>::sos)
        .def_readwrite("fos", &SPUC::iir<float,double>::fos)
        .def_readwrite("gain", &SPUC::iir<float,double>::gain)
        .def_readwrite("Q", &SPUC::iir<float,double>::Q)
        .def("stages", &SPUC::iir<float,double>::stages)
        .def("reset", &SPUC::iir<float,double>::reset)
        .def("set_coeffs", &SPUC::iir<float,double>::set_coeffs)
        .def("set_round_bits", &SPUC::iir<float,double>::set_round_bits)
        .def("print", &SPUC::iir<float,double>::print)
        .def("clock", &SPUC::iir<float,double>::clock)
    ;

}


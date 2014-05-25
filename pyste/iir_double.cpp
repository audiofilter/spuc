
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_double)
{
    class_< SPUC::iir<double,double> >("iir_double", init< const SPUC::iir<double,double>& >())
        .def(init< SPUC::iir_coeff& >())
        .def(init< optional< long int > >())
        .def_readwrite("order", &SPUC::iir<double,double>::order)
        .def_readwrite("odd", &SPUC::iir<double,double>::odd)
        .def_readwrite("n2", &SPUC::iir<double,double>::n2)
        .def_readwrite("sos", &SPUC::iir<double,double>::sos)
        .def_readwrite("fos", &SPUC::iir<double,double>::fos)
        .def_readwrite("gain", &SPUC::iir<double,double>::gain)
        .def_readwrite("Q", &SPUC::iir<double,double>::Q)
        .def("stages", &SPUC::iir<double,double>::stages)
        .def("reset", &SPUC::iir<double,double>::reset)
        .def("set_coeffs", &SPUC::iir<double,double>::set_coeffs)
        .def("set_round_bits", &SPUC::iir<double,double>::set_round_bits)
        .def("print", &SPUC::iir<double,double>::print)
        .def("clock", &SPUC::iir<double,double>::clock)
    ;

}


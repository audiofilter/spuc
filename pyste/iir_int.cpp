
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_int)
{
    class_< SPUC::iir<int,double> >("iir_int", init< const SPUC::iir<int,double>& >())
        .def(init< SPUC::iir_coeff& >())
        .def(init< optional< long int > >())
        .def_readwrite("order", &SPUC::iir<int,double>::order)
        .def_readwrite("odd", &SPUC::iir<int,double>::odd)
        .def_readwrite("n2", &SPUC::iir<int,double>::n2)
        .def_readwrite("sos", &SPUC::iir<int,double>::sos)
        .def_readwrite("fos", &SPUC::iir<int,double>::fos)
        .def_readwrite("gain", &SPUC::iir<int,double>::gain)
        .def_readwrite("Q", &SPUC::iir<int,double>::Q)
        .def("stages", &SPUC::iir<int,double>::stages)
        .def("reset", &SPUC::iir<int,double>::reset)
        .def("set_coeffs", &SPUC::iir<int,double>::set_coeffs)
        .def("set_round_bits", &SPUC::iir<int,double>::set_round_bits)
        .def("print", &SPUC::iir<int,double>::print)
        .def("clock", &SPUC::iir<int,double>::clock)
    ;

}


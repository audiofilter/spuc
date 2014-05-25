
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_hpf.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_hpf_double)
{
    class_< SPUC::iir_hpf<double,double> >("iir_hpf_double", init< const SPUC::iir_hpf<double,double>& >())
        .def(init< optional< SPUC::float_type, long int > >())
        .def("set_coeff", &SPUC::iir_hpf<double,double>::set_coeff)
        .def("get_a0", &SPUC::iir_hpf<double,double>::get_a0)
        .def("get_b0", &SPUC::iir_hpf<double,double>::get_b0)
        .def("print", &SPUC::iir_hpf<double,double>::print)
        .def("clock", &SPUC::iir_hpf<double,double>::clock)
        .def("reset", &SPUC::iir_hpf<double,double>::reset)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_hpf.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_hpf_float)
{
    class_< SPUC::iir_hpf<float,float> >("iir_hpf_float", init< const SPUC::iir_hpf<float,float>& >())
        .def(init< optional< float, long int > >())
        .def("set_coeff", &SPUC::iir_hpf<float,float>::set_coeff)
        .def("get_a0", &SPUC::iir_hpf<float,float>::get_a0)
        .def("get_b0", &SPUC::iir_hpf<float,float>::get_b0)
        .def("print", &SPUC::iir_hpf<float,float>::print)
        .def("clock", &SPUC::iir_hpf<float,float>::clock)
        .def("reset", &SPUC::iir_hpf<float,float>::reset)
    ;

}


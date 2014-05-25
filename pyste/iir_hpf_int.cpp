
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_hpf.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_hpf_int)
{
    class_< SPUC::iir_hpf<int,float> >("iir_hpf_int", init< const SPUC::iir_hpf<int,float>& >())
        .def(init< optional< float, long int > >())
        .def("set_coeff", &SPUC::iir_hpf<int,float>::set_coeff)
        .def("get_a0", &SPUC::iir_hpf<int,float>::get_a0)
        .def("get_b0", &SPUC::iir_hpf<int,float>::get_b0)
        .def("print", &SPUC::iir_hpf<int,float>::print)
        .def("clock", &SPUC::iir_hpf<int,float>::clock)
        .def("reset", &SPUC::iir_hpf<int,float>::reset)
    ;

}


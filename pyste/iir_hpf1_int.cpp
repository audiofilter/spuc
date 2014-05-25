
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_hpf1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_hpf1_int)
{
    class_< SPUC::iir_hpf1<int,float> >("iir_hpf1_int", init< const SPUC::iir_hpf1<int,float>& >())
        .def(init< optional< float, long int > >())
        .def(init< const char* >())
        .def("set_coeff", &SPUC::iir_hpf1<int,float>::set_coeff)
        .def("print", &SPUC::iir_hpf1<int,float>::print)
        .def("clock", &SPUC::iir_hpf1<int,float>::clock)
        .def("reset", &SPUC::iir_hpf1<int,float>::reset)
    ;

}


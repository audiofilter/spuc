
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1_cascade.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_cascade_int)
{
    class_< SPUC::iir_allpass1_cascade<int,float> >("iir_allpass1_cascade_int", init< const SPUC::iir_allpass1_cascade<int,float>& >())
        .def(init< float, optional< int, int > >())
        .def_readwrite("stages", &SPUC::iir_allpass1_cascade<int,float>::stages)
        .def_readwrite("A0", &SPUC::iir_allpass1_cascade<int,float>::A0)
        .def_readwrite("A1", &SPUC::iir_allpass1_cascade<int,float>::A1)
        .def_readwrite("prev_input", &SPUC::iir_allpass1_cascade<int,float>::prev_input)
        .def("get_a0", &SPUC::iir_allpass1_cascade<int,float>::get_a0)
        .def("get_a1", &SPUC::iir_allpass1_cascade<int,float>::get_a1)
        .def("reset", &SPUC::iir_allpass1_cascade<int,float>::reset)
        .def("clock", &SPUC::iir_allpass1_cascade<int,float>::clock)
    ;

}


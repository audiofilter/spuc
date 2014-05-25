
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_allpass1_cascade.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_allpass1_cascade_double)
{
    class_< SPUC::iir_allpass1_cascade<double,double> >("iir_allpass1_cascade_double", init< const SPUC::iir_allpass1_cascade<double,double>& >())
        .def(init< SPUC::float_type, optional< int, int > >())
        .def_readwrite("stages", &SPUC::iir_allpass1_cascade<double,double>::stages)
        .def_readwrite("A0", &SPUC::iir_allpass1_cascade<double,double>::A0)
        .def_readwrite("A1", &SPUC::iir_allpass1_cascade<double,double>::A1)
        .def_readwrite("prev_input", &SPUC::iir_allpass1_cascade<double,double>::prev_input)
        .def("get_a0", &SPUC::iir_allpass1_cascade<double,double>::get_a0)
        .def("get_a1", &SPUC::iir_allpass1_cascade<double,double>::get_a1)
        .def("reset", &SPUC::iir_allpass1_cascade<double,double>::reset)
        .def("clock", &SPUC::iir_allpass1_cascade<double,double>::clock)
    ;

}


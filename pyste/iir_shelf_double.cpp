
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_shelf.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_shelf_double)
{
    class_< SPUC::iir_shelf<double,double> >("iir_shelf_double", init< const SPUC::iir_shelf<double,double>& >())
        .def(init< SPUC::float_type, SPUC::float_type, SPUC::float_type, optional< long int > >())
        .def(init< SPUC::float_type, SPUC::float_type >())
        .def("get_a0", &SPUC::iir_shelf<double,double>::get_a0)
        .def("get_a1", &SPUC::iir_shelf<double,double>::get_a1)
        .def("get_b", &SPUC::iir_shelf<double,double>::get_b)
        .def("clock", &SPUC::iir_shelf<double,double>::clock)
        .def("set_round_bits", &SPUC::iir_shelf<double,double>::set_round_bits)
        .def("get_round_bits", &SPUC::iir_shelf<double,double>::get_round_bits)
        .def("reset", &SPUC::iir_shelf<double,double>::reset)
    ;

}


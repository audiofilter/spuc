
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_1st.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_1st_double)
{
    class_< SPUC::iir_1st<double,double> >("iir_1st_double", init< const SPUC::iir_1st<double,double>& >())
        .def(init< optional< SPUC::float_type, SPUC::float_type, long int > >())
        .def("set_coeffs", &SPUC::iir_1st<double,double>::set_coeffs)
        .def("set_round_bits", &SPUC::iir_1st<double,double>::set_round_bits)
        .def("print", &SPUC::iir_1st<double,double>::print)
        .def("clock", &SPUC::iir_1st<double,double>::clock)
        .def("reset", &SPUC::iir_1st<double,double>::reset)
    ;

}


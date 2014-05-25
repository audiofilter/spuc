
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_1st.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_1st_float)
{
    class_< SPUC::iir_1st<float,float> >("iir_1st_float", init< const SPUC::iir_1st<float,float>& >())
        .def(init< optional< float, float, long int > >())
        .def("set_coeffs", &SPUC::iir_1st<float,float>::set_coeffs)
        .def("set_round_bits", &SPUC::iir_1st<float,float>::set_round_bits)
        .def("print", &SPUC::iir_1st<float,float>::print)
        .def("clock", &SPUC::iir_1st<float,float>::clock)
        .def("reset", &SPUC::iir_1st<float,float>::reset)
    ;

}


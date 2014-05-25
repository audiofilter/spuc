
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_coeff.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_coeff)
{
    class_< SPUC::iir_coeff >("iir_coeff", init< const SPUC::iir_coeff& >())
        .def(init< optional< long int > >())
        .def_readwrite("order", &SPUC::iir_coeff::order)
        .def_readwrite("odd", &SPUC::iir_coeff::odd)
        .def_readwrite("n2", &SPUC::iir_coeff::n2)
        .def_readwrite("poles", &SPUC::iir_coeff::poles)
        .def_readwrite("zeros", &SPUC::iir_coeff::zeros)
        .def_readwrite("a_tf", &SPUC::iir_coeff::a_tf)
        .def_readwrite("b_tf", &SPUC::iir_coeff::b_tf)
        .def_readwrite("gain", &SPUC::iir_coeff::gain)
        .def_readwrite("state", &SPUC::iir_coeff::state)
        .def_readwrite("tf_state", &SPUC::iir_coeff::tf_state)
        .def_readwrite("ap_state", &SPUC::iir_coeff::ap_state)
        .def("bilinear", &SPUC::iir_coeff::bilinear)
        .def("convert_to_ab", &SPUC::iir_coeff::convert_to_ab)
        .def("z_root_to_ab", &SPUC::iir_coeff::z_root_to_ab)
        .def("pz_to_ap", &SPUC::iir_coeff::pz_to_ap)
        .def("ab_to_tf", &SPUC::iir_coeff::ab_to_tf)
        .def("p2_to_poly", &SPUC::iir_coeff::p2_to_poly)
        .def("pz_to_poly", &SPUC::iir_coeff::pz_to_poly)
        .def("get_root", &SPUC::iir_coeff::get_root)
        .def("get_zero", &SPUC::iir_coeff::get_zero)
        .def("get_a", &SPUC::iir_coeff::get_a)
        .def("get_b", &SPUC::iir_coeff::get_b)
        .def("get_coeff_a", &SPUC::iir_coeff::get_coeff_a)
        .def("get_coeff_b", &SPUC::iir_coeff::get_coeff_b)
        .def("max_abs_coeff", &SPUC::iir_coeff::max_abs_coeff)
        .def("quantize", &SPUC::iir_coeff::quantize)
        .def("freqz_mag", &SPUC::iir_coeff::freqz_mag)
    ;

}


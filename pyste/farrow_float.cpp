
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/farrow.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(farrow_float)
{
    class_< SPUC::farrow<float> >("farrow_float", init< const SPUC::farrow<float>& >())
        .def(init< char >())
        .def_readwrite("num_taps", &SPUC::farrow<float>::num_taps)
        .def_readwrite("coeff", &SPUC::farrow<float>::coeff)
        .def("out", &SPUC::farrow<float>::out)
        .def("check", &SPUC::farrow<float>::check)
        .def("reset", &SPUC::farrow<float>::reset)
        .def("input", &SPUC::farrow<float>::input)
        .def("update", &SPUC::farrow<float>::update)
        .def("fir", &SPUC::farrow<float>::fir)
        .def("rephase", &SPUC::farrow<float>::rephase)
        .def("calculate_coeff2", &SPUC::farrow<float>::calculate_coeff2)
        .def("calculate_coeff3", &SPUC::farrow<float>::calculate_coeff3)
        .def("calculate_coeff3a", &SPUC::farrow<float>::calculate_coeff3a)
        .def("calculate_coeff4", &SPUC::farrow<float>::calculate_coeff4)
    ;

}


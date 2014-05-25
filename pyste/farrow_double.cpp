
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/farrow.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(farrow_double)
{
    class_< SPUC::farrow<double> >("farrow_double", init< const SPUC::farrow<double>& >())
        .def(init< char >())
        .def_readwrite("num_taps", &SPUC::farrow<double>::num_taps)
        .def_readwrite("coeff", &SPUC::farrow<double>::coeff)
        .def("out", &SPUC::farrow<double>::out)
        .def("check", &SPUC::farrow<double>::check)
        .def("reset", &SPUC::farrow<double>::reset)
        .def("input", &SPUC::farrow<double>::input)
        .def("update", &SPUC::farrow<double>::update)
        .def("fir", &SPUC::farrow<double>::fir)
        .def("rephase", &SPUC::farrow<double>::rephase)
        .def("calculate_coeff2", &SPUC::farrow<double>::calculate_coeff2)
        .def("calculate_coeff3", &SPUC::farrow<double>::calculate_coeff3)
        .def("calculate_coeff3a", &SPUC::farrow<double>::calculate_coeff3a)
        .def("calculate_coeff4", &SPUC::farrow<double>::calculate_coeff4)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/farrow.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(farrow_int)
{
    class_< SPUC::farrow<int> >("farrow_int", init< const SPUC::farrow<int>& >())
        .def(init< char >())
        .def_readwrite("num_taps", &SPUC::farrow<int>::num_taps)
        .def_readwrite("coeff", &SPUC::farrow<int>::coeff)
        .def("out", &SPUC::farrow<int>::out)
        .def("check", &SPUC::farrow<int>::check)
        .def("reset", &SPUC::farrow<int>::reset)
        .def("input", &SPUC::farrow<int>::input)
        .def("update", &SPUC::farrow<int>::update)
        .def("fir", &SPUC::farrow<int>::fir)
        .def("rephase", &SPUC::farrow<int>::rephase)
        .def("calculate_coeff2", &SPUC::farrow<int>::calculate_coeff2)
        .def("calculate_coeff3", &SPUC::farrow<int>::calculate_coeff3)
        .def("calculate_coeff3a", &SPUC::farrow<int>::calculate_coeff3a)
        .def("calculate_coeff4", &SPUC::farrow<int>::calculate_coeff4)
    ;

}


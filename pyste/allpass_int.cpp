
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_int)
{
    class_< SPUC::allpass<int,float> >("allpass_int", init< const SPUC::allpass<int,float>& >())
        .def(init< SPUC::smart_array<float>, int >())
        .def(init< optional< long int > >())
        .def_readwrite("stages", &SPUC::allpass<int,float>::stages)
        .def_readwrite("ap", &SPUC::allpass<int,float>::ap)
        .def("get_coefficient", &SPUC::allpass<int,float>::get_coefficient)
        .def("init", &SPUC::allpass<int,float>::init)
        .def("reset", &SPUC::allpass<int,float>::reset)
        .def("set_coeffs", &SPUC::allpass<int,float>::set_coeffs)
        .def("clock", &SPUC::allpass<int,float>::clock)
    ;

}


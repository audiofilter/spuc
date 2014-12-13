
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_float)
{
    class_< SPUC::allpass<float,float> >("allpass_float", init< const SPUC::allpass<float,float>& >())
        .def(init< std::vector<float>, int >())
        .def(init< optional< long int > >())
        .def_readwrite("stages", &SPUC::allpass<float,float>::stages)
        .def_readwrite("ap", &SPUC::allpass<float,float>::ap)
        .def("get_coefficient", &SPUC::allpass<float,float>::get_coefficient)
        .def("init", &SPUC::allpass<float,float>::init)
        .def("reset", &SPUC::allpass<float,float>::reset)
        .def("set_coeffs", &SPUC::allpass<float,float>::set_coeffs)
        .def("clock", &SPUC::allpass<float,float>::clock)
    ;

}


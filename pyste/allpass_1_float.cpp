
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass_1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_1_float)
{
    class_< SPUC::allpass_1<float,float> >("allpass_1_float", init< const SPUC::allpass_1<float,float>& >())
        .def(init< optional< float, long int, long int > >())
        .def("get_coefficient", &SPUC::allpass_1<float,float>::get_coefficient)
        .def("reset", &SPUC::allpass_1<float,float>::reset)
        .def("init", &SPUC::allpass_1<float,float>::init)
        .def("clock", &SPUC::allpass_1<float,float>::clock)
    ;

}


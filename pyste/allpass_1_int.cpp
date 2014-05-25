
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass_1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_1_int)
{
    class_< SPUC::allpass_1<int,float> >("allpass_1_int", init< const SPUC::allpass_1<int,float>& >())
        .def(init< optional< float, long int, long int > >())
        .def("get_coefficient", &SPUC::allpass_1<int,float>::get_coefficient)
        .def("reset", &SPUC::allpass_1<int,float>::reset)
        .def("init", &SPUC::allpass_1<int,float>::init)
        .def("clock", &SPUC::allpass_1<int,float>::clock)
    ;

}


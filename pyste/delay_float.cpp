
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/delay.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_delay_float_set_size_overloads_0_1, set_size, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(delay_float)
{
    class_< SPUC::delay<float> >("delay_float", init< const SPUC::delay<float>& >())
        .def(init< optional< long int > >())
        .def_readwrite("num_taps", &SPUC::delay<float>::num_taps)
        .def("reset", &SPUC::delay<float>::reset)
        .def("check", &SPUC::delay<float>::check)
        .def("checkback", &SPUC::delay<float>::checkback)
        .def("last", &SPUC::delay<float>::last)
        .def("set_size", &SPUC::delay<float>::set_size, SPUC_delay_float_set_size_overloads_0_1())
        .def("input", &SPUC::delay<float>::input)
        .def("update", &SPUC::delay<float>::update)
    ;

}


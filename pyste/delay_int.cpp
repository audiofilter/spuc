
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/delay.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_delay_int_set_size_overloads_0_1, set_size, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(delay_int)
{
    class_< SPUC::delay<int> >("delay_int", init< const SPUC::delay<int>& >())
        .def(init< optional< long int > >())
        .def_readwrite("num_taps", &SPUC::delay<int>::num_taps)
        .def("reset", &SPUC::delay<int>::reset)
        .def("check", &SPUC::delay<int>::check)
        .def("checkback", &SPUC::delay<int>::checkback)
        .def("last", &SPUC::delay<int>::last)
        .def("set_size", &SPUC::delay<int>::set_size, SPUC_delay_int_set_size_overloads_0_1())
        .def("input", &SPUC::delay<int>::input)
        .def("update", &SPUC::delay<int>::update)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/delay.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_delay_double_set_size_overloads_0_1, set_size, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(delay_double)
{
    class_< SPUC::delay<double> >("delay_double", init< const SPUC::delay<double>& >())
        .def(init< optional< long int > >())
        .def_readwrite("num_taps", &SPUC::delay<double>::num_taps)
        .def("reset", &SPUC::delay<double>::reset)
        .def("check", &SPUC::delay<double>::check)
        .def("checkback", &SPUC::delay<double>::checkback)
        .def("last", &SPUC::delay<double>::last)
        .def("set_size", &SPUC::delay<double>::set_size, SPUC_delay_double_set_size_overloads_0_1())
        .def("input", &SPUC::delay<double>::input)
        .def("update", &SPUC::delay<double>::update)
    ;

}


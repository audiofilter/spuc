
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/running_sum.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(running_sum_int)
{
    class_< SPUC::running_sum<int> >("running_sum_int", init< const SPUC::running_sum<int>& >())
        .def(init< optional< long int > >())
        .def("set_size", &SPUC::running_sum<int>::set_size)
        .def("reset", &SPUC::running_sum<int>::reset)
        .def("get_result", &SPUC::running_sum<int>::get_result)
        .def("update", &SPUC::running_sum<int>::update)
        .def("average", &SPUC::running_sum<int>::average)
    ;

}


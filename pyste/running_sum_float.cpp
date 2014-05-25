
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/running_sum.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(running_sum_float)
{
    class_< SPUC::running_sum<float> >("running_sum_float", init< const SPUC::running_sum<float>& >())
        .def(init< optional< long int > >())
        .def("set_size", &SPUC::running_sum<float>::set_size)
        .def("reset", &SPUC::running_sum<float>::reset)
        .def("get_result", &SPUC::running_sum<float>::get_result)
        .def("update", &SPUC::running_sum<float>::update)
        .def("average", &SPUC::running_sum<float>::average)
    ;

}


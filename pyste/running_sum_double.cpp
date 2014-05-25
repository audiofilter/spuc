
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/running_sum.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(running_sum_double)
{
    class_< SPUC::running_sum<double> >("running_sum_double", init< const SPUC::running_sum<double>& >())
        .def(init< optional< long int > >())
        .def("set_size", &SPUC::running_sum<double>::set_size)
        .def("reset", &SPUC::running_sum<double>::reset)
        .def("get_result", &SPUC::running_sum<double>::get_result)
        .def("update", &SPUC::running_sum<double>::update)
        .def("average", &SPUC::running_sum<double>::average)
    ;

}


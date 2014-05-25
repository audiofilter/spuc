
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sum_and_dump.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(sum_and_dump_double)
{
    class_< SPUC::sum_and_dump<double> >("sum_and_dump_double", init< const SPUC::sum_and_dump<double>& >())
        .def(init< long int >())
        .def_readwrite("average", &SPUC::sum_and_dump<double>::average)
        .def_readwrite("result", &SPUC::sum_and_dump<double>::result)
        .def_readwrite("count_exp", &SPUC::sum_and_dump<double>::count_exp)
        .def_readwrite("count", &SPUC::sum_and_dump<double>::count)
        .def_readwrite("count_val", &SPUC::sum_and_dump<double>::count_val)
        .def("output", &SPUC::sum_and_dump<double>::output)
        .def("set_exp", &SPUC::sum_and_dump<double>::set_exp)
        .def("input", &SPUC::sum_and_dump<double>::input)
    ;

}


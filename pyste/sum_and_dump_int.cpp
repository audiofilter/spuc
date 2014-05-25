
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sum_and_dump.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(sum_and_dump_int)
{
    class_< SPUC::sum_and_dump<int> >("sum_and_dump_int", init< const SPUC::sum_and_dump<int>& >())
        .def(init< long int >())
        .def_readwrite("average", &SPUC::sum_and_dump<int>::average)
        .def_readwrite("result", &SPUC::sum_and_dump<int>::result)
        .def_readwrite("count_exp", &SPUC::sum_and_dump<int>::count_exp)
        .def_readwrite("count", &SPUC::sum_and_dump<int>::count)
        .def_readwrite("count_val", &SPUC::sum_and_dump<int>::count_val)
        .def("output", &SPUC::sum_and_dump<int>::output)
        .def("set_exp", &SPUC::sum_and_dump<int>::set_exp)
        .def("input", &SPUC::sum_and_dump<int>::input)
    ;

}


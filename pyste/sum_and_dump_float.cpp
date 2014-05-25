
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sum_and_dump.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(sum_and_dump_float)
{
    class_< SPUC::sum_and_dump<float> >("sum_and_dump_float", init< const SPUC::sum_and_dump<float>& >())
        .def(init< long int >())
        .def_readwrite("average", &SPUC::sum_and_dump<float>::average)
        .def_readwrite("result", &SPUC::sum_and_dump<float>::result)
        .def_readwrite("count_exp", &SPUC::sum_and_dump<float>::count_exp)
        .def_readwrite("count", &SPUC::sum_and_dump<float>::count)
        .def_readwrite("count_val", &SPUC::sum_and_dump<float>::count_val)
        .def("output", &SPUC::sum_and_dump<float>::output)
        .def("set_exp", &SPUC::sum_and_dump<float>::set_exp)
        .def("input", &SPUC::sum_and_dump<float>::input)
    ;

}


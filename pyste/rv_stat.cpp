
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/rv_stat.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(rv_stat)
{
    class_< SPUC::rv_stat >("rv_stat", init<  >())
        .def(init< const SPUC::rv_stat& >())
        .def("update", &SPUC::rv_stat::update)
        .def("average", &SPUC::rv_stat::average)
        .def("mean_sq", &SPUC::rv_stat::mean_sq)
        .def("rms", &SPUC::rv_stat::rms)
        .def("var", &SPUC::rv_stat::var)
        .def("std", &SPUC::rv_stat::std)
        .def("minimum", &SPUC::rv_stat::minimum)
        .def("maximum", &SPUC::rv_stat::maximum)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/quad_data.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(quad_data_int)
{
    class_< SPUC::quad_data<int> >("quad_data_int", init< const SPUC::quad_data<int>& >())
        .def(init< int >())
        .def_readwrite("rcfir", &SPUC::quad_data<int>::rcfir)
        .def_readwrite("pn_i", &SPUC::quad_data<int>::pn_i)
        .def_readwrite("pn_q", &SPUC::quad_data<int>::pn_q)
        .def_readwrite("symbols", &SPUC::quad_data<int>::symbols)
        .def_readwrite("over", &SPUC::quad_data<int>::over)
        .def_readwrite("data", &SPUC::quad_data<int>::data)
        .def_readwrite("interp", &SPUC::quad_data<int>::interp)
        .def_readwrite("prev_timing_offset", &SPUC::quad_data<int>::prev_timing_offset)
        .def("set_initial_offset", &SPUC::quad_data<int>::set_initial_offset)
        .def("get_fir_output", &SPUC::quad_data<int>::get_fir_output)
        .def("get_sample", &SPUC::quad_data<int>::get_sample)
    ;

}


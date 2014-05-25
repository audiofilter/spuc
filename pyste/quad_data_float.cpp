
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/quad_data.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(quad_data_float)
{
    class_< SPUC::quad_data<float> >("quad_data_float", init< const SPUC::quad_data<float>& >())
        .def(init< int >())
        .def_readwrite("rcfir", &SPUC::quad_data<float>::rcfir)
        .def_readwrite("pn_i", &SPUC::quad_data<float>::pn_i)
        .def_readwrite("pn_q", &SPUC::quad_data<float>::pn_q)
        .def_readwrite("symbols", &SPUC::quad_data<float>::symbols)
        .def_readwrite("over", &SPUC::quad_data<float>::over)
        .def_readwrite("data", &SPUC::quad_data<float>::data)
        .def_readwrite("interp", &SPUC::quad_data<float>::interp)
        .def_readwrite("prev_timing_offset", &SPUC::quad_data<float>::prev_timing_offset)
        .def("set_initial_offset", &SPUC::quad_data<float>::set_initial_offset)
        .def("get_fir_output", &SPUC::quad_data<float>::get_fir_output)
        .def("get_sample", &SPUC::quad_data<float>::get_sample)
    ;

}


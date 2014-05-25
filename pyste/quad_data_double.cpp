
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/quad_data.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(quad_data_double)
{
    class_< SPUC::quad_data<double> >("quad_data_double", init< const SPUC::quad_data<double>& >())
        .def(init< int >())
        .def_readwrite("rcfir", &SPUC::quad_data<double>::rcfir)
        .def_readwrite("pn_i", &SPUC::quad_data<double>::pn_i)
        .def_readwrite("pn_q", &SPUC::quad_data<double>::pn_q)
        .def_readwrite("symbols", &SPUC::quad_data<double>::symbols)
        .def_readwrite("over", &SPUC::quad_data<double>::over)
        .def_readwrite("data", &SPUC::quad_data<double>::data)
        .def_readwrite("interp", &SPUC::quad_data<double>::interp)
        .def_readwrite("prev_timing_offset", &SPUC::quad_data<double>::prev_timing_offset)
        .def("set_initial_offset", &SPUC::quad_data<double>::set_initial_offset)
        .def("get_fir_output", &SPUC::quad_data<double>::get_fir_output)
        .def("get_sample", &SPUC::quad_data<double>::get_sample)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/mle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(mle_float)
{
    class_< SPUC::mle<float> >("mle_float", init< const SPUC::mle<float>& >())
        .def(init< int, optional< int, long int > >())
        .def_readonly("mlsd_span", &SPUC::mle<float>::mlsd_span)
        .def_readonly("dfe_span", &SPUC::mle<float>::dfe_span)
        .def_readonly("n_branches", &SPUC::mle<float>::n_branches)
        .def_readonly("n_states", &SPUC::mle<float>::n_states)
        .def_readwrite("fb_est", &SPUC::mle<float>::fb_est)
        .def_readwrite("cfir", &SPUC::mle<float>::cfir)
        .def_readwrite("cir_mlsd", &SPUC::mle<float>::cir_mlsd)
        .def_readwrite("cir_dfe", &SPUC::mle<float>::cir_dfe)
        .def_readwrite("f_est", &SPUC::mle<float>::f_est)
        .def_readwrite("b_est", &SPUC::mle<float>::b_est)
        .def_readwrite("weight", &SPUC::mle<float>::weight)
        .def_readwrite("path", &SPUC::mle<float>::path)
        .def_readwrite("tmp_path", &SPUC::mle<float>::tmp_path)
        .def_readwrite("tmp_weight", &SPUC::mle<float>::tmp_weight)
        .def_readwrite("path_symbol", &SPUC::mle<float>::path_symbol)
        .def_readwrite("phase_states", &SPUC::mle<float>::phase_states)
        .def_readwrite("total_states", &SPUC::mle<float>::total_states)
        .def_readwrite("phase_inc", &SPUC::mle<float>::phase_inc)
        .def("reset", &SPUC::mle<float>::reset)
        .def("update_taps_lms", &SPUC::mle<float>::update_taps_lms)
        .def("tap0", &SPUC::mle<float>::tap0)
        .def("set_cir", &SPUC::mle<float>::set_cir)
        .def("df_est", &SPUC::mle<float>::df_est)
        .def("ff_estimate", &SPUC::mle<float>::ff_estimate)
        .def("estimate", &SPUC::mle<float>::estimate)
        .def("ddfse", &SPUC::mle<float>::ddfse)
        .def("mlsd", &SPUC::mle<float>::mlsd)
        .def("rsdfse", &SPUC::mle<float>::rsdfse)
        .def("equalize", &SPUC::mle<float>::equalize)
    ;

}


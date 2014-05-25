
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/mle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(mle_double)
{
    class_< SPUC::mle<double> >("mle_double", init< const SPUC::mle<double>& >())
        .def(init< int, optional< int, long int > >())
        .def_readonly("mlsd_span", &SPUC::mle<double>::mlsd_span)
        .def_readonly("dfe_span", &SPUC::mle<double>::dfe_span)
        .def_readonly("n_branches", &SPUC::mle<double>::n_branches)
        .def_readonly("n_states", &SPUC::mle<double>::n_states)
        .def_readwrite("fb_est", &SPUC::mle<double>::fb_est)
        .def_readwrite("cfir", &SPUC::mle<double>::cfir)
        .def_readwrite("cir_mlsd", &SPUC::mle<double>::cir_mlsd)
        .def_readwrite("cir_dfe", &SPUC::mle<double>::cir_dfe)
        .def_readwrite("f_est", &SPUC::mle<double>::f_est)
        .def_readwrite("b_est", &SPUC::mle<double>::b_est)
        .def_readwrite("weight", &SPUC::mle<double>::weight)
        .def_readwrite("path", &SPUC::mle<double>::path)
        .def_readwrite("tmp_path", &SPUC::mle<double>::tmp_path)
        .def_readwrite("tmp_weight", &SPUC::mle<double>::tmp_weight)
        .def_readwrite("path_symbol", &SPUC::mle<double>::path_symbol)
        .def_readwrite("phase_states", &SPUC::mle<double>::phase_states)
        .def_readwrite("total_states", &SPUC::mle<double>::total_states)
        .def_readwrite("phase_inc", &SPUC::mle<double>::phase_inc)
        .def("reset", &SPUC::mle<double>::reset)
        .def("update_taps_lms", &SPUC::mle<double>::update_taps_lms)
        .def("tap0", &SPUC::mle<double>::tap0)
        .def("set_cir", &SPUC::mle<double>::set_cir)
        .def("df_est", &SPUC::mle<double>::df_est)
        .def("ff_estimate", &SPUC::mle<double>::ff_estimate)
        .def("estimate", &SPUC::mle<double>::estimate)
        .def("ddfse", &SPUC::mle<double>::ddfse)
        .def("mlsd", &SPUC::mle<double>::mlsd)
        .def("rsdfse", &SPUC::mle<double>::rsdfse)
        .def("equalize", &SPUC::mle<double>::equalize)
    ;

}


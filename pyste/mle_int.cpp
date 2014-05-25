
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/mle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(mle_int)
{
    class_< SPUC::mle<int> >("mle_int", init< const SPUC::mle<int>& >())
        .def(init< int, optional< int, long int > >())
        .def_readonly("mlsd_span", &SPUC::mle<int>::mlsd_span)
        .def_readonly("dfe_span", &SPUC::mle<int>::dfe_span)
        .def_readonly("n_branches", &SPUC::mle<int>::n_branches)
        .def_readonly("n_states", &SPUC::mle<int>::n_states)
        .def_readwrite("fb_est", &SPUC::mle<int>::fb_est)
        .def_readwrite("cfir", &SPUC::mle<int>::cfir)
        .def_readwrite("cir_mlsd", &SPUC::mle<int>::cir_mlsd)
        .def_readwrite("cir_dfe", &SPUC::mle<int>::cir_dfe)
        .def_readwrite("f_est", &SPUC::mle<int>::f_est)
        .def_readwrite("b_est", &SPUC::mle<int>::b_est)
        .def_readwrite("weight", &SPUC::mle<int>::weight)
        .def_readwrite("path", &SPUC::mle<int>::path)
        .def_readwrite("tmp_path", &SPUC::mle<int>::tmp_path)
        .def_readwrite("tmp_weight", &SPUC::mle<int>::tmp_weight)
        .def_readwrite("path_symbol", &SPUC::mle<int>::path_symbol)
        .def_readwrite("phase_states", &SPUC::mle<int>::phase_states)
        .def_readwrite("total_states", &SPUC::mle<int>::total_states)
        .def_readwrite("phase_inc", &SPUC::mle<int>::phase_inc)
        .def("reset", &SPUC::mle<int>::reset)
        .def("update_taps_lms", &SPUC::mle<int>::update_taps_lms)
        .def("tap0", &SPUC::mle<int>::tap0)
        .def("set_cir", &SPUC::mle<int>::set_cir)
        .def("df_est", &SPUC::mle<int>::df_est)
        .def("ff_estimate", &SPUC::mle<int>::ff_estimate)
        .def("estimate", &SPUC::mle<int>::estimate)
        .def("ddfse", &SPUC::mle<int>::ddfse)
        .def("mlsd", &SPUC::mle<int>::mlsd)
        .def("rsdfse", &SPUC::mle<int>::rsdfse)
        .def("equalize", &SPUC::mle<int>::equalize)
    ;

}


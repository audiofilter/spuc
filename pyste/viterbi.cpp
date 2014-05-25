
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/viterbi.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(viterbi)
{
    class_< SPUC::viterbi_state >("viterbi_state", init<  >())
        .def(init< const SPUC::viterbi_state& >())
        .def_readwrite("path", &SPUC::viterbi_state::path)
        .def_readwrite("metric", &SPUC::viterbi_state::metric)
    ;

    class_< SPUC::viterbi >("viterbi", init<  >())
        .def(init< const SPUC::viterbi& >())
        .def_readwrite("decoded", &SPUC::viterbi::decoded)
        .def_readwrite("enable_output", &SPUC::viterbi::enable_output)
        .def_readwrite("output_ready", &SPUC::viterbi::output_ready)
        .def_readwrite("prev_value", &SPUC::viterbi::prev_value)
        .def_readwrite("state0", &SPUC::viterbi::state0)
        .def_readwrite("state1", &SPUC::viterbi::state1)
        .def_readwrite("state", &SPUC::viterbi::state)
        .def_readwrite("next", &SPUC::viterbi::next)
        .def_readwrite("bitcnt", &SPUC::viterbi::bitcnt)
        .def_readwrite("beststate", &SPUC::viterbi::beststate)
        .def_readwrite("depuncture_bit_number", &SPUC::viterbi::depuncture_bit_number)
        .def_readwrite("phase", &SPUC::viterbi::phase)
        .def("reset", &SPUC::viterbi::reset)
        .def("clock", &SPUC::viterbi::clock)
        .def("decode", &SPUC::viterbi::decode)
        .def("minimize_metrics", &SPUC::viterbi::minimize_metrics)
        .def("depuncture", &SPUC::viterbi::depuncture)
    ;

}


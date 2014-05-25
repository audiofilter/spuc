
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk_discriminators.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_qpsk_discriminators_set_mode_overloads_0_1, set_mode, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_discriminators)
{
    class_< SPUC::qpsk_discriminators >("qpsk_discriminators", init< const SPUC::qpsk_discriminators& >())
        .def(init< optional< int > >())
        .def_readwrite("bpsk_mode", &SPUC::qpsk_discriminators::bpsk_mode)
        .def_readwrite("fmf", &SPUC::qpsk_discriminators::fmf)
        .def_readwrite("prev_sam", &SPUC::qpsk_discriminators::prev_sam)
        .def_readwrite("prev_sym", &SPUC::qpsk_discriminators::prev_sym)
        .def_readwrite("data", &SPUC::qpsk_discriminators::data)
        .def_readwrite("hard_decision_prev", &SPUC::qpsk_discriminators::hard_decision_prev)
        .def_readwrite("decision", &SPUC::qpsk_discriminators::decision)
        .def_readwrite("hard_decision_delay", &SPUC::qpsk_discriminators::hard_decision_delay)
        .def_readwrite("timing_disc_delay", &SPUC::qpsk_discriminators::timing_disc_delay)
        .def("update", &SPUC::qpsk_discriminators::update)
        .def("sample", &SPUC::qpsk_discriminators::sample)
        .def("set_mode", &SPUC::qpsk_discriminators::set_mode, SPUC_qpsk_discriminators_set_mode_overloads_0_1())
        .def("cross_prod_afc", &SPUC::qpsk_discriminators::cross_prod_afc)
        .def("quad", &SPUC::qpsk_discriminators::quad)
        .def("rcfd", &SPUC::qpsk_discriminators::rcfd)
        .def("dd_timing_disc", &SPUC::qpsk_discriminators::dd_timing_disc)
        .def("nda_timing_disc", &SPUC::qpsk_discriminators::nda_timing_disc)
        .def("symbol_lock_out", &SPUC::qpsk_discriminators::symbol_lock_out)
        .def("pll_disc", &SPUC::qpsk_discriminators::pll_disc)
    ;

}


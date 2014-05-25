
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_int)
{
    class_< SPUC::qpsk<int> >("qpsk_int", init<  >())
        .def(init< const SPUC::qpsk<int>& >())
        .def_readwrite("ADC", &SPUC::qpsk<int>::ADC)
        .def_readwrite("carrier_loop_filter", &SPUC::qpsk<int>::carrier_loop_filter)
        .def_readwrite("symbol_loop_filter", &SPUC::qpsk<int>::symbol_loop_filter)
        .def_readwrite("carrier_loop_out", &SPUC::qpsk<int>::carrier_loop_out)
        .def_readwrite("symbol_loop_out", &SPUC::qpsk<int>::symbol_loop_out)
        .def_readwrite("symbol_clk", &SPUC::qpsk<int>::symbol_clk)
        .def_readwrite("symbol_clk_pls", &SPUC::qpsk<int>::symbol_clk_pls)
        .def_readwrite("sample_clk", &SPUC::qpsk<int>::sample_clk)
        .def_readwrite("symbol_x2_clk", &SPUC::qpsk<int>::symbol_x2_clk)
        .def_readwrite("symbol_x2_clk_pls", &SPUC::qpsk<int>::symbol_x2_clk_pls)
        .def_readwrite("c_nco", &SPUC::qpsk<int>::c_nco)
        .def_readwrite("rcv_sqrt_rc", &SPUC::qpsk<int>::rcv_sqrt_rc)
        .def_readwrite("final_baseband_delay", &SPUC::qpsk<int>::final_baseband_delay)
        .def_readwrite("hard_decision_delay", &SPUC::qpsk<int>::hard_decision_delay)
        .def_readwrite("timing_disc_delay", &SPUC::qpsk<int>::timing_disc_delay)
        .def_readwrite("bpsk", &SPUC::qpsk<int>::bpsk)
        .def_readwrite("dec_rate_log", &SPUC::qpsk<int>::dec_rate_log)
        .def_readwrite("carrier_error", &SPUC::qpsk<int>::carrier_error)
        .def_readwrite("symbol_nco_out", &SPUC::qpsk<int>::symbol_nco_out)
        .def_readwrite("prev_sam", &SPUC::qpsk<int>::prev_sam)
        .def_readwrite("prev_sym", &SPUC::qpsk<int>::prev_sym)
        .def_readwrite("decision", &SPUC::qpsk<int>::decision)
        .def_readwrite("hard_decision_prev", &SPUC::qpsk<int>::hard_decision_prev)
        .def_readwrite("final_baseband_prev", &SPUC::qpsk<int>::final_baseband_prev)
        .def_readwrite("baseband", &SPUC::qpsk<int>::baseband)
        .def_readwrite("resampled", &SPUC::qpsk<int>::resampled)
        .def_readwrite("carrier_in", &SPUC::qpsk<int>::carrier_in)
        .def_readwrite("carrier_nco_out", &SPUC::qpsk<int>::carrier_nco_out)
        .def_readwrite("mf_in", &SPUC::qpsk<int>::mf_in)
        .def_readwrite("mf_out", &SPUC::qpsk<int>::mf_out)
        .def_readwrite("final_baseband", &SPUC::qpsk<int>::final_baseband)
        .def_readwrite("hard_decision", &SPUC::qpsk<int>::hard_decision)
        .def_readwrite("timing_error", &SPUC::qpsk<int>::timing_error)
        .def_readwrite("nda_timing_error", &SPUC::qpsk<int>::nda_timing_error)
        .def("I_data", &SPUC::qpsk<int>::I_data)
        .def("Q_data", &SPUC::qpsk<int>::Q_data)
        .def("data", &SPUC::qpsk<int>::data)
        .def("carrier_loop", &SPUC::qpsk<int>::carrier_loop)
        .def("symbol_loop", &SPUC::qpsk<int>::symbol_loop)
        .def("symclk", &SPUC::qpsk<int>::symclk)
        .def("reset", &SPUC::qpsk<int>::reset)
        .def("clock", &SPUC::qpsk<int>::clock)
    ;

}


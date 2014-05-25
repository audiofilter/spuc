
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_float)
{
    class_< SPUC::qpsk<float> >("qpsk_float", init<  >())
        .def(init< const SPUC::qpsk<float>& >())
        .def_readwrite("ADC", &SPUC::qpsk<float>::ADC)
        .def_readwrite("carrier_loop_filter", &SPUC::qpsk<float>::carrier_loop_filter)
        .def_readwrite("symbol_loop_filter", &SPUC::qpsk<float>::symbol_loop_filter)
        .def_readwrite("carrier_loop_out", &SPUC::qpsk<float>::carrier_loop_out)
        .def_readwrite("symbol_loop_out", &SPUC::qpsk<float>::symbol_loop_out)
        .def_readwrite("symbol_clk", &SPUC::qpsk<float>::symbol_clk)
        .def_readwrite("symbol_clk_pls", &SPUC::qpsk<float>::symbol_clk_pls)
        .def_readwrite("sample_clk", &SPUC::qpsk<float>::sample_clk)
        .def_readwrite("symbol_x2_clk", &SPUC::qpsk<float>::symbol_x2_clk)
        .def_readwrite("symbol_x2_clk_pls", &SPUC::qpsk<float>::symbol_x2_clk_pls)
        .def_readwrite("c_nco", &SPUC::qpsk<float>::c_nco)
        .def_readwrite("rcv_sqrt_rc", &SPUC::qpsk<float>::rcv_sqrt_rc)
        .def_readwrite("final_baseband_delay", &SPUC::qpsk<float>::final_baseband_delay)
        .def_readwrite("hard_decision_delay", &SPUC::qpsk<float>::hard_decision_delay)
        .def_readwrite("timing_disc_delay", &SPUC::qpsk<float>::timing_disc_delay)
        .def_readwrite("bpsk", &SPUC::qpsk<float>::bpsk)
        .def_readwrite("dec_rate_log", &SPUC::qpsk<float>::dec_rate_log)
        .def_readwrite("carrier_error", &SPUC::qpsk<float>::carrier_error)
        .def_readwrite("symbol_nco_out", &SPUC::qpsk<float>::symbol_nco_out)
        .def_readwrite("prev_sam", &SPUC::qpsk<float>::prev_sam)
        .def_readwrite("prev_sym", &SPUC::qpsk<float>::prev_sym)
        .def_readwrite("decision", &SPUC::qpsk<float>::decision)
        .def_readwrite("hard_decision_prev", &SPUC::qpsk<float>::hard_decision_prev)
        .def_readwrite("final_baseband_prev", &SPUC::qpsk<float>::final_baseband_prev)
        .def_readwrite("baseband", &SPUC::qpsk<float>::baseband)
        .def_readwrite("resampled", &SPUC::qpsk<float>::resampled)
        .def_readwrite("carrier_in", &SPUC::qpsk<float>::carrier_in)
        .def_readwrite("carrier_nco_out", &SPUC::qpsk<float>::carrier_nco_out)
        .def_readwrite("mf_in", &SPUC::qpsk<float>::mf_in)
        .def_readwrite("mf_out", &SPUC::qpsk<float>::mf_out)
        .def_readwrite("final_baseband", &SPUC::qpsk<float>::final_baseband)
        .def_readwrite("hard_decision", &SPUC::qpsk<float>::hard_decision)
        .def_readwrite("timing_error", &SPUC::qpsk<float>::timing_error)
        .def_readwrite("nda_timing_error", &SPUC::qpsk<float>::nda_timing_error)
        .def("I_data", &SPUC::qpsk<float>::I_data)
        .def("Q_data", &SPUC::qpsk<float>::Q_data)
        .def("data", &SPUC::qpsk<float>::data)
        .def("carrier_loop", &SPUC::qpsk<float>::carrier_loop)
        .def("symbol_loop", &SPUC::qpsk<float>::symbol_loop)
        .def("symclk", &SPUC::qpsk<float>::symclk)
        .def("reset", &SPUC::qpsk<float>::reset)
        .def("clock", &SPUC::qpsk<float>::clock)
    ;

}


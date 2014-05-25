
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_double)
{
    class_< SPUC::qpsk<double> >("qpsk_double", init<  >())
        .def(init< const SPUC::qpsk<double>& >())
        .def_readwrite("ADC", &SPUC::qpsk<double>::ADC)
        .def_readwrite("carrier_loop_filter", &SPUC::qpsk<double>::carrier_loop_filter)
        .def_readwrite("symbol_loop_filter", &SPUC::qpsk<double>::symbol_loop_filter)
        .def_readwrite("carrier_loop_out", &SPUC::qpsk<double>::carrier_loop_out)
        .def_readwrite("symbol_loop_out", &SPUC::qpsk<double>::symbol_loop_out)
        .def_readwrite("symbol_clk", &SPUC::qpsk<double>::symbol_clk)
        .def_readwrite("symbol_clk_pls", &SPUC::qpsk<double>::symbol_clk_pls)
        .def_readwrite("sample_clk", &SPUC::qpsk<double>::sample_clk)
        .def_readwrite("symbol_x2_clk", &SPUC::qpsk<double>::symbol_x2_clk)
        .def_readwrite("symbol_x2_clk_pls", &SPUC::qpsk<double>::symbol_x2_clk_pls)
        .def_readwrite("c_nco", &SPUC::qpsk<double>::c_nco)
        .def_readwrite("rcv_sqrt_rc", &SPUC::qpsk<double>::rcv_sqrt_rc)
        .def_readwrite("final_baseband_delay", &SPUC::qpsk<double>::final_baseband_delay)
        .def_readwrite("hard_decision_delay", &SPUC::qpsk<double>::hard_decision_delay)
        .def_readwrite("timing_disc_delay", &SPUC::qpsk<double>::timing_disc_delay)
        .def_readwrite("bpsk", &SPUC::qpsk<double>::bpsk)
        .def_readwrite("dec_rate_log", &SPUC::qpsk<double>::dec_rate_log)
        .def_readwrite("carrier_error", &SPUC::qpsk<double>::carrier_error)
        .def_readwrite("symbol_nco_out", &SPUC::qpsk<double>::symbol_nco_out)
        .def_readwrite("prev_sam", &SPUC::qpsk<double>::prev_sam)
        .def_readwrite("prev_sym", &SPUC::qpsk<double>::prev_sym)
        .def_readwrite("decision", &SPUC::qpsk<double>::decision)
        .def_readwrite("hard_decision_prev", &SPUC::qpsk<double>::hard_decision_prev)
        .def_readwrite("final_baseband_prev", &SPUC::qpsk<double>::final_baseband_prev)
        .def_readwrite("baseband", &SPUC::qpsk<double>::baseband)
        .def_readwrite("resampled", &SPUC::qpsk<double>::resampled)
        .def_readwrite("carrier_in", &SPUC::qpsk<double>::carrier_in)
        .def_readwrite("carrier_nco_out", &SPUC::qpsk<double>::carrier_nco_out)
        .def_readwrite("mf_in", &SPUC::qpsk<double>::mf_in)
        .def_readwrite("mf_out", &SPUC::qpsk<double>::mf_out)
        .def_readwrite("final_baseband", &SPUC::qpsk<double>::final_baseband)
        .def_readwrite("hard_decision", &SPUC::qpsk<double>::hard_decision)
        .def_readwrite("timing_error", &SPUC::qpsk<double>::timing_error)
        .def_readwrite("nda_timing_error", &SPUC::qpsk<double>::nda_timing_error)
        .def("I_data", &SPUC::qpsk<double>::I_data)
        .def("Q_data", &SPUC::qpsk<double>::Q_data)
        .def("data", &SPUC::qpsk<double>::data)
        .def("carrier_loop", &SPUC::qpsk<double>::carrier_loop)
        .def("symbol_loop", &SPUC::qpsk<double>::symbol_loop)
        .def("symclk", &SPUC::qpsk<double>::symclk)
        .def("reset", &SPUC::qpsk<double>::reset)
        .def("clock", &SPUC::qpsk<double>::clock)
    ;

}


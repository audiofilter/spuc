
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk_variable.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_variable_int)
{
    class_< SPUC::qpsk_variable<int> >("qpsk_variable_int", init<  >())
        .def(init< const SPUC::qpsk_variable<int>& >())
        .def_readwrite("ADC", &SPUC::qpsk_variable<int>::ADC)
        .def_readwrite("rcv_sqrt_rc", &SPUC::qpsk_variable<int>::rcv_sqrt_rc)
        .def_readwrite("interp", &SPUC::qpsk_variable<int>::interp)
        .def_readwrite("final_baseband_delay", &SPUC::qpsk_variable<int>::final_baseband_delay)
        .def_readwrite("hard_decision_delay", &SPUC::qpsk_variable<int>::hard_decision_delay)
        .def_readwrite("timing_disc_delay", &SPUC::qpsk_variable<int>::timing_disc_delay)
        .def_readwrite("symbol_lock_detect", &SPUC::qpsk_variable<int>::symbol_lock_detect)
        .def_readwrite("fmf", &SPUC::qpsk_variable<int>::fmf)
        .def_readwrite("sigma_delta", &SPUC::qpsk_variable<int>::sigma_delta)
        .def_readwrite("afc_loop_filter", &SPUC::qpsk_variable<int>::afc_loop_filter)
        .def_readwrite("carrier_loop_filter", &SPUC::qpsk_variable<int>::carrier_loop_filter)
        .def_readwrite("symbol_loop_filter", &SPUC::qpsk_variable<int>::symbol_loop_filter)
        .def_readwrite("discriminators", &SPUC::qpsk_variable<int>::discriminators)
        .def_readwrite("agc_bit", &SPUC::qpsk_variable<int>::agc_bit)
        .def_readwrite("carrier_loop_out", &SPUC::qpsk_variable<int>::carrier_loop_out)
        .def_readwrite("symbol_loop_out", &SPUC::qpsk_variable<int>::symbol_loop_out)
        .def_readwrite("symbol_clk", &SPUC::qpsk_variable<int>::symbol_clk)
        .def_readwrite("symbol_clk_pls", &SPUC::qpsk_variable<int>::symbol_clk_pls)
        .def_readwrite("sample_clk", &SPUC::qpsk_variable<int>::sample_clk)
        .def_readwrite("symbol_x2_clk", &SPUC::qpsk_variable<int>::symbol_x2_clk)
        .def_readwrite("symbol_x2_clk_pls", &SPUC::qpsk_variable<int>::symbol_x2_clk_pls)
        .def_readwrite("carrier__nco", &SPUC::qpsk_variable<int>::carrier__nco)
        .def_readwrite("cordic_mult", &SPUC::qpsk_variable<int>::cordic_mult)
        .def_readwrite("rate_change", &SPUC::qpsk_variable<int>::rate_change)
        .def_readwrite("bpsk", &SPUC::qpsk_variable<int>::bpsk)
        .def_readwrite("resampler_round", &SPUC::qpsk_variable<int>::resampler_round)
        .def_readwrite("sym_dec", &SPUC::qpsk_variable<int>::sym_dec)
        .def_readwrite("carrier_error", &SPUC::qpsk_variable<int>::carrier_error)
        .def_readwrite("symbol_nco_out", &SPUC::qpsk_variable<int>::symbol_nco_out)
        .def_readwrite("hard_decision_prev", &SPUC::qpsk_variable<int>::hard_decision_prev)
        .def_readwrite("final_baseband_prev", &SPUC::qpsk_variable<int>::final_baseband_prev)
        .def_readwrite("adc_out", &SPUC::qpsk_variable<int>::adc_out)
        .def_readwrite("baseband", &SPUC::qpsk_variable<int>::baseband)
        .def_readwrite("decimated", &SPUC::qpsk_variable<int>::decimated)
        .def_readwrite("decimated_baseband", &SPUC::qpsk_variable<int>::decimated_baseband)
        .def_readwrite("resampled", &SPUC::qpsk_variable<int>::resampled)
        .def_readwrite("carrier_in", &SPUC::qpsk_variable<int>::carrier_in)
        .def_readwrite("carrier_nco_out", &SPUC::qpsk_variable<int>::carrier_nco_out)
        .def_readwrite("mf_in", &SPUC::qpsk_variable<int>::mf_in)
        .def_readwrite("mf_out", &SPUC::qpsk_variable<int>::mf_out)
        .def_readwrite("fmf_out", &SPUC::qpsk_variable<int>::fmf_out)
        .def_readwrite("final_baseband", &SPUC::qpsk_variable<int>::final_baseband)
        .def_readwrite("timing_error", &SPUC::qpsk_variable<int>::timing_error)
        .def_readwrite("nda_timing_error", &SPUC::qpsk_variable<int>::nda_timing_error)
        .def_readwrite("sym_lock", &SPUC::qpsk_variable<int>::sym_lock)
        .def_readwrite("symbol_locked", &SPUC::qpsk_variable<int>::symbol_locked)
        .def_readwrite("sym_lock_thres", &SPUC::qpsk_variable<int>::sym_lock_thres)
        .def_readwrite("cp_afc", &SPUC::qpsk_variable<int>::cp_afc)
        .def_readwrite("quad_afc", &SPUC::qpsk_variable<int>::quad_afc)
        .def_readwrite("afc", &SPUC::qpsk_variable<int>::afc)
        .def_readwrite("hard_decision", &SPUC::qpsk_variable<int>::hard_decision)
        .def_readwrite("qpsk_bpsk_reg", &SPUC::qpsk_variable<int>::qpsk_bpsk_reg)
        .def_readwrite("lock_rate_reg", &SPUC::qpsk_variable<int>::lock_rate_reg)
        .def_readwrite("invert_q_reg", &SPUC::qpsk_variable<int>::invert_q_reg)
        .def("I_data", &SPUC::qpsk_variable<int>::I_data)
        .def("Q_data", &SPUC::qpsk_variable<int>::Q_data)
        .def("data", &SPUC::qpsk_variable<int>::data)
        .def("carrier_loop", &SPUC::qpsk_variable<int>::carrier_loop)
        .def("symbol_loop", &SPUC::qpsk_variable<int>::symbol_loop)
        .def("symclk", &SPUC::qpsk_variable<int>::symclk)
        .def("agc_out", &SPUC::qpsk_variable<int>::agc_out)
        .def("clock", &SPUC::qpsk_variable<int>::clock)
    ;

}


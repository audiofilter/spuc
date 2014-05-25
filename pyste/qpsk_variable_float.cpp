
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk_variable.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_variable_float)
{
    class_< SPUC::qpsk_variable<float> >("qpsk_variable_float", init<  >())
        .def(init< const SPUC::qpsk_variable<float>& >())
        .def_readwrite("ADC", &SPUC::qpsk_variable<float>::ADC)
        .def_readwrite("rcv_sqrt_rc", &SPUC::qpsk_variable<float>::rcv_sqrt_rc)
        .def_readwrite("interp", &SPUC::qpsk_variable<float>::interp)
        .def_readwrite("final_baseband_delay", &SPUC::qpsk_variable<float>::final_baseband_delay)
        .def_readwrite("hard_decision_delay", &SPUC::qpsk_variable<float>::hard_decision_delay)
        .def_readwrite("timing_disc_delay", &SPUC::qpsk_variable<float>::timing_disc_delay)
        .def_readwrite("symbol_lock_detect", &SPUC::qpsk_variable<float>::symbol_lock_detect)
        .def_readwrite("fmf", &SPUC::qpsk_variable<float>::fmf)
        .def_readwrite("sigma_delta", &SPUC::qpsk_variable<float>::sigma_delta)
        .def_readwrite("afc_loop_filter", &SPUC::qpsk_variable<float>::afc_loop_filter)
        .def_readwrite("carrier_loop_filter", &SPUC::qpsk_variable<float>::carrier_loop_filter)
        .def_readwrite("symbol_loop_filter", &SPUC::qpsk_variable<float>::symbol_loop_filter)
        .def_readwrite("discriminators", &SPUC::qpsk_variable<float>::discriminators)
        .def_readwrite("agc_bit", &SPUC::qpsk_variable<float>::agc_bit)
        .def_readwrite("carrier_loop_out", &SPUC::qpsk_variable<float>::carrier_loop_out)
        .def_readwrite("symbol_loop_out", &SPUC::qpsk_variable<float>::symbol_loop_out)
        .def_readwrite("symbol_clk", &SPUC::qpsk_variable<float>::symbol_clk)
        .def_readwrite("symbol_clk_pls", &SPUC::qpsk_variable<float>::symbol_clk_pls)
        .def_readwrite("sample_clk", &SPUC::qpsk_variable<float>::sample_clk)
        .def_readwrite("symbol_x2_clk", &SPUC::qpsk_variable<float>::symbol_x2_clk)
        .def_readwrite("symbol_x2_clk_pls", &SPUC::qpsk_variable<float>::symbol_x2_clk_pls)
        .def_readwrite("carrier__nco", &SPUC::qpsk_variable<float>::carrier__nco)
        .def_readwrite("cordic_mult", &SPUC::qpsk_variable<float>::cordic_mult)
        .def_readwrite("rate_change", &SPUC::qpsk_variable<float>::rate_change)
        .def_readwrite("bpsk", &SPUC::qpsk_variable<float>::bpsk)
        .def_readwrite("resampler_round", &SPUC::qpsk_variable<float>::resampler_round)
        .def_readwrite("sym_dec", &SPUC::qpsk_variable<float>::sym_dec)
        .def_readwrite("carrier_error", &SPUC::qpsk_variable<float>::carrier_error)
        .def_readwrite("symbol_nco_out", &SPUC::qpsk_variable<float>::symbol_nco_out)
        .def_readwrite("hard_decision_prev", &SPUC::qpsk_variable<float>::hard_decision_prev)
        .def_readwrite("final_baseband_prev", &SPUC::qpsk_variable<float>::final_baseband_prev)
        .def_readwrite("adc_out", &SPUC::qpsk_variable<float>::adc_out)
        .def_readwrite("baseband", &SPUC::qpsk_variable<float>::baseband)
        .def_readwrite("decimated", &SPUC::qpsk_variable<float>::decimated)
        .def_readwrite("decimated_baseband", &SPUC::qpsk_variable<float>::decimated_baseband)
        .def_readwrite("resampled", &SPUC::qpsk_variable<float>::resampled)
        .def_readwrite("carrier_in", &SPUC::qpsk_variable<float>::carrier_in)
        .def_readwrite("carrier_nco_out", &SPUC::qpsk_variable<float>::carrier_nco_out)
        .def_readwrite("mf_in", &SPUC::qpsk_variable<float>::mf_in)
        .def_readwrite("mf_out", &SPUC::qpsk_variable<float>::mf_out)
        .def_readwrite("fmf_out", &SPUC::qpsk_variable<float>::fmf_out)
        .def_readwrite("final_baseband", &SPUC::qpsk_variable<float>::final_baseband)
        .def_readwrite("timing_error", &SPUC::qpsk_variable<float>::timing_error)
        .def_readwrite("nda_timing_error", &SPUC::qpsk_variable<float>::nda_timing_error)
        .def_readwrite("sym_lock", &SPUC::qpsk_variable<float>::sym_lock)
        .def_readwrite("symbol_locked", &SPUC::qpsk_variable<float>::symbol_locked)
        .def_readwrite("sym_lock_thres", &SPUC::qpsk_variable<float>::sym_lock_thres)
        .def_readwrite("cp_afc", &SPUC::qpsk_variable<float>::cp_afc)
        .def_readwrite("quad_afc", &SPUC::qpsk_variable<float>::quad_afc)
        .def_readwrite("afc", &SPUC::qpsk_variable<float>::afc)
        .def_readwrite("hard_decision", &SPUC::qpsk_variable<float>::hard_decision)
        .def_readwrite("qpsk_bpsk_reg", &SPUC::qpsk_variable<float>::qpsk_bpsk_reg)
        .def_readwrite("lock_rate_reg", &SPUC::qpsk_variable<float>::lock_rate_reg)
        .def_readwrite("invert_q_reg", &SPUC::qpsk_variable<float>::invert_q_reg)
        .def("I_data", &SPUC::qpsk_variable<float>::I_data)
        .def("Q_data", &SPUC::qpsk_variable<float>::Q_data)
        .def("data", &SPUC::qpsk_variable<float>::data)
        .def("carrier_loop", &SPUC::qpsk_variable<float>::carrier_loop)
        .def("symbol_loop", &SPUC::qpsk_variable<float>::symbol_loop)
        .def("symclk", &SPUC::qpsk_variable<float>::symclk)
        .def("agc_out", &SPUC::qpsk_variable<float>::agc_out)
        .def("clock", &SPUC::qpsk_variable<float>::clock)
    ;

}


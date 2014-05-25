
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk_variable.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_variable_double)
{
    class_< SPUC::qpsk_variable<double> >("qpsk_variable_double", init<  >())
        .def(init< const SPUC::qpsk_variable<double>& >())
        .def_readwrite("ADC", &SPUC::qpsk_variable<double>::ADC)
        .def_readwrite("rcv_sqrt_rc", &SPUC::qpsk_variable<double>::rcv_sqrt_rc)
        .def_readwrite("interp", &SPUC::qpsk_variable<double>::interp)
        .def_readwrite("final_baseband_delay", &SPUC::qpsk_variable<double>::final_baseband_delay)
        .def_readwrite("hard_decision_delay", &SPUC::qpsk_variable<double>::hard_decision_delay)
        .def_readwrite("timing_disc_delay", &SPUC::qpsk_variable<double>::timing_disc_delay)
        .def_readwrite("symbol_lock_detect", &SPUC::qpsk_variable<double>::symbol_lock_detect)
        .def_readwrite("fmf", &SPUC::qpsk_variable<double>::fmf)
        .def_readwrite("sigma_delta", &SPUC::qpsk_variable<double>::sigma_delta)
        .def_readwrite("afc_loop_filter", &SPUC::qpsk_variable<double>::afc_loop_filter)
        .def_readwrite("carrier_loop_filter", &SPUC::qpsk_variable<double>::carrier_loop_filter)
        .def_readwrite("symbol_loop_filter", &SPUC::qpsk_variable<double>::symbol_loop_filter)
        .def_readwrite("discriminators", &SPUC::qpsk_variable<double>::discriminators)
        .def_readwrite("agc_bit", &SPUC::qpsk_variable<double>::agc_bit)
        .def_readwrite("carrier_loop_out", &SPUC::qpsk_variable<double>::carrier_loop_out)
        .def_readwrite("symbol_loop_out", &SPUC::qpsk_variable<double>::symbol_loop_out)
        .def_readwrite("symbol_clk", &SPUC::qpsk_variable<double>::symbol_clk)
        .def_readwrite("symbol_clk_pls", &SPUC::qpsk_variable<double>::symbol_clk_pls)
        .def_readwrite("sample_clk", &SPUC::qpsk_variable<double>::sample_clk)
        .def_readwrite("symbol_x2_clk", &SPUC::qpsk_variable<double>::symbol_x2_clk)
        .def_readwrite("symbol_x2_clk_pls", &SPUC::qpsk_variable<double>::symbol_x2_clk_pls)
        .def_readwrite("carrier__nco", &SPUC::qpsk_variable<double>::carrier__nco)
        .def_readwrite("cordic_mult", &SPUC::qpsk_variable<double>::cordic_mult)
        .def_readwrite("rate_change", &SPUC::qpsk_variable<double>::rate_change)
        .def_readwrite("bpsk", &SPUC::qpsk_variable<double>::bpsk)
        .def_readwrite("resampler_round", &SPUC::qpsk_variable<double>::resampler_round)
        .def_readwrite("sym_dec", &SPUC::qpsk_variable<double>::sym_dec)
        .def_readwrite("carrier_error", &SPUC::qpsk_variable<double>::carrier_error)
        .def_readwrite("symbol_nco_out", &SPUC::qpsk_variable<double>::symbol_nco_out)
        .def_readwrite("hard_decision_prev", &SPUC::qpsk_variable<double>::hard_decision_prev)
        .def_readwrite("final_baseband_prev", &SPUC::qpsk_variable<double>::final_baseband_prev)
        .def_readwrite("adc_out", &SPUC::qpsk_variable<double>::adc_out)
        .def_readwrite("baseband", &SPUC::qpsk_variable<double>::baseband)
        .def_readwrite("decimated", &SPUC::qpsk_variable<double>::decimated)
        .def_readwrite("decimated_baseband", &SPUC::qpsk_variable<double>::decimated_baseband)
        .def_readwrite("resampled", &SPUC::qpsk_variable<double>::resampled)
        .def_readwrite("carrier_in", &SPUC::qpsk_variable<double>::carrier_in)
        .def_readwrite("carrier_nco_out", &SPUC::qpsk_variable<double>::carrier_nco_out)
        .def_readwrite("mf_in", &SPUC::qpsk_variable<double>::mf_in)
        .def_readwrite("mf_out", &SPUC::qpsk_variable<double>::mf_out)
        .def_readwrite("fmf_out", &SPUC::qpsk_variable<double>::fmf_out)
        .def_readwrite("final_baseband", &SPUC::qpsk_variable<double>::final_baseband)
        .def_readwrite("timing_error", &SPUC::qpsk_variable<double>::timing_error)
        .def_readwrite("nda_timing_error", &SPUC::qpsk_variable<double>::nda_timing_error)
        .def_readwrite("sym_lock", &SPUC::qpsk_variable<double>::sym_lock)
        .def_readwrite("symbol_locked", &SPUC::qpsk_variable<double>::symbol_locked)
        .def_readwrite("sym_lock_thres", &SPUC::qpsk_variable<double>::sym_lock_thres)
        .def_readwrite("cp_afc", &SPUC::qpsk_variable<double>::cp_afc)
        .def_readwrite("quad_afc", &SPUC::qpsk_variable<double>::quad_afc)
        .def_readwrite("afc", &SPUC::qpsk_variable<double>::afc)
        .def_readwrite("hard_decision", &SPUC::qpsk_variable<double>::hard_decision)
        .def_readwrite("qpsk_bpsk_reg", &SPUC::qpsk_variable<double>::qpsk_bpsk_reg)
        .def_readwrite("lock_rate_reg", &SPUC::qpsk_variable<double>::lock_rate_reg)
        .def_readwrite("invert_q_reg", &SPUC::qpsk_variable<double>::invert_q_reg)
        .def("I_data", &SPUC::qpsk_variable<double>::I_data)
        .def("Q_data", &SPUC::qpsk_variable<double>::Q_data)
        .def("data", &SPUC::qpsk_variable<double>::data)
        .def("carrier_loop", &SPUC::qpsk_variable<double>::carrier_loop)
        .def("symbol_loop", &SPUC::qpsk_variable<double>::symbol_loop)
        .def("symclk", &SPUC::qpsk_variable<double>::symclk)
        .def("agc_out", &SPUC::qpsk_variable<double>::agc_out)
        .def("clock", &SPUC::qpsk_variable<double>::clock)
    ;

}


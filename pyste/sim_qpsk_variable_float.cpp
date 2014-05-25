
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qpsk_variable.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qpsk_variable_float_loop_init_overloads_1_2, loop_init, 1, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qpsk_variable_float)
{
    class_< SPUC::sim_qpsk_variable<float> >("sim_qpsk_variable_float", init<  >())
        .def(init< const SPUC::sim_qpsk_variable<float>& >())
        .def_readwrite("BER_mon", &SPUC::sim_qpsk_variable<float>::BER_mon)
        .def_readwrite("tx_data_source", &SPUC::sim_qpsk_variable<float>::tx_data_source)
        .def_readwrite("freq_offset", &SPUC::sim_qpsk_variable<float>::freq_offset)
        .def_readwrite("n", &SPUC::sim_qpsk_variable<float>::n)
        .def_readwrite("RECEIVER", &SPUC::sim_qpsk_variable<float>::RECEIVER)
        .def_readwrite("num", &SPUC::sim_qpsk_variable<float>::num)
        .def_readwrite("var", &SPUC::sim_qpsk_variable<float>::var)
        .def_readwrite("snr", &SPUC::sim_qpsk_variable<float>::snr)
        .def_readwrite("timing_offset", &SPUC::sim_qpsk_variable<float>::timing_offset)
        .def_readwrite("total_over", &SPUC::sim_qpsk_variable<float>::total_over)
        .def_readwrite("data", &SPUC::sim_qpsk_variable<float>::data)
        .def_readwrite("base", &SPUC::sim_qpsk_variable<float>::base)
        .def_readwrite("main", &SPUC::sim_qpsk_variable<float>::main)
        .def_readwrite("b_noise", &SPUC::sim_qpsk_variable<float>::b_noise)
        .def_readwrite("sum_s", &SPUC::sim_qpsk_variable<float>::sum_s)
        .def_readwrite("sum_n", &SPUC::sim_qpsk_variable<float>::sum_n)
        .def_readwrite("rcv_symbols", &SPUC::sim_qpsk_variable<float>::rcv_symbols)
        .def_readwrite("count", &SPUC::sim_qpsk_variable<float>::count)
        .def_readwrite("dec_rate_log", &SPUC::sim_qpsk_variable<float>::dec_rate_log)
        .def_readwrite("resample_over", &SPUC::sim_qpsk_variable<float>::resample_over)
        .def_readwrite("agc_scale", &SPUC::sim_qpsk_variable<float>::agc_scale)
        .def_readwrite("nominal_scale", &SPUC::sim_qpsk_variable<float>::nominal_scale)
        .def_readwrite("analog_agc", &SPUC::sim_qpsk_variable<float>::analog_agc)
        .def_readwrite("analog_filter_gain", &SPUC::sim_qpsk_variable<float>::analog_filter_gain)
        .def_readwrite("analog_agc_gain", &SPUC::sim_qpsk_variable<float>::analog_agc_gain)
        .def_readwrite("actual_over", &SPUC::sim_qpsk_variable<float>::actual_over)
        .def_readwrite("tx_time_inc", &SPUC::sim_qpsk_variable<float>::tx_time_inc)
        .def_readwrite("rc_delay", &SPUC::sim_qpsk_variable<float>::rc_delay)
        .def_readwrite("symbol_nco_word", &SPUC::sim_qpsk_variable<float>::symbol_nco_word)
        .def("loop_init", &SPUC::sim_qpsk_variable<float>::loop_init, SPUC_sim_qpsk_variable_float_loop_init_overloads_1_2())
        .def("tx_step", &SPUC::sim_qpsk_variable<float>::tx_step)
        .def("rx_step", &SPUC::sim_qpsk_variable<float>::rx_step)
        .def("step", &SPUC::sim_qpsk_variable<float>::step)
        .def("loop_end", &SPUC::sim_qpsk_variable<float>::loop_end)
    ;

}


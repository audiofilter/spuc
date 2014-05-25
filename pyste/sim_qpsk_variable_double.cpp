
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qpsk_variable.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qpsk_variable_double_loop_init_overloads_1_2, loop_init, 1, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qpsk_variable_double)
{
    class_< SPUC::sim_qpsk_variable<double> >("sim_qpsk_variable_double", init<  >())
        .def(init< const SPUC::sim_qpsk_variable<double>& >())
        .def_readwrite("BER_mon", &SPUC::sim_qpsk_variable<double>::BER_mon)
        .def_readwrite("tx_data_source", &SPUC::sim_qpsk_variable<double>::tx_data_source)
        .def_readwrite("freq_offset", &SPUC::sim_qpsk_variable<double>::freq_offset)
        .def_readwrite("n", &SPUC::sim_qpsk_variable<double>::n)
        .def_readwrite("RECEIVER", &SPUC::sim_qpsk_variable<double>::RECEIVER)
        .def_readwrite("num", &SPUC::sim_qpsk_variable<double>::num)
        .def_readwrite("var", &SPUC::sim_qpsk_variable<double>::var)
        .def_readwrite("snr", &SPUC::sim_qpsk_variable<double>::snr)
        .def_readwrite("timing_offset", &SPUC::sim_qpsk_variable<double>::timing_offset)
        .def_readwrite("total_over", &SPUC::sim_qpsk_variable<double>::total_over)
        .def_readwrite("data", &SPUC::sim_qpsk_variable<double>::data)
        .def_readwrite("base", &SPUC::sim_qpsk_variable<double>::base)
        .def_readwrite("main", &SPUC::sim_qpsk_variable<double>::main)
        .def_readwrite("b_noise", &SPUC::sim_qpsk_variable<double>::b_noise)
        .def_readwrite("sum_s", &SPUC::sim_qpsk_variable<double>::sum_s)
        .def_readwrite("sum_n", &SPUC::sim_qpsk_variable<double>::sum_n)
        .def_readwrite("rcv_symbols", &SPUC::sim_qpsk_variable<double>::rcv_symbols)
        .def_readwrite("count", &SPUC::sim_qpsk_variable<double>::count)
        .def_readwrite("dec_rate_log", &SPUC::sim_qpsk_variable<double>::dec_rate_log)
        .def_readwrite("resample_over", &SPUC::sim_qpsk_variable<double>::resample_over)
        .def_readwrite("agc_scale", &SPUC::sim_qpsk_variable<double>::agc_scale)
        .def_readwrite("nominal_scale", &SPUC::sim_qpsk_variable<double>::nominal_scale)
        .def_readwrite("analog_agc", &SPUC::sim_qpsk_variable<double>::analog_agc)
        .def_readwrite("analog_filter_gain", &SPUC::sim_qpsk_variable<double>::analog_filter_gain)
        .def_readwrite("analog_agc_gain", &SPUC::sim_qpsk_variable<double>::analog_agc_gain)
        .def_readwrite("actual_over", &SPUC::sim_qpsk_variable<double>::actual_over)
        .def_readwrite("tx_time_inc", &SPUC::sim_qpsk_variable<double>::tx_time_inc)
        .def_readwrite("rc_delay", &SPUC::sim_qpsk_variable<double>::rc_delay)
        .def_readwrite("symbol_nco_word", &SPUC::sim_qpsk_variable<double>::symbol_nco_word)
        .def("loop_init", &SPUC::sim_qpsk_variable<double>::loop_init, SPUC_sim_qpsk_variable_double_loop_init_overloads_1_2())
        .def("tx_step", &SPUC::sim_qpsk_variable<double>::tx_step)
        .def("rx_step", &SPUC::sim_qpsk_variable<double>::rx_step)
        .def("step", &SPUC::sim_qpsk_variable<double>::step)
        .def("loop_end", &SPUC::sim_qpsk_variable<double>::loop_end)
    ;

}


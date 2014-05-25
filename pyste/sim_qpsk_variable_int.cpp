
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qpsk_variable.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qpsk_variable_int_loop_init_overloads_1_2, loop_init, 1, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qpsk_variable_int)
{
    class_< SPUC::sim_qpsk_variable<int> >("sim_qpsk_variable_int", init<  >())
        .def(init< const SPUC::sim_qpsk_variable<int>& >())
        .def_readwrite("BER_mon", &SPUC::sim_qpsk_variable<int>::BER_mon)
        .def_readwrite("tx_data_source", &SPUC::sim_qpsk_variable<int>::tx_data_source)
        .def_readwrite("freq_offset", &SPUC::sim_qpsk_variable<int>::freq_offset)
        .def_readwrite("n", &SPUC::sim_qpsk_variable<int>::n)
        .def_readwrite("RECEIVER", &SPUC::sim_qpsk_variable<int>::RECEIVER)
        .def_readwrite("num", &SPUC::sim_qpsk_variable<int>::num)
        .def_readwrite("var", &SPUC::sim_qpsk_variable<int>::var)
        .def_readwrite("snr", &SPUC::sim_qpsk_variable<int>::snr)
        .def_readwrite("timing_offset", &SPUC::sim_qpsk_variable<int>::timing_offset)
        .def_readwrite("total_over", &SPUC::sim_qpsk_variable<int>::total_over)
        .def_readwrite("data", &SPUC::sim_qpsk_variable<int>::data)
        .def_readwrite("base", &SPUC::sim_qpsk_variable<int>::base)
        .def_readwrite("main", &SPUC::sim_qpsk_variable<int>::main)
        .def_readwrite("b_noise", &SPUC::sim_qpsk_variable<int>::b_noise)
        .def_readwrite("sum_s", &SPUC::sim_qpsk_variable<int>::sum_s)
        .def_readwrite("sum_n", &SPUC::sim_qpsk_variable<int>::sum_n)
        .def_readwrite("rcv_symbols", &SPUC::sim_qpsk_variable<int>::rcv_symbols)
        .def_readwrite("count", &SPUC::sim_qpsk_variable<int>::count)
        .def_readwrite("dec_rate_log", &SPUC::sim_qpsk_variable<int>::dec_rate_log)
        .def_readwrite("resample_over", &SPUC::sim_qpsk_variable<int>::resample_over)
        .def_readwrite("agc_scale", &SPUC::sim_qpsk_variable<int>::agc_scale)
        .def_readwrite("nominal_scale", &SPUC::sim_qpsk_variable<int>::nominal_scale)
        .def_readwrite("analog_agc", &SPUC::sim_qpsk_variable<int>::analog_agc)
        .def_readwrite("analog_filter_gain", &SPUC::sim_qpsk_variable<int>::analog_filter_gain)
        .def_readwrite("analog_agc_gain", &SPUC::sim_qpsk_variable<int>::analog_agc_gain)
        .def_readwrite("actual_over", &SPUC::sim_qpsk_variable<int>::actual_over)
        .def_readwrite("tx_time_inc", &SPUC::sim_qpsk_variable<int>::tx_time_inc)
        .def_readwrite("rc_delay", &SPUC::sim_qpsk_variable<int>::rc_delay)
        .def_readwrite("symbol_nco_word", &SPUC::sim_qpsk_variable<int>::symbol_nco_word)
        .def("loop_init", &SPUC::sim_qpsk_variable<int>::loop_init, SPUC_sim_qpsk_variable_int_loop_init_overloads_1_2())
        .def("tx_step", &SPUC::sim_qpsk_variable<int>::tx_step)
        .def("rx_step", &SPUC::sim_qpsk_variable<int>::rx_step)
        .def("step", &SPUC::sim_qpsk_variable<int>::step)
        .def("loop_end", &SPUC::sim_qpsk_variable<int>::loop_end)
    ;

}


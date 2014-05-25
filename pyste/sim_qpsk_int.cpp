
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qpsk.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qpsk_int_loop_init_overloads_1_3, loop_init, 1, 3)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qpsk_int)
{
    class_< SPUC::sim_qpsk<int> >("sim_qpsk_int", init<  >())
        .def(init< const SPUC::sim_qpsk<int>& >())
        .def_readwrite("BER_mon", &SPUC::sim_qpsk<int>::BER_mon)
        .def_readwrite("tx_data_source", &SPUC::sim_qpsk<int>::tx_data_source)
        .def_readwrite("freq_offset", &SPUC::sim_qpsk<int>::freq_offset)
        .def_readwrite("n", &SPUC::sim_qpsk<int>::n)
        .def_readwrite("RECEIVER", &SPUC::sim_qpsk<int>::RECEIVER)
        .def_readwrite("ADC", &SPUC::sim_qpsk<int>::ADC)
        .def_readwrite("num", &SPUC::sim_qpsk<int>::num)
        .def_readwrite("var", &SPUC::sim_qpsk<int>::var)
        .def_readwrite("snr", &SPUC::sim_qpsk<int>::snr)
        .def_readwrite("timing_offset", &SPUC::sim_qpsk<int>::timing_offset)
        .def_readwrite("total_over", &SPUC::sim_qpsk<int>::total_over)
        .def_readwrite("base", &SPUC::sim_qpsk<int>::base)
        .def_readwrite("main", &SPUC::sim_qpsk<int>::main)
        .def_readwrite("b_noise", &SPUC::sim_qpsk<int>::b_noise)
        .def_readwrite("adc_out", &SPUC::sim_qpsk<int>::adc_out)
        .def_readwrite("rcv_symbols", &SPUC::sim_qpsk<int>::rcv_symbols)
        .def_readwrite("count", &SPUC::sim_qpsk<int>::count)
        .def_readwrite("resample_over", &SPUC::sim_qpsk<int>::resample_over)
        .def_readwrite("nominal_scale", &SPUC::sim_qpsk<int>::nominal_scale)
        .def_readwrite("actual_over", &SPUC::sim_qpsk<int>::actual_over)
        .def_readwrite("tx_time_inc", &SPUC::sim_qpsk<int>::tx_time_inc)
        .def_readwrite("rc_delay", &SPUC::sim_qpsk<int>::rc_delay)
        .def_readwrite("symbol_nco_word", &SPUC::sim_qpsk<int>::symbol_nco_word)
        .def_readwrite("time", &SPUC::sim_qpsk<int>::time)
        .def_readwrite("freq", &SPUC::sim_qpsk<int>::freq)
        .def("loop_init", &SPUC::sim_qpsk<int>::loop_init, SPUC_sim_qpsk_int_loop_init_overloads_1_3())
        .def("tx_step", &SPUC::sim_qpsk<int>::tx_step)
        .def("step", &SPUC::sim_qpsk<int>::step)
        .def("rx_step", &SPUC::sim_qpsk<int>::rx_step)
        .def("loop_end", &SPUC::sim_qpsk<int>::loop_end)
    ;

}


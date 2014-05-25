
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qpsk.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qpsk_float_loop_init_overloads_1_3, loop_init, 1, 3)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qpsk_float)
{
    class_< SPUC::sim_qpsk<float> >("sim_qpsk_float", init<  >())
        .def(init< const SPUC::sim_qpsk<float>& >())
        .def_readwrite("BER_mon", &SPUC::sim_qpsk<float>::BER_mon)
        .def_readwrite("tx_data_source", &SPUC::sim_qpsk<float>::tx_data_source)
        .def_readwrite("freq_offset", &SPUC::sim_qpsk<float>::freq_offset)
        .def_readwrite("n", &SPUC::sim_qpsk<float>::n)
        .def_readwrite("RECEIVER", &SPUC::sim_qpsk<float>::RECEIVER)
        .def_readwrite("ADC", &SPUC::sim_qpsk<float>::ADC)
        .def_readwrite("num", &SPUC::sim_qpsk<float>::num)
        .def_readwrite("var", &SPUC::sim_qpsk<float>::var)
        .def_readwrite("snr", &SPUC::sim_qpsk<float>::snr)
        .def_readwrite("timing_offset", &SPUC::sim_qpsk<float>::timing_offset)
        .def_readwrite("total_over", &SPUC::sim_qpsk<float>::total_over)
        .def_readwrite("base", &SPUC::sim_qpsk<float>::base)
        .def_readwrite("main", &SPUC::sim_qpsk<float>::main)
        .def_readwrite("b_noise", &SPUC::sim_qpsk<float>::b_noise)
        .def_readwrite("adc_out", &SPUC::sim_qpsk<float>::adc_out)
        .def_readwrite("rcv_symbols", &SPUC::sim_qpsk<float>::rcv_symbols)
        .def_readwrite("count", &SPUC::sim_qpsk<float>::count)
        .def_readwrite("resample_over", &SPUC::sim_qpsk<float>::resample_over)
        .def_readwrite("nominal_scale", &SPUC::sim_qpsk<float>::nominal_scale)
        .def_readwrite("actual_over", &SPUC::sim_qpsk<float>::actual_over)
        .def_readwrite("tx_time_inc", &SPUC::sim_qpsk<float>::tx_time_inc)
        .def_readwrite("rc_delay", &SPUC::sim_qpsk<float>::rc_delay)
        .def_readwrite("symbol_nco_word", &SPUC::sim_qpsk<float>::symbol_nco_word)
        .def_readwrite("time", &SPUC::sim_qpsk<float>::time)
        .def_readwrite("freq", &SPUC::sim_qpsk<float>::freq)
        .def("loop_init", &SPUC::sim_qpsk<float>::loop_init, SPUC_sim_qpsk_float_loop_init_overloads_1_3())
        .def("tx_step", &SPUC::sim_qpsk<float>::tx_step)
        .def("step", &SPUC::sim_qpsk<float>::step)
        .def("rx_step", &SPUC::sim_qpsk<float>::rx_step)
        .def("loop_end", &SPUC::sim_qpsk<float>::loop_end)
    ;

}


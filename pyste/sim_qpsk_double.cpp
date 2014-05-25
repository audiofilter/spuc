
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qpsk.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qpsk_double_loop_init_overloads_1_3, loop_init, 1, 3)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qpsk_double)
{
    class_< SPUC::sim_qpsk<double> >("sim_qpsk_double", init<  >())
        .def(init< const SPUC::sim_qpsk<double>& >())
        .def_readwrite("BER_mon", &SPUC::sim_qpsk<double>::BER_mon)
        .def_readwrite("tx_data_source", &SPUC::sim_qpsk<double>::tx_data_source)
        .def_readwrite("freq_offset", &SPUC::sim_qpsk<double>::freq_offset)
        .def_readwrite("n", &SPUC::sim_qpsk<double>::n)
        .def_readwrite("RECEIVER", &SPUC::sim_qpsk<double>::RECEIVER)
        .def_readwrite("ADC", &SPUC::sim_qpsk<double>::ADC)
        .def_readwrite("num", &SPUC::sim_qpsk<double>::num)
        .def_readwrite("var", &SPUC::sim_qpsk<double>::var)
        .def_readwrite("snr", &SPUC::sim_qpsk<double>::snr)
        .def_readwrite("timing_offset", &SPUC::sim_qpsk<double>::timing_offset)
        .def_readwrite("total_over", &SPUC::sim_qpsk<double>::total_over)
        .def_readwrite("base", &SPUC::sim_qpsk<double>::base)
        .def_readwrite("main", &SPUC::sim_qpsk<double>::main)
        .def_readwrite("b_noise", &SPUC::sim_qpsk<double>::b_noise)
        .def_readwrite("adc_out", &SPUC::sim_qpsk<double>::adc_out)
        .def_readwrite("rcv_symbols", &SPUC::sim_qpsk<double>::rcv_symbols)
        .def_readwrite("count", &SPUC::sim_qpsk<double>::count)
        .def_readwrite("resample_over", &SPUC::sim_qpsk<double>::resample_over)
        .def_readwrite("nominal_scale", &SPUC::sim_qpsk<double>::nominal_scale)
        .def_readwrite("actual_over", &SPUC::sim_qpsk<double>::actual_over)
        .def_readwrite("tx_time_inc", &SPUC::sim_qpsk<double>::tx_time_inc)
        .def_readwrite("rc_delay", &SPUC::sim_qpsk<double>::rc_delay)
        .def_readwrite("symbol_nco_word", &SPUC::sim_qpsk<double>::symbol_nco_word)
        .def_readwrite("time", &SPUC::sim_qpsk<double>::time)
        .def_readwrite("freq", &SPUC::sim_qpsk<double>::freq)
        .def("loop_init", &SPUC::sim_qpsk<double>::loop_init, SPUC_sim_qpsk_double_loop_init_overloads_1_3())
        .def("tx_step", &SPUC::sim_qpsk<double>::tx_step)
        .def("step", &SPUC::sim_qpsk<double>::step)
        .def("rx_step", &SPUC::sim_qpsk<double>::rx_step)
        .def("loop_end", &SPUC::sim_qpsk<double>::loop_end)
    ;

}


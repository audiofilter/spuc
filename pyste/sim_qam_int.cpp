
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qam.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qam_int_loop_init_overloads_2_4, loop_init, 2, 4)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qam_int)
{
    class_< SPUC::sim_qam<int> >("sim_qam_int", init< const SPUC::sim_qam<int>& >())
        .def(init< optional< float > >())
        .def_readonly("over", &SPUC::sim_qam<int>::over)
        .def_readwrite("alpha", &SPUC::sim_qam<int>::alpha)
        .def_readwrite("interp", &SPUC::sim_qam<int>::interp)
        .def_readwrite("rx_filter", &SPUC::sim_qam<int>::rx_filter)
        .def_readwrite("TX", &SPUC::sim_qam<int>::TX)
        .def_readwrite("n", &SPUC::sim_qam<int>::n)
        .def_readwrite("DUT", &SPUC::sim_qam<int>::DUT)
        .def_readwrite("freq_offset", &SPUC::sim_qam<int>::freq_offset)
        .def_readwrite("ADC", &SPUC::sim_qam<int>::ADC)
        .def_readwrite("var", &SPUC::sim_qam<int>::var)
        .def_readwrite("snr", &SPUC::sim_qam<int>::snr)
        .def_readwrite("channel_pwr", &SPUC::sim_qam<int>::channel_pwr)
        .def_readwrite("tx_data", &SPUC::sim_qam<int>::tx_data)
        .def_readwrite("data", &SPUC::sim_qam<int>::data)
        .def_readwrite("output_delay", &SPUC::sim_qam<int>::output_delay)
        .def_readwrite("rate", &SPUC::sim_qam<int>::rate)
        .def_readwrite("enable_freq_offset", &SPUC::sim_qam<int>::enable_freq_offset)
        .def_readwrite("enable_time_offset", &SPUC::sim_qam<int>::enable_time_offset)
        .def_readwrite("carrier_offset_rate", &SPUC::sim_qam<int>::carrier_offset_rate)
        .def_readwrite("time_inc", &SPUC::sim_qam<int>::time_inc)
        .def_readwrite("time_offset", &SPUC::sim_qam<int>::time_offset)
        .def_readwrite("adc_out", &SPUC::sim_qam<int>::adc_out)
        .def_readwrite("base", &SPUC::sim_qam<int>::base)
        .def_readwrite("main", &SPUC::sim_qam<int>::main)
        .def_readwrite("main1", &SPUC::sim_qam<int>::main1)
        .def_readwrite("base1", &SPUC::sim_qam<int>::base1)
        .def_readwrite("b_noise", &SPUC::sim_qam<int>::b_noise)
        .def_readwrite("rcv_symbols", &SPUC::sim_qam<int>::rcv_symbols)
        .def_readwrite("tx_symbols", &SPUC::sim_qam<int>::tx_symbols)
        .def_readwrite("count", &SPUC::sim_qam<int>::count)
        .def_readwrite("phase_inc", &SPUC::sim_qam<int>::phase_inc)
        .def_readwrite("phase_acc", &SPUC::sim_qam<int>::phase_acc)
        .def("loop_init", &SPUC::sim_qam<int>::loop_init, SPUC_sim_qam_int_loop_init_overloads_2_4())
        .def("tx_step", &SPUC::sim_qam<int>::tx_step)
        .def("step", &SPUC::sim_qam<int>::step)
        .def("rx_step", &SPUC::sim_qam<int>::rx_step)
        .def("loop_end", &SPUC::sim_qam<int>::loop_end)
    ;

}


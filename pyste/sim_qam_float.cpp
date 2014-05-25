
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qam.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qam_float_loop_init_overloads_2_4, loop_init, 2, 4)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qam_float)
{
    class_< SPUC::sim_qam<float> >("sim_qam_float", init< const SPUC::sim_qam<float>& >())
        .def(init< optional< float > >())
        .def_readonly("over", &SPUC::sim_qam<float>::over)
        .def_readwrite("alpha", &SPUC::sim_qam<float>::alpha)
        .def_readwrite("interp", &SPUC::sim_qam<float>::interp)
        .def_readwrite("rx_filter", &SPUC::sim_qam<float>::rx_filter)
        .def_readwrite("TX", &SPUC::sim_qam<float>::TX)
        .def_readwrite("n", &SPUC::sim_qam<float>::n)
        .def_readwrite("DUT", &SPUC::sim_qam<float>::DUT)
        .def_readwrite("freq_offset", &SPUC::sim_qam<float>::freq_offset)
        .def_readwrite("ADC", &SPUC::sim_qam<float>::ADC)
        .def_readwrite("var", &SPUC::sim_qam<float>::var)
        .def_readwrite("snr", &SPUC::sim_qam<float>::snr)
        .def_readwrite("channel_pwr", &SPUC::sim_qam<float>::channel_pwr)
        .def_readwrite("tx_data", &SPUC::sim_qam<float>::tx_data)
        .def_readwrite("data", &SPUC::sim_qam<float>::data)
        .def_readwrite("output_delay", &SPUC::sim_qam<float>::output_delay)
        .def_readwrite("rate", &SPUC::sim_qam<float>::rate)
        .def_readwrite("enable_freq_offset", &SPUC::sim_qam<float>::enable_freq_offset)
        .def_readwrite("enable_time_offset", &SPUC::sim_qam<float>::enable_time_offset)
        .def_readwrite("carrier_offset_rate", &SPUC::sim_qam<float>::carrier_offset_rate)
        .def_readwrite("time_inc", &SPUC::sim_qam<float>::time_inc)
        .def_readwrite("time_offset", &SPUC::sim_qam<float>::time_offset)
        .def_readwrite("adc_out", &SPUC::sim_qam<float>::adc_out)
        .def_readwrite("base", &SPUC::sim_qam<float>::base)
        .def_readwrite("main", &SPUC::sim_qam<float>::main)
        .def_readwrite("main1", &SPUC::sim_qam<float>::main1)
        .def_readwrite("base1", &SPUC::sim_qam<float>::base1)
        .def_readwrite("b_noise", &SPUC::sim_qam<float>::b_noise)
        .def_readwrite("rcv_symbols", &SPUC::sim_qam<float>::rcv_symbols)
        .def_readwrite("tx_symbols", &SPUC::sim_qam<float>::tx_symbols)
        .def_readwrite("count", &SPUC::sim_qam<float>::count)
        .def_readwrite("phase_inc", &SPUC::sim_qam<float>::phase_inc)
        .def_readwrite("phase_acc", &SPUC::sim_qam<float>::phase_acc)
        .def("loop_init", &SPUC::sim_qam<float>::loop_init, SPUC_sim_qam_float_loop_init_overloads_2_4())
        .def("tx_step", &SPUC::sim_qam<float>::tx_step)
        .def("step", &SPUC::sim_qam<float>::step)
        .def("rx_step", &SPUC::sim_qam<float>::rx_step)
        .def("loop_end", &SPUC::sim_qam<float>::loop_end)
    ;

}


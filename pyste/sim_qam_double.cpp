
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sim_qam.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_sim_qam_double_loop_init_overloads_2_4, loop_init, 2, 4)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(sim_qam_double)
{
    class_< SPUC::sim_qam<double> >("sim_qam_double", init< const SPUC::sim_qam<double>& >())
        .def(init< optional< SPUC::float_type > >())
        .def_readonly("over", &SPUC::sim_qam<double>::over)
        .def_readwrite("alpha", &SPUC::sim_qam<double>::alpha)
        .def_readwrite("interp", &SPUC::sim_qam<double>::interp)
        .def_readwrite("rx_filter", &SPUC::sim_qam<double>::rx_filter)
        .def_readwrite("TX", &SPUC::sim_qam<double>::TX)
        .def_readwrite("n", &SPUC::sim_qam<double>::n)
        .def_readwrite("DUT", &SPUC::sim_qam<double>::DUT)
        .def_readwrite("freq_offset", &SPUC::sim_qam<double>::freq_offset)
        .def_readwrite("ADC", &SPUC::sim_qam<double>::ADC)
        .def_readwrite("var", &SPUC::sim_qam<double>::var)
        .def_readwrite("snr", &SPUC::sim_qam<double>::snr)
        .def_readwrite("channel_pwr", &SPUC::sim_qam<double>::channel_pwr)
        .def_readwrite("tx_data", &SPUC::sim_qam<double>::tx_data)
        .def_readwrite("data", &SPUC::sim_qam<double>::data)
        .def_readwrite("output_delay", &SPUC::sim_qam<double>::output_delay)
        .def_readwrite("rate", &SPUC::sim_qam<double>::rate)
        .def_readwrite("enable_freq_offset", &SPUC::sim_qam<double>::enable_freq_offset)
        .def_readwrite("enable_time_offset", &SPUC::sim_qam<double>::enable_time_offset)
        .def_readwrite("carrier_offset_rate", &SPUC::sim_qam<double>::carrier_offset_rate)
        .def_readwrite("time_inc", &SPUC::sim_qam<double>::time_inc)
        .def_readwrite("time_offset", &SPUC::sim_qam<double>::time_offset)
        .def_readwrite("adc_out", &SPUC::sim_qam<double>::adc_out)
        .def_readwrite("base", &SPUC::sim_qam<double>::base)
        .def_readwrite("main", &SPUC::sim_qam<double>::main)
        .def_readwrite("main1", &SPUC::sim_qam<double>::main1)
        .def_readwrite("base1", &SPUC::sim_qam<double>::base1)
        .def_readwrite("b_noise", &SPUC::sim_qam<double>::b_noise)
        .def_readwrite("rcv_symbols", &SPUC::sim_qam<double>::rcv_symbols)
        .def_readwrite("tx_symbols", &SPUC::sim_qam<double>::tx_symbols)
        .def_readwrite("count", &SPUC::sim_qam<double>::count)
        .def_readwrite("phase_inc", &SPUC::sim_qam<double>::phase_inc)
        .def_readwrite("phase_acc", &SPUC::sim_qam<double>::phase_acc)
        .def("loop_init", &SPUC::sim_qam<double>::loop_init, SPUC_sim_qam_double_loop_init_overloads_2_4())
        .def("tx_step", &SPUC::sim_qam<double>::tx_step)
        .def("step", &SPUC::sim_qam<double>::step)
        .def("rx_step", &SPUC::sim_qam<double>::rx_step)
        .def("loop_end", &SPUC::sim_qam<double>::loop_end)
    ;

}


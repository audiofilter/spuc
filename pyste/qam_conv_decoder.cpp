
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qam_conv_decoder.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qam_conv_decoder)
{
    class_< SPUC::qam_conv_decoder >("qam_conv_decoder", init< const SPUC::qam_conv_decoder& >())
        .def(init< int >())
        .def_readonly("Max_bits_per_symbol", &SPUC::qam_conv_decoder::Max_bits_per_symbol)
        .def_readonly("soft_decision_level", &SPUC::qam_conv_decoder::soft_decision_level)
        .def_readwrite("viterbi_decoder", &SPUC::qam_conv_decoder::viterbi_decoder)
        .def_readwrite("viterbi_input", &SPUC::qam_conv_decoder::viterbi_input)
        .def_readwrite("enc_rate", &SPUC::qam_conv_decoder::enc_rate)
        .def_readwrite("rate_index", &SPUC::qam_conv_decoder::rate_index)
        .def_readwrite("soft_bit_counter", &SPUC::qam_conv_decoder::soft_bit_counter)
        .def_readwrite("rx_bits_per_symbol", &SPUC::qam_conv_decoder::rx_bits_per_symbol)
        .def_readwrite("raw_bits_this_frame", &SPUC::qam_conv_decoder::raw_bits_this_frame)
        .def_readwrite("coded_bits_per_frame", &SPUC::qam_conv_decoder::coded_bits_per_frame)
        .def_readwrite("raw_bits_out", &SPUC::qam_conv_decoder::raw_bits_out)
        .def_readwrite("sample", &SPUC::qam_conv_decoder::sample)
        .def_readwrite("serial", &SPUC::qam_conv_decoder::serial)
        .def_readwrite("frame_ready", &SPUC::qam_conv_decoder::frame_ready)
        .def_readwrite("viterbi_ready", &SPUC::qam_conv_decoder::viterbi_ready)
        .def_readwrite("viterbi_data", &SPUC::qam_conv_decoder::viterbi_data)
        .def_readwrite("output_buffer_empty", &SPUC::qam_conv_decoder::output_buffer_empty)
        .def_readwrite("no_conv", &SPUC::qam_conv_decoder::no_conv)
        .def("reset", &SPUC::qam_conv_decoder::reset)
        .def("set_rate", &SPUC::qam_conv_decoder::set_rate)
        .def("data_decode", &SPUC::qam_conv_decoder::data_decode)
        .def("get_bit", &SPUC::qam_conv_decoder::get_bit)
        .def("clear_soft_decision", &SPUC::qam_conv_decoder::clear_soft_decision)
    ;

}


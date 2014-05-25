
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/ofdm_data_encoder.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(ofdm_data_encoder)
{
    class_< SPUC::ofdm_data_encoder >("ofdm_data_encoder", init< const SPUC::ofdm_data_encoder& >())
        .def(init< int, int, int, int >())
        .def_readwrite("CONV", &SPUC::ofdm_data_encoder::CONV)
        .def_readwrite("QAM", &SPUC::ofdm_data_encoder::QAM)
        .def_readwrite("rate_index", &SPUC::ofdm_data_encoder::rate_index)
        .def_readwrite("enc_rate", &SPUC::ofdm_data_encoder::enc_rate)
        .def_readwrite("tx_bits_per_symbol", &SPUC::ofdm_data_encoder::tx_bits_per_symbol)
        .def_readwrite("total_bits", &SPUC::ofdm_data_encoder::total_bits)
        .def_readwrite("number_symbols", &SPUC::ofdm_data_encoder::number_symbols)
        .def_readwrite("frame", &SPUC::ofdm_data_encoder::frame)
        .def_readwrite("serial", &SPUC::ofdm_data_encoder::serial)
        .def_readwrite("sample", &SPUC::ofdm_data_encoder::sample)
        .def_readwrite("data_index", &SPUC::ofdm_data_encoder::data_index)
        .def_readwrite("raw_bit", &SPUC::ofdm_data_encoder::raw_bit)
        .def_readonly("Carriers", &SPUC::ofdm_data_encoder::Carriers)
        .def_readwrite("raw_data", &SPUC::ofdm_data_encoder::raw_data)
        .def_readwrite("interleaver_in", &SPUC::ofdm_data_encoder::interleaver_in)
        .def_readwrite("interleaved", &SPUC::ofdm_data_encoder::interleaved)
        .def_readwrite("interleaver_out", &SPUC::ofdm_data_encoder::interleaver_out)
        .def_readwrite("pre_mod", &SPUC::ofdm_data_encoder::pre_mod)
        .def_readwrite("coded_bits_per_frame", &SPUC::ofdm_data_encoder::coded_bits_per_frame)
        .def_readwrite("raw_bits_this_frame", &SPUC::ofdm_data_encoder::raw_bits_this_frame)
        .def_readwrite("no_conv", &SPUC::ofdm_data_encoder::no_conv)
        .def("tx_burst_size", &SPUC::ofdm_data_encoder::tx_burst_size)
        .def("reset", &SPUC::ofdm_data_encoder::reset)
        .def("set_rate", &SPUC::ofdm_data_encoder::set_rate)
        .def("data_map", &SPUC::ofdm_data_encoder::data_map)
        .def("get_data_frame", &SPUC::ofdm_data_encoder::get_data_frame)
        .def("serial_to_word_input", &SPUC::ofdm_data_encoder::serial_to_word_input)
        .def("serial_to_word_output", &SPUC::ofdm_data_encoder::serial_to_word_output)
    ;

}


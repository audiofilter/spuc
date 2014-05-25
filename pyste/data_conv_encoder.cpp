
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/data_conv_encoder.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(data_conv_encoder)
{
    class_< SPUC::data_conv_encoder >("data_conv_encoder", init< const SPUC::data_conv_encoder& >())
        .def(init< int, int >())
        .def_readwrite("test_pn", &SPUC::data_conv_encoder::test_pn)
        .def_readwrite("g1", &SPUC::data_conv_encoder::g1)
        .def_readwrite("g2", &SPUC::data_conv_encoder::g2)
        .def_readwrite("conv_enc_phase", &SPUC::data_conv_encoder::conv_enc_phase)
        .def_readwrite("conv_enc_get_bit", &SPUC::data_conv_encoder::conv_enc_get_bit)
        .def_readwrite("conv_enc_u", &SPUC::data_conv_encoder::conv_enc_u)
        .def_readwrite("conv_bit_number", &SPUC::data_conv_encoder::conv_bit_number)
        .def_readwrite("rate_index", &SPUC::data_conv_encoder::rate_index)
        .def_readwrite("enc_rate", &SPUC::data_conv_encoder::enc_rate)
        .def_readwrite("total_bits", &SPUC::data_conv_encoder::total_bits)
        .def_readwrite("number_symbols", &SPUC::data_conv_encoder::number_symbols)
        .def_readwrite("frame", &SPUC::data_conv_encoder::frame)
        .def_readwrite("serial", &SPUC::data_conv_encoder::serial)
        .def_readwrite("sample", &SPUC::data_conv_encoder::sample)
        .def_readwrite("data_index", &SPUC::data_conv_encoder::data_index)
        .def_readwrite("raw_bit", &SPUC::data_conv_encoder::raw_bit)
        .def_readwrite("raw_data", &SPUC::data_conv_encoder::raw_data)
        .def_readwrite("pre_mod", &SPUC::data_conv_encoder::pre_mod)
        .def_readwrite("raw_bits_this_frame", &SPUC::data_conv_encoder::raw_bits_this_frame)
        .def_readwrite("no_conv", &SPUC::data_conv_encoder::no_conv)
        .def("reset", &SPUC::data_conv_encoder::reset)
        .def("set_rate", &SPUC::data_conv_encoder::set_rate)
        .def("conv_encoder", &SPUC::data_conv_encoder::conv_encoder)
        .def("serial_to_word_input", &SPUC::data_conv_encoder::serial_to_word_input)
        .def("serial_to_word_output", &SPUC::data_conv_encoder::serial_to_word_output)
        .def("get_data", &SPUC::data_conv_encoder::get_data)
    ;

}


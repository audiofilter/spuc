
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/dvb_conv_encoder.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(dvb_conv_encoder)
{
    class_< SPUC::dvb_conv_encoder >("dvb_conv_encoder", init<  >())
        .def(init< const SPUC::dvb_conv_encoder& >())
        .def_readwrite("test_pn", &SPUC::dvb_conv_encoder::test_pn)
        .def_readonly("g1", &SPUC::dvb_conv_encoder::g1)
        .def_readonly("g2", &SPUC::dvb_conv_encoder::g2)
        .def_readwrite("conv_enc_phase", &SPUC::dvb_conv_encoder::conv_enc_phase)
        .def_readwrite("conv_enc_get_bit", &SPUC::dvb_conv_encoder::conv_enc_get_bit)
        .def_readwrite("conv_enc_u", &SPUC::dvb_conv_encoder::conv_enc_u)
        .def_readwrite("conv_bit_number", &SPUC::dvb_conv_encoder::conv_bit_number)
        .def_readwrite("raw_bit", &SPUC::dvb_conv_encoder::raw_bit)
        .def("reset", &SPUC::dvb_conv_encoder::reset)
        .def("clock", &SPUC::dvb_conv_encoder::clock)
        .def("get_data", &SPUC::dvb_conv_encoder::get_data)
        .def("reduce", &SPUC::dvb_conv_encoder::reduce)
    ;

}


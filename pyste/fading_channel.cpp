
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fading_channel.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fading_channel)
{
    class_< SPUC::fading_channel >("fading_channel", init< const SPUC::fading_channel& >())
        .def(init< optional< long int, SPUC::float_type > >())
        .def_readwrite("exp_decay", &SPUC::fading_channel::exp_decay)
        .def_readwrite("taps", &SPUC::fading_channel::taps)
        .def_readwrite("delay_spread", &SPUC::fading_channel::delay_spread)
        .def_readwrite("tap_gain", &SPUC::fading_channel::tap_gain)
        .def("setup", &SPUC::fading_channel::setup)
        .def("generate_channel", &SPUC::fading_channel::generate_channel)
        .def("update", &SPUC::fading_channel::update)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qam_tx.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qam_tx_float)
{
    class_< SPUC::qam_tx<float> >("qam_tx_float", init< const SPUC::qam_tx<float>& >())
        .def(init< optional< long int, long int, long int, long int, float > >())
        .def_readwrite("alpha", &SPUC::qam_tx<float>::alpha)
        .def_readwrite("training_source", &SPUC::qam_tx<float>::training_source)
        .def_readwrite("ENC", &SPUC::qam_tx<float>::ENC)
        .def_readwrite("tx_filter", &SPUC::qam_tx<float>::tx_filter)
        .def_readwrite("preamble_source", &SPUC::qam_tx<float>::preamble_source)
        .def_readwrite("tx_data", &SPUC::qam_tx<float>::tx_data)
        .def_readwrite("data_level", &SPUC::qam_tx<float>::data_level)
        .def_readwrite("preamble_pn", &SPUC::qam_tx<float>::preamble_pn)
        .def_readwrite("training_interval", &SPUC::qam_tx<float>::training_interval)
        .def_readwrite("tx_symbols", &SPUC::qam_tx<float>::tx_symbols)
        .def_readwrite("over", &SPUC::qam_tx<float>::over)
        .def_readwrite("training_scale", &SPUC::qam_tx<float>::training_scale)
        .def_readwrite("count", &SPUC::qam_tx<float>::count)
        .def_readwrite("rate", &SPUC::qam_tx<float>::rate)
        .def("loop_init", &SPUC::qam_tx<float>::loop_init)
        .def("clock", &SPUC::qam_tx<float>::clock)
    ;

}


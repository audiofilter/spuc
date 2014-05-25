
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qam_tx.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qam_tx_double)
{
    class_< SPUC::qam_tx<double> >("qam_tx_double", init< const SPUC::qam_tx<double>& >())
        .def(init< optional< long int, long int, long int, long int, SPUC::float_type > >())
        .def_readwrite("alpha", &SPUC::qam_tx<double>::alpha)
        .def_readwrite("training_source", &SPUC::qam_tx<double>::training_source)
        .def_readwrite("ENC", &SPUC::qam_tx<double>::ENC)
        .def_readwrite("tx_filter", &SPUC::qam_tx<double>::tx_filter)
        .def_readwrite("preamble_source", &SPUC::qam_tx<double>::preamble_source)
        .def_readwrite("tx_data", &SPUC::qam_tx<double>::tx_data)
        .def_readwrite("data_level", &SPUC::qam_tx<double>::data_level)
        .def_readwrite("preamble_pn", &SPUC::qam_tx<double>::preamble_pn)
        .def_readwrite("training_interval", &SPUC::qam_tx<double>::training_interval)
        .def_readwrite("tx_symbols", &SPUC::qam_tx<double>::tx_symbols)
        .def_readwrite("over", &SPUC::qam_tx<double>::over)
        .def_readwrite("training_scale", &SPUC::qam_tx<double>::training_scale)
        .def_readwrite("count", &SPUC::qam_tx<double>::count)
        .def_readwrite("rate", &SPUC::qam_tx<double>::rate)
        .def("loop_init", &SPUC::qam_tx<double>::loop_init)
        .def("clock", &SPUC::qam_tx<double>::clock)
    ;

}


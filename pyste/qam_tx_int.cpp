
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qam_tx.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qam_tx_int)
{
    class_< SPUC::qam_tx<int> >("qam_tx_int", init< const SPUC::qam_tx<int>& >())
        .def(init< optional< long int, long int, long int, long int, float > >())
        .def_readwrite("alpha", &SPUC::qam_tx<int>::alpha)
        .def_readwrite("training_source", &SPUC::qam_tx<int>::training_source)
        .def_readwrite("ENC", &SPUC::qam_tx<int>::ENC)
        .def_readwrite("tx_filter", &SPUC::qam_tx<int>::tx_filter)
        .def_readwrite("preamble_source", &SPUC::qam_tx<int>::preamble_source)
        .def_readwrite("tx_data", &SPUC::qam_tx<int>::tx_data)
        .def_readwrite("data_level", &SPUC::qam_tx<int>::data_level)
        .def_readwrite("preamble_pn", &SPUC::qam_tx<int>::preamble_pn)
        .def_readwrite("training_interval", &SPUC::qam_tx<int>::training_interval)
        .def_readwrite("tx_symbols", &SPUC::qam_tx<int>::tx_symbols)
        .def_readwrite("over", &SPUC::qam_tx<int>::over)
        .def_readwrite("training_scale", &SPUC::qam_tx<int>::training_scale)
        .def_readwrite("count", &SPUC::qam_tx<int>::count)
        .def_readwrite("rate", &SPUC::qam_tx<int>::rate)
        .def("loop_init", &SPUC::qam_tx<int>::loop_init)
        .def("clock", &SPUC::qam_tx<int>::clock)
    ;

}


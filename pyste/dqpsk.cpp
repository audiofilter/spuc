
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/dqpsk.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(dqpsk)
{
    class_< SPUC::dqpsk >("dqpsk", init<  >())
        .def(init< const SPUC::dqpsk& >())
        .def_readwrite("datbase", &SPUC::dqpsk::datbase)
        .def_readwrite("previous_encoded_symbol", &SPUC::dqpsk::previous_encoded_symbol)
        .def_readwrite("previous_decoded_symbol", &SPUC::dqpsk::previous_decoded_symbol)
        .def("encode", &SPUC::dqpsk::encode)
        .def("decode", &SPUC::dqpsk::decode)
        .def("convbits", &SPUC::dqpsk::convbits)
        .def("qpsk_sym", &SPUC::dqpsk::qpsk_sym)
    ;

}


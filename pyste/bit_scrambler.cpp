
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/bit_scrambler.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(bit_scrambler)
{
    class_< SPUC::bit_scrambler >("bit_scrambler", init< const SPUC::bit_scrambler& >())
        .def(init< optional< long int, long int, long int > >())
        .def_readwrite("g", &SPUC::bit_scrambler::g)
        .def_readwrite("span", &SPUC::bit_scrambler::span)
        .def_readwrite("u", &SPUC::bit_scrambler::u)
        .def("reset", &SPUC::bit_scrambler::reset)
        .def("scramble", &SPUC::bit_scrambler::scramble)
        .def("xor_bits", &SPUC::bit_scrambler::xor_bits)
    ;

}


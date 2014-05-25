
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/bit.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(bit)
{
    class_< SPUC::bit >("bit", init<  >())
        .def(init< const SPUC::bit& >())
        .def(init< int >())
        .def("value", &SPUC::bit::value)
        .def( self /= self )
        .def( self |= self )
        .def( self += self )
        .def( self ^= self )
        .def( self -= self )
        .def( self *= self )
        .def( self &= self )
        .def( self + self )
        .def( self ^ self )
        .def( self - self )
        .def( -self )
        .def( self & self )
        .def( !self )
        .def( ~self )
        .def( self | self )
        .def( self == self )
        .def( self == other< int >() )
        .def( self != self )
        .def( self != other< int >() )
        .def("to_short_int", &SPUC::bit::operator short int)
        .def("__int__", &SPUC::bit::operator int)
        .def("to_bool", &SPUC::bit::operator bool)
        .def("__float__", &SPUC::bit::operator float)
        .def("__float__", &SPUC::bit::operator double)
    ;

}


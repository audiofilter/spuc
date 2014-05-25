
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/a_d.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(a_d)
{
    class_< SPUC::a_d >("a_d", init< const SPUC::a_d& >())
        .def(init< optional< char > >())
        .def("clock", (long int (SPUC::a_d::*)(SPUC::float_type) )&SPUC::a_d::clock)
        .def("clock", (SPUC::complex<long int> (SPUC::a_d::*)(SPUC::complex<double>) )&SPUC::a_d::clock)
    ;

}


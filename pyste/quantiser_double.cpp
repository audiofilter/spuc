
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/quantiser.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(quantiser_double)
{
    class_< SPUC::quantiser<double> >("quantiser_double", init< const SPUC::quantiser<double>& >())
        .def(init< optional< char > >())
        .def("set_bits", &SPUC::quantiser<double>::set_bits)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/quantizer.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(quantizer_double)
{
    class_< SPUC::quantizer<double> >("quantizer_double", init<  >())
        .def(init< const SPUC::quantizer<double>& >())
        .def("quantized", &SPUC::quantizer<double>::quantized)
        .def("quantized_scale", &SPUC::quantizer<double>::quantized_scale)
        .staticmethod("quantized_scale")
        .staticmethod("quantized")
    ;

}


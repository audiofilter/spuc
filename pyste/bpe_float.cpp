
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/bpe.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(bpe_float)
{
    class_< SPUC::bpe<float,double> >("bpe_float", init< const SPUC::bpe<float,double>& >())
        .def(init< optional< char > >())
        .def("angle", &SPUC::bpe<float,double>::angle)
        .def("refvect", &SPUC::bpe<float,double>::refvect)
        .def("clock", &SPUC::bpe<float,double>::clock)
        .def("fq_angle", &SPUC::bpe<float,double>::fq_angle)
        .def("output", &SPUC::bpe<float,double>::output)
    ;

}


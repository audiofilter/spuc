
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/bpe.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(bpe_double)
{
    class_< SPUC::bpe<double,double> >("bpe_double", init< const SPUC::bpe<double,double>& >())
        .def(init< optional< char > >())
        .def("angle", &SPUC::bpe<double,double>::angle)
        .def("refvect", &SPUC::bpe<double,double>::refvect)
        .def("clock", &SPUC::bpe<double,double>::clock)
        .def("fq_angle", &SPUC::bpe<double,double>::fq_angle)
        .def("output", &SPUC::bpe<double,double>::output)
    ;

}


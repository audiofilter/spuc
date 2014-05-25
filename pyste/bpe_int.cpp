
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/bpe.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(bpe_int)
{
    class_< SPUC::bpe<int,double> >("bpe_int", init< const SPUC::bpe<int,double>& >())
        .def(init< optional< char > >())
        .def("angle", &SPUC::bpe<int,double>::angle)
        .def("refvect", &SPUC::bpe<int,double>::refvect)
        .def("clock", &SPUC::bpe<int,double>::clock)
        .def("fq_angle", &SPUC::bpe<int,double>::fq_angle)
        .def("output", &SPUC::bpe<int,double>::output)
    ;

}


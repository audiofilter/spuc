
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/farrow_upsampler.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(farrow_upsampler)
{
    class_< SPUC::farrow_upsampler >("farrow_upsampler", init< const SPUC::farrow_upsampler& >())
        .def(init< optional< int > >())
        .def_readwrite("time_offset", &SPUC::farrow_upsampler::time_offset)
        .def_readwrite("INTERP", &SPUC::farrow_upsampler::INTERP)
        .def("need_sample", &SPUC::farrow_upsampler::need_sample)
        .def("output", &SPUC::farrow_upsampler::output)
    ;

}


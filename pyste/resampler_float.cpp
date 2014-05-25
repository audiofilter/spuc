
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/resampler.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(resampler_float)
{
    class_< SPUC::resampler<float> >("resampler_float", init<  >())
        .def(init< const SPUC::resampler<float>& >())
        .def_readwrite("ready", &SPUC::resampler<float>::ready)
        .def_readwrite("sample2", &SPUC::resampler<float>::sample2)
        .def_readwrite("interp", &SPUC::resampler<float>::interp)
        .def_readwrite("symbol_nco", &SPUC::resampler<float>::symbol_nco)
        .def_readwrite("resampled", &SPUC::resampler<float>::resampled)
        .def_readwrite("half", &SPUC::resampler<float>::half)
        .def("update", &SPUC::resampler<float>::update)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/resampler.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(resampler_double)
{
    class_< SPUC::resampler<double> >("resampler_double", init<  >())
        .def(init< const SPUC::resampler<double>& >())
        .def_readwrite("ready", &SPUC::resampler<double>::ready)
        .def_readwrite("sample2", &SPUC::resampler<double>::sample2)
        .def_readwrite("interp", &SPUC::resampler<double>::interp)
        .def_readwrite("symbol_nco", &SPUC::resampler<double>::symbol_nco)
        .def_readwrite("resampled", &SPUC::resampler<double>::resampled)
        .def_readwrite("half", &SPUC::resampler<double>::half)
        .def("update", &SPUC::resampler<double>::update)
    ;

}


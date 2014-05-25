
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/resampler.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(resampler_int)
{
    class_< SPUC::resampler<int> >("resampler_int", init<  >())
        .def(init< const SPUC::resampler<int>& >())
        .def_readwrite("ready", &SPUC::resampler<int>::ready)
        .def_readwrite("sample2", &SPUC::resampler<int>::sample2)
        .def_readwrite("interp", &SPUC::resampler<int>::interp)
        .def_readwrite("symbol_nco", &SPUC::resampler<int>::symbol_nco)
        .def_readwrite("resampled", &SPUC::resampler<int>::resampled)
        .def_readwrite("half", &SPUC::resampler<int>::half)
        .def("update", &SPUC::resampler<int>::update)
    ;

}


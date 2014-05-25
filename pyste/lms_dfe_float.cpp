
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/lms_dfe.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(lms_dfe_float)
{
    class_< SPUC::lms_dfe<float,double> >("lms_dfe_float", init< const SPUC::lms_dfe<float,double>& >())
        .def(init< optional< char, char, float, float > >())
        .def_readwrite("ff", &SPUC::lms_dfe<float,double>::ff)
        .def_readwrite("fb", &SPUC::lms_dfe<float,double>::fb)
        .def_readwrite("u", &SPUC::lms_dfe<float,double>::u)
        .def_readwrite("mid_tap", &SPUC::lms_dfe<float,double>::mid_tap)
        .def("reset", &SPUC::lms_dfe<float,double>::reset)
        .def("set_ff_tap", &SPUC::lms_dfe<float,double>::set_ff_tap)
        .def("set_fb_tap", &SPUC::lms_dfe<float,double>::set_fb_tap)
        .def("get_ff_tap", &SPUC::lms_dfe<float,double>::get_ff_tap)
        .def("get_fb_tap", &SPUC::lms_dfe<float,double>::get_fb_tap)
        .def("ff_size", &SPUC::lms_dfe<float,double>::ff_size)
        .def("fb_size", &SPUC::lms_dfe<float,double>::fb_size)
        .def("set_gain", &SPUC::lms_dfe<float,double>::set_gain)
        .def("update", &SPUC::lms_dfe<float,double>::update)
        .def("update_taps_lms", &SPUC::lms_dfe<float,double>::update_taps_lms)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/lms_dfe.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(lms_dfe_int)
{
    class_< SPUC::lms_dfe<int,double> >("lms_dfe_int", init< const SPUC::lms_dfe<int,double>& >())
        .def(init< optional< char, char, int, int > >())
        .def_readwrite("ff", &SPUC::lms_dfe<int,double>::ff)
        .def_readwrite("fb", &SPUC::lms_dfe<int,double>::fb)
        .def_readwrite("u", &SPUC::lms_dfe<int,double>::u)
        .def_readwrite("mid_tap", &SPUC::lms_dfe<int,double>::mid_tap)
        .def("reset", &SPUC::lms_dfe<int,double>::reset)
        .def("set_ff_tap", &SPUC::lms_dfe<int,double>::set_ff_tap)
        .def("set_fb_tap", &SPUC::lms_dfe<int,double>::set_fb_tap)
        .def("get_ff_tap", &SPUC::lms_dfe<int,double>::get_ff_tap)
        .def("get_fb_tap", &SPUC::lms_dfe<int,double>::get_fb_tap)
        .def("ff_size", &SPUC::lms_dfe<int,double>::ff_size)
        .def("fb_size", &SPUC::lms_dfe<int,double>::fb_size)
        .def("set_gain", &SPUC::lms_dfe<int,double>::set_gain)
        .def("update", &SPUC::lms_dfe<int,double>::update)
        .def("update_taps_lms", &SPUC::lms_dfe<int,double>::update_taps_lms)
    ;

}


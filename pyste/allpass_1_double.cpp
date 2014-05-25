
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass_1.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_1_double)
{
    class_< SPUC::allpass_1<double,double> >("allpass_1_double", init< const SPUC::allpass_1<double,double>& >())
        .def(init< optional< SPUC::float_type, long int, long int > >())
        .def("get_coefficient", &SPUC::allpass_1<double,double>::get_coefficient)
        .def("reset", &SPUC::allpass_1<double,double>::reset)
        .def("init", &SPUC::allpass_1<double,double>::init)
        .def("clock", &SPUC::allpass_1<double,double>::clock)
    ;

}


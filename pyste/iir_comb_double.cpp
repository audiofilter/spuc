
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_comb.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_comb_double)
{
    class_< SPUC::iir_comb<double,double> >("iir_comb_double", init< const SPUC::iir_comb<double,double>& >())
        .def(init< optional< SPUC::float_type, long int, long int > >())
        .def("init", &SPUC::iir_comb<double,double>::init)
        .def("set_coeff", &SPUC::iir_comb<double,double>::set_coeff)
        .def("clock", &SPUC::iir_comb<double,double>::clock)
        .def("reset", &SPUC::iir_comb<double,double>::reset)
    ;

}


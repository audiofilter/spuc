
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_comb.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_comb_float)
{
    class_< SPUC::iir_comb<float,float> >("iir_comb_float", init< const SPUC::iir_comb<float,float>& >())
        .def(init< optional< float, long int, long int > >())
        .def("init", &SPUC::iir_comb<float,float>::init)
        .def("set_coeff", &SPUC::iir_comb<float,float>::set_coeff)
        .def("clock", &SPUC::iir_comb<float,float>::clock)
        .def("reset", &SPUC::iir_comb<float,float>::reset)
    ;

}


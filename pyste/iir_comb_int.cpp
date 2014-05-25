
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_comb.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_comb_int)
{
    class_< SPUC::iir_comb<int,float> >("iir_comb_int", init< const SPUC::iir_comb<int,float>& >())
        .def(init< optional< float, long int, long int > >())
        .def("init", &SPUC::iir_comb<int,float>::init)
        .def("set_coeff", &SPUC::iir_comb<int,float>::set_coeff)
        .def("clock", &SPUC::iir_comb<int,float>::clock)
        .def("reset", &SPUC::iir_comb<int,float>::reset)
    ;

}


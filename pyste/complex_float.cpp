
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/complex.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(complex_float)
{
    class_< SPUC::complex<float> >("complex_float", init<  >())
        .def(init< const SPUC::complex<float>& >())
        .def(init< float, optional< float > >())
        .def_readwrite("re", &SPUC::complex<float>::re)
        .def_readwrite("im", &SPUC::complex<float>::im)
        .def( -self )
        .def( self *= self )
        .def( self += self )
        .def( self -= self )
        .def("to_SPUC_complex_long_int", &SPUC::complex<float>::operator const SPUC::complex<long int>)
        .def("to_SPUC_complex_double", &SPUC::complex<float>::operator const SPUC::complex<double>)
        .def("to_SPUC_complex_float", &SPUC::complex<float>::operator const SPUC::complex<float>)
        .def("to_SPUC_complex_int", &SPUC::complex<float>::operator const SPUC::complex<int>)
        .def("to_SPUC_complex_SPUC_builtin_long_int", &SPUC::complex<float>::operator const SPUC::complex<SPUC::builtin<long int> >)
        .def("to_SPUC_complex_SPUC_builtin_double", &SPUC::complex<float>::operator const SPUC::complex<SPUC::builtin<double> >)
        .def("to_SPUC_complex_SPUC_builtin_int", &SPUC::complex<float>::operator const SPUC::complex<SPUC::builtin<int> >)
        .def("to_SPUC_complex_SPUC_builtin_float", &SPUC::complex<float>::operator const SPUC::complex<SPUC::builtin<float> >)
    ;

}


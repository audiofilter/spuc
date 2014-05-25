
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/complex.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(complex_long)
{
    class_< SPUC::complex<long int> >("complex_long", init<  >())
        .def(init< const SPUC::complex<long int>& >())
        .def(init< long int, optional< long int > >())
        .def_readwrite("re", &SPUC::complex<long int>::re)
        .def_readwrite("im", &SPUC::complex<long int>::im)
        .def( -self )
        .def( self *= self )
        .def( self += self )
        .def( self -= self )
        .def("to_SPUC_complex_long_int", &SPUC::complex<long int>::operator const SPUC::complex<long int>)
        .def("to_SPUC_complex_double", &SPUC::complex<long int>::operator const SPUC::complex<double>)
        .def("to_SPUC_complex_float", &SPUC::complex<long int>::operator const SPUC::complex<float>)
        .def("to_SPUC_complex_int", &SPUC::complex<long int>::operator const SPUC::complex<int>)
        .def("to_SPUC_complex_SPUC_builtin_long_int", &SPUC::complex<long int>::operator const SPUC::complex<SPUC::builtin<long int> >)
        .def("to_SPUC_complex_SPUC_builtin_double", &SPUC::complex<long int>::operator const SPUC::complex<SPUC::builtin<double> >)
        .def("to_SPUC_complex_SPUC_builtin_int", &SPUC::complex<long int>::operator const SPUC::complex<SPUC::builtin<int> >)
        .def("to_SPUC_complex_SPUC_builtin_float", &SPUC::complex<long int>::operator const SPUC::complex<SPUC::builtin<float> >)
    ;

}


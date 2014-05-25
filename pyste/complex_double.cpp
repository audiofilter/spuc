
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/complex.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(complex_double)
{
    class_< SPUC::complex<double> >("complex_double", init<  >())
        .def(init< const SPUC::complex<double>& >())
        .def(init< double, optional< double > >())
        .def_readwrite("re", &SPUC::complex<double>::re)
        .def_readwrite("im", &SPUC::complex<double>::im)
        .def( -self )
        .def( self *= self )
        .def( self += self )
        .def( self -= self )
        .def("to_SPUC_complex_long_int", &SPUC::complex<double>::operator const SPUC::complex<long int>)
        .def("to_SPUC_complex_double", &SPUC::complex<double>::operator const SPUC::complex<double>)
        .def("to_SPUC_complex_float", &SPUC::complex<double>::operator const SPUC::complex<float>)
        .def("to_SPUC_complex_int", &SPUC::complex<double>::operator const SPUC::complex<int>)
        .def("to_SPUC_complex_SPUC_builtin_long_int", &SPUC::complex<double>::operator const SPUC::complex<SPUC::builtin<long int> >)
        .def("to_SPUC_complex_SPUC_builtin_double", &SPUC::complex<double>::operator const SPUC::complex<SPUC::builtin<double> >)
        .def("to_SPUC_complex_SPUC_builtin_int", &SPUC::complex<double>::operator const SPUC::complex<SPUC::builtin<int> >)
        .def("to_SPUC_complex_SPUC_builtin_float", &SPUC::complex<double>::operator const SPUC::complex<SPUC::builtin<float> >)
    ;

}


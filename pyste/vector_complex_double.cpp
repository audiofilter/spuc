
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_complex_double)
{
    class_< SPUC::vector<SPUC::complex<double> > >("vector_complex_double", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<SPUC::complex<double> >& >())
        .def("len", &SPUC::vector<SPUC::complex<double> >::len)
        .def("size", &SPUC::vector<SPUC::complex<double> >::size)
        .def("reset", &SPUC::vector<SPUC::complex<double> >::reset)
        .def("ones", &SPUC::vector<SPUC::complex<double> >::ones)
        .def("__call__", &SPUC::vector<SPUC::complex<double> >::operator ())
    ;

}


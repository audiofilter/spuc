
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_complex_long)
{
    class_< SPUC::vector<SPUC::complex<long int> > >("vector_complex_long", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<SPUC::complex<long int> >& >())
        .def("len", &SPUC::vector<SPUC::complex<long int> >::len)
        .def("size", &SPUC::vector<SPUC::complex<long int> >::size)
        .def("reset", &SPUC::vector<SPUC::complex<long int> >::reset)
        .def("ones", &SPUC::vector<SPUC::complex<long int> >::ones)
        .def("__call__", &SPUC::vector<SPUC::complex<long int> >::operator ())
    ;

}


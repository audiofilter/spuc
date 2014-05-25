
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/vector.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(vector_complex_int)
{
    class_< SPUC::vector<SPUC::complex<int> > >("vector_complex_int", init<  >())
        .def(init< int >())
        .def(init< const SPUC::vector<SPUC::complex<int> >& >())
        .def("len", &SPUC::vector<SPUC::complex<int> >::len)
        .def("size", &SPUC::vector<SPUC::complex<int> >::size)
        .def("reset", &SPUC::vector<SPUC::complex<int> >::reset)
        .def("ones", &SPUC::vector<SPUC::complex<int> >::ones)
        .def("__call__", &SPUC::vector<SPUC::complex<int> >::operator ())
    ;

}


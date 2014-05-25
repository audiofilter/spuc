
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/convolutional_interleaver.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(convolutional_interleaver_int)
{
    class_< SPUC::convolutional_interleaver<int> >("convolutional_interleaver_int", init<  >())
        .def(init< const SPUC::convolutional_interleaver<int>& >())
        .def(init< int, int >())
        .def("interleave", &SPUC::convolutional_interleaver<int>::interleave)
        .def("interleave_write", &SPUC::convolutional_interleaver<int>::interleave_write)
        .def("interleave_read", &SPUC::convolutional_interleaver<int>::interleave_read)
        .def("deinterleave", &SPUC::convolutional_interleaver<int>::deinterleave)
        .def("set_size", &SPUC::convolutional_interleaver<int>::set_size)
        .def("get_rows", &SPUC::convolutional_interleaver<int>::get_rows)
        .def("get_cols", &SPUC::convolutional_interleaver<int>::get_cols)
        .def("reset", &SPUC::convolutional_interleaver<int>::reset)
        .def("resync", &SPUC::convolutional_interleaver<int>::resync)
    ;

}


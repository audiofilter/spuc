
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/convolutional_interleaver.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(convolutional_interleaver_float)
{
    class_< SPUC::convolutional_interleaver<float> >("convolutional_interleaver_float", init<  >())
        .def(init< const SPUC::convolutional_interleaver<float>& >())
        .def(init< int, int >())
        .def("interleave", &SPUC::convolutional_interleaver<float>::interleave)
        .def("interleave_write", &SPUC::convolutional_interleaver<float>::interleave_write)
        .def("interleave_read", &SPUC::convolutional_interleaver<float>::interleave_read)
        .def("deinterleave", &SPUC::convolutional_interleaver<float>::deinterleave)
        .def("set_size", &SPUC::convolutional_interleaver<float>::set_size)
        .def("get_rows", &SPUC::convolutional_interleaver<float>::get_rows)
        .def("get_cols", &SPUC::convolutional_interleaver<float>::get_cols)
        .def("reset", &SPUC::convolutional_interleaver<float>::reset)
        .def("resync", &SPUC::convolutional_interleaver<float>::resync)
    ;

}


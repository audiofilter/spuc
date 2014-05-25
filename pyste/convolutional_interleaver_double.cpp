
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/convolutional_interleaver.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(convolutional_interleaver_double)
{
    class_< SPUC::convolutional_interleaver<double> >("convolutional_interleaver_double", init<  >())
        .def(init< const SPUC::convolutional_interleaver<double>& >())
        .def(init< int, int >())
        .def("interleave", &SPUC::convolutional_interleaver<double>::interleave)
        .def("interleave_write", &SPUC::convolutional_interleaver<double>::interleave_write)
        .def("interleave_read", &SPUC::convolutional_interleaver<double>::interleave_read)
        .def("deinterleave", &SPUC::convolutional_interleaver<double>::deinterleave)
        .def("set_size", &SPUC::convolutional_interleaver<double>::set_size)
        .def("get_rows", &SPUC::convolutional_interleaver<double>::get_rows)
        .def("get_cols", &SPUC::convolutional_interleaver<double>::get_cols)
        .def("reset", &SPUC::convolutional_interleaver<double>::reset)
        .def("resync", &SPUC::convolutional_interleaver<double>::resync)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_df.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_df_int)
{
    class_< SPUC::iir_df<int,float> >("iir_df_int", init< const SPUC::iir_df<int,float>& >())
        .def(init< const char*, const char* >())
        .def_readwrite("poles", &SPUC::iir_df<int,float>::poles)
        .def_readwrite("zeros", &SPUC::iir_df<int,float>::zeros)
        .def_readwrite("output", &SPUC::iir_df<int,float>::output)
        .def_readwrite("err", &SPUC::iir_df<int,float>::err)
        .def("reset", &SPUC::iir_df<int,float>::reset)
        .def("out", &SPUC::iir_df<int,float>::out)
        .def("clock", &SPUC::iir_df<int,float>::clock)
        .def("update", &SPUC::iir_df<int,float>::update)
        .def("print", &SPUC::iir_df<int,float>::print)
    ;

}


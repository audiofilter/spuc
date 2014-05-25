
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_df.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_df_float)
{
    class_< SPUC::iir_df<float,float> >("iir_df_float", init< const SPUC::iir_df<float,float>& >())
        .def(init< const char*, const char* >())
        .def_readwrite("poles", &SPUC::iir_df<float,float>::poles)
        .def_readwrite("zeros", &SPUC::iir_df<float,float>::zeros)
        .def_readwrite("output", &SPUC::iir_df<float,float>::output)
        .def_readwrite("err", &SPUC::iir_df<float,float>::err)
        .def("reset", &SPUC::iir_df<float,float>::reset)
        .def("out", &SPUC::iir_df<float,float>::out)
        .def("clock", &SPUC::iir_df<float,float>::clock)
        .def("update", &SPUC::iir_df<float,float>::update)
        .def("print", &SPUC::iir_df<float,float>::print)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/iir_df.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(iir_df_double)
{
    class_< SPUC::iir_df<double,double> >("iir_df_double", init< const SPUC::iir_df<double,double>& >())
        .def(init< const char*, const char* >())
        .def_readwrite("poles", &SPUC::iir_df<double,double>::poles)
        .def_readwrite("zeros", &SPUC::iir_df<double,double>::zeros)
        .def_readwrite("output", &SPUC::iir_df<double,double>::output)
        .def_readwrite("err", &SPUC::iir_df<double,double>::err)
        .def("reset", &SPUC::iir_df<double,double>::reset)
        .def("out", &SPUC::iir_df<double,double>::out)
        .def("clock", &SPUC::iir_df<double,double>::clock)
        .def("update", &SPUC::iir_df<double,double>::update)
        .def("print", &SPUC::iir_df<double,double>::print)
    ;

}


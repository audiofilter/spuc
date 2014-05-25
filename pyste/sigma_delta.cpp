
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/sigma_delta.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(sigma_delta)
{
    class_< SPUC::sigma_delta >("sigma_delta", init< const SPUC::sigma_delta& >())
        .def(init< optional< char, char > >())
        .def_readwrite("nbit_out", &SPUC::sigma_delta::nbit_out)
        .def_readwrite("nbit_in", &SPUC::sigma_delta::nbit_in)
        .def("single", &SPUC::sigma_delta::single)
    ;

}


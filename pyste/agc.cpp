
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/agc.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(agc)
{
    class_< SPUC::agc >("agc", init< const SPUC::agc& >())
        .def(init< optional< long int > >())
        .def_readwrite("agc_acc", &SPUC::agc::agc_acc)
        .def_readwrite("agc_bit", &SPUC::agc::agc_bit)
        .def_readwrite("agc_thres", &SPUC::agc::agc_thres)
        .def("run", &SPUC::agc::run)
    ;

}


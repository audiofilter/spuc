
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/max_pn.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(max_pn)
{
    class_< SPUC::max_pn >("max_pn", init< const SPUC::max_pn& >())
        .def(init< optional< int, int, int > >())
        .def("reset", &SPUC::max_pn::reset)
        .def("out", &SPUC::max_pn::out)
        .def("get_bit", &SPUC::max_pn::get_bit)
        .def("out1", &SPUC::max_pn::out1)
        .def("state", &SPUC::max_pn::state)
    ;

}


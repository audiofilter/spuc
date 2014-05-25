
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qam_mod.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qam_mod)
{
    class_< SPUC::qam_mod >("qam_mod", init< const SPUC::qam_mod& >())
        .def(init< int >())
        .def_readwrite("rate_index", &SPUC::qam_mod::rate_index)
        .def("data_map", &SPUC::qam_mod::data_map)
        .def("bpsk_map", &SPUC::qam_mod::bpsk_map)
        .def("qpsk_map", &SPUC::qam_mod::qpsk_map)
        .def("qam16_map", &SPUC::qam_mod::qam16_map)
        .def("qam64_map", &SPUC::qam_mod::qam64_map)
    ;

}


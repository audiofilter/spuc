
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qam_soft_decision.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qam_soft_decision)
{
    def("qam64_soft_decision", &SPUC::qam64_soft_decision);
    def("bpsk_soft_decision", &SPUC::bpsk_soft_decision);
    def("qam_data_demap", &SPUC::qam_data_demap);
    def("qam16_soft_decision", &SPUC::qam16_soft_decision);
    def("qpsk_soft_decision", &SPUC::qpsk_soft_decision);
}


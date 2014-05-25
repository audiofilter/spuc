
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/bpsk_ber_test.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(bpsk_ber_test)
{
    class_< SPUC::bpsk_ber_test >("bpsk_ber_test", init<  >())
        .def(init< const SPUC::bpsk_ber_test& >())
        .def_readwrite("modc", &SPUC::bpsk_ber_test::modc)
        .def_readwrite("start_time", &SPUC::bpsk_ber_test::start_time)
        .def_readwrite("ref", &SPUC::bpsk_ber_test::ref)
        .def_readwrite("corr_sum", &SPUC::bpsk_ber_test::corr_sum)
        .def_readwrite("errors", &SPUC::bpsk_ber_test::errors)
        .def_readwrite("synced", &SPUC::bpsk_ber_test::synced)
        .def_readwrite("interval", &SPUC::bpsk_ber_test::interval)
        .def_readwrite("prev_errors", &SPUC::bpsk_ber_test::prev_errors)
        .def("reset", &SPUC::bpsk_ber_test::reset)
        .def("found_sync", &SPUC::bpsk_ber_test::found_sync)
        .def("ber_results", &SPUC::bpsk_ber_test::ber_results)
        .def("synchronize", &SPUC::bpsk_ber_test::synchronize)
        .def("final_results", &SPUC::bpsk_ber_test::final_results)
        .def("correlate", &SPUC::bpsk_ber_test::correlate)
        .def("running_ber", &SPUC::bpsk_ber_test::running_ber)
        .def("ber", &SPUC::bpsk_ber_test::ber)
    ;

}


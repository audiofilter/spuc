
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/qpsk_ber_test.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(qpsk_ber_test)
{
    class_< SPUC::qpsk_ber_test >("qpsk_ber_test", init<  >())
        .def(init< const SPUC::qpsk_ber_test& >())
        .def_readwrite("modc", &SPUC::qpsk_ber_test::modc)
        .def_readwrite("start_time", &SPUC::qpsk_ber_test::start_time)
        .def_readwrite("ref", &SPUC::qpsk_ber_test::ref)
        .def_readwrite("corr_sum", &SPUC::qpsk_ber_test::corr_sum)
        .def_readwrite("errors", &SPUC::qpsk_ber_test::errors)
        .def_readwrite("rotate", &SPUC::qpsk_ber_test::rotate)
        .def_readwrite("sync", &SPUC::qpsk_ber_test::sync)
        .def_readwrite("interval", &SPUC::qpsk_ber_test::interval)
        .def_readwrite("prev_errors", &SPUC::qpsk_ber_test::prev_errors)
        .def("reset", &SPUC::qpsk_ber_test::reset)
        .def("init_delay", &SPUC::qpsk_ber_test::init_delay)
        .def("found_sync", &SPUC::qpsk_ber_test::found_sync)
        .def("ber_results", &SPUC::qpsk_ber_test::ber_results)
        .def("synchronize", &SPUC::qpsk_ber_test::synchronize)
        .def("synchronise", &SPUC::qpsk_ber_test::synchronise)
        .def("final_results", &SPUC::qpsk_ber_test::final_results)
        .def("correlate", &SPUC::qpsk_ber_test::correlate)
        .def("print_running_ber", &SPUC::qpsk_ber_test::print_running_ber)
        .def("running_ber", &SPUC::qpsk_ber_test::running_ber)
        .def("ber", &SPUC::qpsk_ber_test::ber)
    ;

}


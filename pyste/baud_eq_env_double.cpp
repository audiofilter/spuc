
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/baud_eq_env.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(baud_eq_env_double)
{
    class_< SPUC::baud_eq_env<SPUC::complex<double> > >("baud_eq_env_complex_double", init< const SPUC::baud_eq_env<SPUC::complex<double> >& >())
        .def(init< optional< long int > >())
        .def_readwrite("BER_mon", &SPUC::baud_eq_env<SPUC::complex<double> >::BER_mon)
        .def_readwrite("tx_data_source", &SPUC::baud_eq_env<SPUC::complex<double> >::tx_data_source)
        .def_readwrite("n", &SPUC::baud_eq_env<SPUC::complex<double> >::n)
        .def_readwrite("DUT", &SPUC::baud_eq_env<SPUC::complex<double> >::DUT)
        .def_readwrite("multipaths", &SPUC::baud_eq_env<SPUC::complex<double> >::multipaths)
        .def_readwrite("num", &SPUC::baud_eq_env<SPUC::complex<double> >::num)
        .def_readwrite("var", &SPUC::baud_eq_env<SPUC::complex<double> >::var)
        .def_readwrite("snr", &SPUC::baud_eq_env<SPUC::complex<double> >::snr)
        .def_readwrite("data", &SPUC::baud_eq_env<SPUC::complex<double> >::data)
        .def_readwrite("output_delay", &SPUC::baud_eq_env<SPUC::complex<double> >::output_delay)
        .def_readwrite("eq_type", &SPUC::baud_eq_env<SPUC::complex<double> >::eq_type)
        .def_readwrite("base", &SPUC::baud_eq_env<SPUC::complex<double> >::base)
        .def_readwrite("main", &SPUC::baud_eq_env<SPUC::complex<double> >::main)
        .def_readwrite("b_noise", &SPUC::baud_eq_env<SPUC::complex<double> >::b_noise)
        .def_readwrite("rcv_symbols", &SPUC::baud_eq_env<SPUC::complex<double> >::rcv_symbols)
        .def_readwrite("count", &SPUC::baud_eq_env<SPUC::complex<double> >::count)
        .def_readwrite("paths", &SPUC::baud_eq_env<SPUC::complex<double> >::paths)
        .def_readwrite("phase_acc", &SPUC::baud_eq_env<SPUC::complex<double> >::phase_acc)
        .def("loop_init", &SPUC::baud_eq_env<SPUC::complex<double> >::loop_init)
        .def("step", &SPUC::baud_eq_env<SPUC::complex<double> >::step)
        .def("loop_end", &SPUC::baud_eq_env<SPUC::complex<double> >::loop_end)
    ;

}


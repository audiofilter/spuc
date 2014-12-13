
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_interp.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_fir_interp_double_double_set_manual_overloads_0_1, set_manual, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(fir_interp_double)
{
    class_< SPUC::fir_interp<double,double> >("fir_interp_double", init<  >())
        .def(init< const SPUC::fir_interp<double,double>& >())
        .def(init< const char* >())
        .def(init< long int >())
        .def_readwrite("num_low", &SPUC::fir_interp<double,double>::num_low)
        .def_readwrite("rate", &SPUC::fir_interp<double,double>::rate)
        .def_readwrite("phase", &SPUC::fir_interp<double,double>::phase)
        .def_readwrite("auto_mode", &SPUC::fir_interp<double,double>::auto_mode)
        .def_readwrite("coeff", &SPUC::fir<double,double>::coeff)
        .def_readwrite("z", &SPUC::fir<double,double>::z)
        .def_readwrite("output", &SPUC::fir<double,double>::output)
        .def_readwrite("Q", &SPUC::fir<double,double>::Q)
        .def_readwrite("num_taps", &SPUC::fir<double,double>::num_taps)
        .def("skip", &SPUC::fir_interp<double,double>::skip)
        .def("set_rate", &SPUC::fir_interp<double,double>::set_rate)
        .def("set_automatic", &SPUC::fir_interp<double,double>::set_automatic)
        .def("set_manual", &SPUC::fir_interp<double,double>::set_manual, SPUC_fir_interp_double_double_set_manual_overloads_0_1())
        .def("reset", &SPUC::fir_interp<double,double>::reset)
        .def("coeff_sum", &SPUC::fir_interp<double,double>::coeff_sum)
        .def("input", &SPUC::fir_interp<double,double>::input)
        .def("clock", (double (SPUC::fir_interp<double,double>::*)(long int) )&SPUC::fir_interp<double,double>::clock)
        .def("clock", (double (SPUC::fir_interp<double,double>::*)() )&SPUC::fir_interp<double,double>::clock)
        .def("settap", (void (SPUC::fir<double,double>::*)(long int, SPUC::float_type) )&SPUC::fir<double,double>::settap)
        .def("settaps", &SPUC::fir<double,double>::settaps)
        .def("number_of_taps", &SPUC::fir<double,double>::number_of_taps)
        .def("gettap", &SPUC::fir<double,double>::gettap)
        .def("out", &SPUC::fir<double,double>::out)
        .def("check", &SPUC::fir<double,double>::check)
        .def("set_round_bits", &SPUC::fir<double,double>::set_round_bits)
        .def("set_size", &SPUC::fir<double,double>::set_size)
        .def("get_size", &SPUC::fir<double,double>::get_size)
        .def("clock", (double (SPUC::fir<double,double>::*)(double) )&SPUC::fir<double,double>::clock)
        .def("update", &SPUC::fir<double,double>::update)
        .def("iir", &SPUC::fir<double,double>::iir)
        .def("read_taps", &SPUC::fir<double,double>::read_taps)
        .def("print", &SPUC::fir<double,double>::print)
        .def("settap", (void (SPUC::fir<double,double>::*)(std::vector<double>) )&SPUC::fir<double,double>::settap)
    ;

}


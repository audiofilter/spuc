
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_interp.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_fir_interp_float_float_set_manual_overloads_0_1, set_manual, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(fir_interp_float)
{
    class_< SPUC::fir_interp<float,float> >("fir_interp_float", init<  >())
        .def(init< const SPUC::fir_interp<float,float>& >())
        .def(init< const char* >())
        .def(init< long int >())
        .def_readwrite("num_low", &SPUC::fir_interp<float,float>::num_low)
        .def_readwrite("rate", &SPUC::fir_interp<float,float>::rate)
        .def_readwrite("phase", &SPUC::fir_interp<float,float>::phase)
        .def_readwrite("auto_mode", &SPUC::fir_interp<float,float>::auto_mode)
        .def_readwrite("coeff", &SPUC::fir<float,float>::coeff)
        .def_readwrite("z", &SPUC::fir<float,float>::z)
        .def_readwrite("output", &SPUC::fir<float,float>::output)
        .def_readwrite("Q", &SPUC::fir<float,float>::Q)
        .def_readwrite("num_taps", &SPUC::fir<float,float>::num_taps)
        .def("skip", &SPUC::fir_interp<float,float>::skip)
        .def("set_rate", &SPUC::fir_interp<float,float>::set_rate)
        .def("set_automatic", &SPUC::fir_interp<float,float>::set_automatic)
        .def("set_manual", &SPUC::fir_interp<float,float>::set_manual, SPUC_fir_interp_float_float_set_manual_overloads_0_1())
        .def("reset", &SPUC::fir_interp<float,float>::reset)
        .def("coeff_sum", &SPUC::fir_interp<float,float>::coeff_sum)
        .def("input", &SPUC::fir_interp<float,float>::input)
        .def("clock", (float (SPUC::fir_interp<float,float>::*)(long int) )&SPUC::fir_interp<float,float>::clock)
        .def("clock", (float (SPUC::fir_interp<float,float>::*)() )&SPUC::fir_interp<float,float>::clock)
        .def("settap", (void (SPUC::fir<float,float>::*)(long int, float) )&SPUC::fir<float,float>::settap)
        .def("settaps", &SPUC::fir<float,float>::settaps)
        .def("number_of_taps", &SPUC::fir<float,float>::number_of_taps)
        .def("gettap", &SPUC::fir<float,float>::gettap)
        .def("out", &SPUC::fir<float,float>::out)
        .def("check", &SPUC::fir<float,float>::check)
        .def("set_round_bits", &SPUC::fir<float,float>::set_round_bits)
        .def("set_size", &SPUC::fir<float,float>::set_size)
        .def("get_size", &SPUC::fir<float,float>::get_size)
        .def("clock", (float (SPUC::fir<float,float>::*)(float) )&SPUC::fir<float,float>::clock)
        .def("update", &SPUC::fir<float,float>::update)
        .def("iir", &SPUC::fir<float,float>::iir)
        .def("read_taps", &SPUC::fir<float,float>::read_taps)
        .def("print", &SPUC::fir<float,float>::print)
        .def("settap", (void (SPUC::fir<float,float>::*)(SPUC::smart_array<float>) )&SPUC::fir<float,float>::settap)
    ;

}


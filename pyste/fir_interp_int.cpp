
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_interp.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_fir_interp_int_float_set_manual_overloads_0_1, set_manual, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(fir_interp_int)
{
    class_< SPUC::fir_interp<int,float> >("fir_interp_int", init<  >())
        .def(init< const SPUC::fir_interp<int,float>& >())
        .def(init< const char* >())
        .def(init< long int >())
        .def_readwrite("num_low", &SPUC::fir_interp<int,float>::num_low)
        .def_readwrite("rate", &SPUC::fir_interp<int,float>::rate)
        .def_readwrite("phase", &SPUC::fir_interp<int,float>::phase)
        .def_readwrite("auto_mode", &SPUC::fir_interp<int,float>::auto_mode)
        .def_readwrite("coeff", &SPUC::fir<int,float>::coeff)
        .def_readwrite("z", &SPUC::fir<int,float>::z)
        .def_readwrite("output", &SPUC::fir<int,float>::output)
        .def_readwrite("Q", &SPUC::fir<int,float>::Q)
        .def_readwrite("num_taps", &SPUC::fir<int,float>::num_taps)
        .def("skip", &SPUC::fir_interp<int,float>::skip)
        .def("set_rate", &SPUC::fir_interp<int,float>::set_rate)
        .def("set_automatic", &SPUC::fir_interp<int,float>::set_automatic)
        .def("set_manual", &SPUC::fir_interp<int,float>::set_manual, SPUC_fir_interp_int_float_set_manual_overloads_0_1())
        .def("reset", &SPUC::fir_interp<int,float>::reset)
        .def("coeff_sum", &SPUC::fir_interp<int,float>::coeff_sum)
        .def("input", &SPUC::fir_interp<int,float>::input)
        .def("clock", (int (SPUC::fir_interp<int,float>::*)(long int) )&SPUC::fir_interp<int,float>::clock)
        .def("clock", (int (SPUC::fir_interp<int,float>::*)() )&SPUC::fir_interp<int,float>::clock)
        .def("settap", (void (SPUC::fir<int,float>::*)(long int, float) )&SPUC::fir<int,float>::settap)
        .def("settaps", &SPUC::fir<int,float>::settaps)
        .def("number_of_taps", &SPUC::fir<int,float>::number_of_taps)
        .def("gettap", &SPUC::fir<int,float>::gettap)
        .def("out", &SPUC::fir<int,float>::out)
        .def("check", &SPUC::fir<int,float>::check)
        .def("set_round_bits", &SPUC::fir<int,float>::set_round_bits)
        .def("set_size", &SPUC::fir<int,float>::set_size)
        .def("get_size", &SPUC::fir<int,float>::get_size)
        .def("clock", (int (SPUC::fir<int,float>::*)(int) )&SPUC::fir<int,float>::clock)
        .def("update", &SPUC::fir<int,float>::update)
        .def("iir", &SPUC::fir<int,float>::iir)
        .def("read_taps", &SPUC::fir<int,float>::read_taps)
        .def("print", &SPUC::fir<int,float>::print)
        .def("settap", (void (SPUC::fir<int,float>::*)(std::vector<float>) )&SPUC::fir<int,float>::settap)
    ;

}


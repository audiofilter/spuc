
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/base_demod.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

struct SPUC_base_demod_int_Wrapper: SPUC::base_demod<int>
{
    SPUC_base_demod_int_Wrapper(PyObject* py_self_, const SPUC::base_demod<int>& p0):
        SPUC::base_demod<int>(p0), py_self(py_self_) {}

    SPUC_base_demod_int_Wrapper(PyObject* py_self_):
        SPUC::base_demod<int>(), py_self(py_self_) {}

    SPUC::complex<int> step(SPUC::complex<int> p0) {
        return call_method< SPUC::complex<int> >(py_self, "step", p0);
    }

    SPUC::complex<int> default_step(SPUC::complex<int> p0) {
        return SPUC::base_demod<int>::step(p0);
    }

    bool sym_pulse() {
        return call_method< bool >(py_self, "sym_pulse");
    }

    bool default_sym_pulse() {
        return SPUC::base_demod<int>::sym_pulse();
    }

    bool buffer_empty() {
        return call_method< bool >(py_self, "buffer_empty");
    }

    bool default_buffer_empty() {
        return SPUC::base_demod<int>::buffer_empty();
    }

    bool get_bits() {
        return call_method< bool >(py_self, "get_bits");
    }

    bool default_get_bits() {
        return SPUC::base_demod<int>::get_bits();
    }

    SPUC::complex<int> get_taps(int p0) {
        return call_method< SPUC::complex<int> >(py_self, "get_taps", p0);
    }

    SPUC::complex<int> default_get_taps(int p0) {
        return SPUC::base_demod<int>::get_taps(p0);
    }

    int eq_size() {
        return call_method< int >(py_self, "eq_size");
    }

    int default_eq_size() {
        return SPUC::base_demod<int>::eq_size();
    }

    PyObject* py_self;
};


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(base_demod_int)
{
    class_< SPUC::base_demod<int>, SPUC_base_demod_int_Wrapper >("base_demod_int", init<  >())
        .def(init< const SPUC::base_demod<int>& >())
        .def_readwrite("data_ready", &SPUC::base_demod<int>::data_ready)
        .def_readwrite("sample_value", &SPUC::base_demod<int>::sample_value)
        .def_readwrite("symbol_value", &SPUC::base_demod<int>::symbol_value)
        .def_readwrite("vers", &SPUC::base_demod<int>::vers)
        .def("step", &SPUC::base_demod<int>::step, &SPUC_base_demod_int_Wrapper::default_step)
        .def("sym_pulse", &SPUC::base_demod<int>::sym_pulse, &SPUC_base_demod_int_Wrapper::default_sym_pulse)
        .def("buffer_empty", &SPUC::base_demod<int>::buffer_empty, &SPUC_base_demod_int_Wrapper::default_buffer_empty)
        .def("get_bits", &SPUC::base_demod<int>::get_bits, &SPUC_base_demod_int_Wrapper::default_get_bits)
        .def("get_taps", &SPUC::base_demod<int>::get_taps, &SPUC_base_demod_int_Wrapper::default_get_taps)
        .def("eq_size", &SPUC::base_demod<int>::eq_size, &SPUC_base_demod_int_Wrapper::default_eq_size)
    ;

}



// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/base_demod.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

struct SPUC_base_demod_double_Wrapper: SPUC::base_demod<double>
{
    SPUC_base_demod_double_Wrapper(PyObject* py_self_, const SPUC::base_demod<double>& p0):
        SPUC::base_demod<double>(p0), py_self(py_self_) {}

    SPUC_base_demod_double_Wrapper(PyObject* py_self_):
        SPUC::base_demod<double>(), py_self(py_self_) {}

    SPUC::complex<double> step(SPUC::complex<double> p0) {
        return call_method< SPUC::complex<double> >(py_self, "step", p0);
    }

    SPUC::complex<double> default_step(SPUC::complex<double> p0) {
        return SPUC::base_demod<double>::step(p0);
    }

    bool sym_pulse() {
        return call_method< bool >(py_self, "sym_pulse");
    }

    bool default_sym_pulse() {
        return SPUC::base_demod<double>::sym_pulse();
    }

    bool buffer_empty() {
        return call_method< bool >(py_self, "buffer_empty");
    }

    bool default_buffer_empty() {
        return SPUC::base_demod<double>::buffer_empty();
    }

    bool get_bits() {
        return call_method< bool >(py_self, "get_bits");
    }

    bool default_get_bits() {
        return SPUC::base_demod<double>::get_bits();
    }

    SPUC::complex<double> get_taps(int p0) {
        return call_method< SPUC::complex<double> >(py_self, "get_taps", p0);
    }

    SPUC::complex<double> default_get_taps(int p0) {
        return SPUC::base_demod<double>::get_taps(p0);
    }

    int eq_size() {
        return call_method< int >(py_self, "eq_size");
    }

    int default_eq_size() {
        return SPUC::base_demod<double>::eq_size();
    }

    PyObject* py_self;
};


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(base_demod_double)
{
    class_< SPUC::base_demod<double>, SPUC_base_demod_double_Wrapper >("base_demod_double", init<  >())
        .def(init< const SPUC::base_demod<double>& >())
        .def_readwrite("data_ready", &SPUC::base_demod<double>::data_ready)
        .def_readwrite("sample_value", &SPUC::base_demod<double>::sample_value)
        .def_readwrite("symbol_value", &SPUC::base_demod<double>::symbol_value)
        .def_readwrite("vers", &SPUC::base_demod<double>::vers)
        .def("step", &SPUC::base_demod<double>::step, &SPUC_base_demod_double_Wrapper::default_step)
        .def("sym_pulse", &SPUC::base_demod<double>::sym_pulse, &SPUC_base_demod_double_Wrapper::default_sym_pulse)
        .def("buffer_empty", &SPUC::base_demod<double>::buffer_empty, &SPUC_base_demod_double_Wrapper::default_buffer_empty)
        .def("get_bits", &SPUC::base_demod<double>::get_bits, &SPUC_base_demod_double_Wrapper::default_get_bits)
        .def("get_taps", &SPUC::base_demod<double>::get_taps, &SPUC_base_demod_double_Wrapper::default_get_taps)
        .def("eq_size", &SPUC::base_demod<double>::eq_size, &SPUC_base_demod_double_Wrapper::default_eq_size)
    ;

}


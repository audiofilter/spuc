
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/spuc_math.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(spuc_math)
{
    def("expj", (SPUC::complex<float> (*)(float))&SPUC::expj);
    def("expj", (SPUC::complex<double> (*)(double))&SPUC::expj);
    def("arccos", &SPUC::arccos);
    def("coshin", &SPUC::coshin);
    def("sinh", &SPUC::sinh);
    def("cosh", &SPUC::cosh);
    def("sqrt", (SPUC::float_type (*)(SPUC::float_type))&SPUC::sqrt);
    def("sqrt", (SPUC::complex<double> (*)(SPUC::complex<long int>))&SPUC::sqrt);
    def("sqrt", (SPUC::complex<double> (*)(SPUC::complex<double>))&SPUC::sqrt);
    def("sqrt", (SPUC::float_type (*)(SPUC::float_type))&SPUC::sqrt);
    def("sqrt", (SPUC::complex<double> (*)(SPUC::complex<long int>))&SPUC::sqrt);
    def("sqrt", (SPUC::complex<double> (*)(SPUC::complex<double>))&SPUC::sqrt);
    def("sqrt", (SPUC::float_type (*)(SPUC::float_type))&SPUC::sqrt);
    def("sqrt", (SPUC::complex<double> (*)(SPUC::complex<long int>))&SPUC::sqrt);
    def("sqrt", (SPUC::complex<double> (*)(SPUC::complex<double>))&SPUC::sqrt);
    def("polar", &SPUC::polar);
    def("expj", (SPUC::complex<float> (*)(float))&SPUC::expj);
    def("expj", (SPUC::complex<double> (*)(double))&SPUC::expj);
    def("hypot", &SPUC::hypot);
    def("exp", &SPUC::exp);
    def("cos", (SPUC::float_type (*)(SPUC::float_type))&SPUC::cos);
    def("cos", (SPUC::complex<double> (*)(SPUC::complex<double>))&SPUC::cos);
    def("cos", (SPUC::float_type (*)(SPUC::float_type))&SPUC::cos);
    def("cos", (SPUC::complex<double> (*)(SPUC::complex<double>))&SPUC::cos);
}


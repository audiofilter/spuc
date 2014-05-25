// This code is automatically generated

#include <boost/python.hpp>
#include <boost/cstdint.hpp>
#include <boost/python/def.hpp>
#include <boost/python/args.hpp>
#include <boost/python/overloads.hpp>

using namespace boost::python;

#include <spuc/conj.h>
#include <spuc/magsq.h>
#include <spuc/quantize.h>
#include <spuc/raised_cosine.h>
#include <spuc/root_raised_cosine.h>
#include <spuc/round.h>
#include <spuc/saturate.h>
#include <spuc/signbit.h>
#include <spuc/toeplitz.h>

BOOST_PYTHON_MODULE(template_functions_complex_double) {
def("conj_complex_double",&SPUC::conj<SPUC::complex<double> >);
def("magsq_complex_double",&SPUC::magsq<SPUC::complex<double> >);
def("quantize_complex_double",&SPUC::quantize<SPUC::complex<double> >);
def("raised_cosine_complex_double",&SPUC::raised_cosine<SPUC::complex<double> >);
def("root_raised_cosine_complex_double",&SPUC::root_raised_cosine<SPUC::complex<double> >);
def("round_complex_double",&SPUC::round<SPUC::complex<double> >);
def("saturate_complex_double",&SPUC::saturate<SPUC::complex<double> >);
def("signbit_complex_double",&SPUC::signbit<SPUC::complex<double> >);
def("toeplitz_complex_double",&SPUC::toeplitz<SPUC::complex<double> >);
}

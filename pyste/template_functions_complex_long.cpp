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

BOOST_PYTHON_MODULE(template_functions_complex_long) {
def("conj_complex_long",&SPUC::conj<SPUC::complex<long> >);
def("magsq_complex_long",&SPUC::magsq<SPUC::complex<long> >);
def("quantize_complex_long",&SPUC::quantize<SPUC::complex<long> >);
def("raised_cosine_complex_long",&SPUC::raised_cosine<SPUC::complex<long> >);
def("root_raised_cosine_complex_long",&SPUC::root_raised_cosine<SPUC::complex<long> >);
def("round_complex_long",&SPUC::round<SPUC::complex<long> >);
def("saturate_complex_long",&SPUC::saturate<SPUC::complex<long> >);
def("signbit_complex_long",&SPUC::signbit<SPUC::complex<long> >);
def("toeplitz_complex_long",&SPUC::toeplitz<SPUC::complex<long> >);
}

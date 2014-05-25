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

BOOST_PYTHON_MODULE(template_functions_complex_float) {
def("conj_complex_float",&SPUC::conj<SPUC::complex<float> >);
def("magsq_complex_float",&SPUC::magsq<SPUC::complex<float> >);
def("quantize_complex_float",&SPUC::quantize<SPUC::complex<float> >);
def("raised_cosine_complex_float",&SPUC::raised_cosine<SPUC::complex<float> >);
def("root_raised_cosine_complex_float",&SPUC::root_raised_cosine<SPUC::complex<float> >);
def("round_complex_float",&SPUC::round<SPUC::complex<float> >);
def("saturate_complex_float",&SPUC::saturate<SPUC::complex<float> >);
def("signbit_complex_float",&SPUC::signbit<SPUC::complex<float> >);
def("toeplitz_complex_float",&SPUC::toeplitz<SPUC::complex<float> >);
}

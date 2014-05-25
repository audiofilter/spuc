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

BOOST_PYTHON_MODULE(template_functions_float) {
def("conj_float",&SPUC::conj<float >);
def("magsq_float",&SPUC::magsq<float >);
def("quantize_float",&SPUC::quantize<float >);
def("raised_cosine_float",&SPUC::raised_cosine<float >);
def("root_raised_cosine_float",&SPUC::root_raised_cosine<float >);
def("round_float",&SPUC::round<float >);
def("saturate_float",&SPUC::saturate<float >);
def("signbit_float",&SPUC::signbit<float >);
def("toeplitz_float",&SPUC::toeplitz<float >);
}

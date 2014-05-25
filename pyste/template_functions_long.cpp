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

BOOST_PYTHON_MODULE(template_functions_long) {
def("conj_long",&SPUC::conj<long >);
def("magsq_long",&SPUC::magsq<long >);
def("quantize_long",&SPUC::quantize<long >);
def("raised_cosine_long",&SPUC::raised_cosine<long >);
def("root_raised_cosine_long",&SPUC::root_raised_cosine<long >);
def("round_long",&SPUC::round<long >);
def("saturate_long",&SPUC::saturate<long >);
def("signbit_long",&SPUC::signbit<long >);
def("toeplitz_long",&SPUC::toeplitz<long >);
}

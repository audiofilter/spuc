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

BOOST_PYTHON_MODULE(template_functions_double) {
def("conj_double",&SPUC::conj<double >);
def("magsq_double",&SPUC::magsq<double >);
def("quantize_double",&SPUC::quantize<double >);
def("raised_cosine_double",&SPUC::raised_cosine<double >);
def("root_raised_cosine_double",&SPUC::root_raised_cosine<double >);
def("round_double",&SPUC::round<double >);
def("saturate_double",&SPUC::saturate<double >);
def("signbit_double",&SPUC::signbit<double >);
def("toeplitz_double",&SPUC::toeplitz<double >);
}

// This code is automatically generated

#include <boost/python.hpp>
#include <boost/cstdint.hpp>
#include <boost/python/def.hpp>
#include <boost/python/args.hpp>
#include <boost/python/overloads.hpp>

using namespace boost::python;

#include <spuc/auto_corr.h>
#include <spuc/burg.h>
#include <spuc/convolve.h>
#include <spuc/fliplr.h>
#include <spuc/levdur.h>
#include <spuc/partial_convolve.h>

BOOST_PYTHON_MODULE(template_array_functions_long) {
def("auto_corr_long",&SPUC::auto_corr<long >);
def("burg_long",&SPUC::burg<long >);
def("convolve_long",&SPUC::convolve<long >);
def("fliplr_long",&SPUC::fliplr<long >);
def("levdur_long",&SPUC::levdur<long >);
def("partial_convolve_long",&SPUC::partial_convolve<long >);
}

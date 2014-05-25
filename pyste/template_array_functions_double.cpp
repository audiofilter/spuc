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

BOOST_PYTHON_MODULE(template_array_functions_double) {
def("auto_corr_double",&SPUC::auto_corr<double >);
def("burg_double",&SPUC::burg<double >);
def("convolve_double",&SPUC::convolve<double >);
def("fliplr_double",&SPUC::fliplr<double >);
def("levdur_double",&SPUC::levdur<double >);
def("partial_convolve_double",&SPUC::partial_convolve<double >);
}

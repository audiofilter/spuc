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

BOOST_PYTHON_MODULE(template_array_functions_float) {
def("auto_corr_float",&SPUC::auto_corr<float >);
def("burg_float",&SPUC::burg<float >);
def("convolve_float",&SPUC::convolve<float >);
def("fliplr_float",&SPUC::fliplr<float >);
def("levdur_float",&SPUC::levdur<float >);
def("partial_convolve_float",&SPUC::partial_convolve<float >);
}

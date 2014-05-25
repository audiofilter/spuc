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

BOOST_PYTHON_MODULE(template_array_functions_complex_float) {
def("auto_corr_complex_float",&SPUC::auto_corr<SPUC::complex<float> >);
def("burg_complex_float",&SPUC::burg<SPUC::complex<float> >);
def("convolve_complex_float",&SPUC::convolve<SPUC::complex<float> >);
def("fliplr_complex_float",&SPUC::fliplr<SPUC::complex<float> >);
def("levdur_complex_float",&SPUC::levdur<SPUC::complex<float> >);
def("partial_convolve_complex_float",&SPUC::partial_convolve<SPUC::complex<float> >);
}

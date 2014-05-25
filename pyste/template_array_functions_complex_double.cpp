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

BOOST_PYTHON_MODULE(template_array_functions_complex_double) {
def("auto_corr_complex_double",&SPUC::auto_corr<SPUC::complex<double> >);
def("burg_complex_double",&SPUC::burg<SPUC::complex<double> >);
def("convolve_complex_double",&SPUC::convolve<SPUC::complex<double> >);
def("fliplr_complex_double",&SPUC::fliplr<SPUC::complex<double> >);
def("levdur_complex_double",&SPUC::levdur<SPUC::complex<double> >);
def("partial_convolve_complex_double",&SPUC::partial_convolve<SPUC::complex<double> >);
}

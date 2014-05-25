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

BOOST_PYTHON_MODULE(template_array_functions_complex_long) {
def("auto_corr_complex_long",&SPUC::auto_corr<SPUC::complex<long> >);
def("burg_complex_long",&SPUC::burg<SPUC::complex<long> >);
def("convolve_complex_long",&SPUC::convolve<SPUC::complex<long> >);
def("fliplr_complex_long",&SPUC::fliplr<SPUC::complex<long> >);
def("levdur_complex_long",&SPUC::levdur<SPUC::complex<long> >);
def("partial_convolve_complex_long",&SPUC::partial_convolve<SPUC::complex<long> >);
}

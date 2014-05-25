// This code is automatically generated

#include <boost/python.hpp>
#include <boost/cstdint.hpp>
#include <boost/python/def.hpp>
#include <boost/python/args.hpp>
#include <boost/python/overloads.hpp>

using namespace boost::python;

#include <spuc/bpsk_dd_phase.h>
#include <spuc/bpsk_quadricorrelator.h>
#include <spuc/cp_afc.h>
#include <spuc/dd_symbol.h>
#include <spuc/nda_symbol.h>
#include <spuc/qpsk_dd_phase.h>
#include <spuc/qpsk_quadricorrelator.h>
#include <spuc/qpsk_rcfd.h>
#include <spuc/real_quantize.h>
#include <spuc/real_round.h>
#include <spuc/real_saturate.h>

BOOST_PYTHON_MODULE(real_template_functions_double) {
def("bpsk_dd_phase_double",&SPUC::bpsk_dd_phase<double >);
def("bpsk_quadricorrelator_double",&SPUC::bpsk_quadricorrelator<double >);
def("cp_afc_double",&SPUC::cp_afc<double >);
def("dd_symbol_double",&SPUC::dd_symbol<double >);
def("nda_symbol_double",&SPUC::nda_symbol<double >);
def("qpsk_dd_phase_double",&SPUC::qpsk_dd_phase<double >);
def("qpsk_quadricorrelator_double",&SPUC::qpsk_quadricorrelator<double >);
def("qpsk_rcfd_double",&SPUC::qpsk_rcfd<double >);
def("real_quantize_double",&SPUC::real_quantize<double >);
def("real_round_double",&SPUC::real_round<double >);
def("real_saturate_double",&SPUC::real_saturate<double >);
}

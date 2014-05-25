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

BOOST_PYTHON_MODULE(real_template_functions_long) {
def("bpsk_dd_phase_long",&SPUC::bpsk_dd_phase<long >);
def("bpsk_quadricorrelator_long",&SPUC::bpsk_quadricorrelator<long >);
def("cp_afc_long",&SPUC::cp_afc<long >);
def("dd_symbol_long",&SPUC::dd_symbol<long >);
def("nda_symbol_long",&SPUC::nda_symbol<long >);
def("qpsk_dd_phase_long",&SPUC::qpsk_dd_phase<long >);
def("qpsk_quadricorrelator_long",&SPUC::qpsk_quadricorrelator<long >);
def("qpsk_rcfd_long",&SPUC::qpsk_rcfd<long >);
def("real_quantize_long",&SPUC::real_quantize<long >);
def("real_round_long",&SPUC::real_round<long >);
def("real_saturate_long",&SPUC::real_saturate<long >);
}

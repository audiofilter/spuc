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

BOOST_PYTHON_MODULE(real_template_functions_float) {
def("bpsk_dd_phase_float",&SPUC::bpsk_dd_phase<float >);
def("bpsk_quadricorrelator_float",&SPUC::bpsk_quadricorrelator<float >);
def("cp_afc_float",&SPUC::cp_afc<float >);
def("dd_symbol_float",&SPUC::dd_symbol<float >);
def("nda_symbol_float",&SPUC::nda_symbol<float >);
def("qpsk_dd_phase_float",&SPUC::qpsk_dd_phase<float >);
def("qpsk_quadricorrelator_float",&SPUC::qpsk_quadricorrelator<float >);
def("qpsk_rcfd_float",&SPUC::qpsk_rcfd<float >);
def("real_quantize_float",&SPUC::real_quantize<float >);
def("real_round_float",&SPUC::real_round<float >);
def("real_saturate_float",&SPUC::real_saturate<float >);
}

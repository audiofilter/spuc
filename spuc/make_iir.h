#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <spuc/iir.h>
#include <spuc/butterworth_iir.h>
#include <spuc/chebyshev_iir.h>
#include <spuc/elliptic_iir.h>
namespace SPUC {
//! \file
//! \brief Design functions for iir filters
//! \author Tony Kirke
//! \ingroup template_functions iir

iir_coeff* design_iir(const std::string& iir_type, const std::string& filter_type, int order, float_type fcd,
                      float_type ripple = 0.1, float_type fstop = 0.5, float_type stopattn = -60) {
  iir_coeff* filt = new iir_coeff(order);
  if (iir_type == "butterworth") {
    if (filter_type == "LOW_PASS") {
      butterworth_iir(*filt, fcd, true, 3.0);
    } else if (filter_type == "HIGH_PASS") {
      butterworth_iir(*filt, fcd, false, 3.0);
    } else {
      std::cout << "Unsupported band type\n";
    }
  } else if (iir_type == "chebyshev") {
    if (filter_type == "LOW_PASS") {
      chebyshev_iir(*filt, fcd, true, ripple);
    } else if (filter_type == "HIGH_PASS") {
      chebyshev_iir(*filt, fcd, false, ripple);
    } else {
      std::cout << "Unsupported band type\n";
    }
  } else if (iir_type == "chebyshev") {
    if (filter_type == "LOW_PASS") {
      elliptic_iir(*filt, fcd, true, fstop, stopattn, ripple);
    } else if (filter_type == "HIGH_PASS") {
      elliptic_iir(*filt, fcd, false, fstop, stopattn, ripple);
    } else {
      std::cout << "Unsupported band type\n";
    }
  } else {
    std::cout << "Unknown iir type\n";
  }

  return filt;
}

template <class Numeric, class Coeff = float_type>
iir<Numeric, Coeff>* make_iir(const std::string& iir_type, const std::string& filter_type, int order, float_type fcd,
                              float_type ripple = 0.1, float_type fstop = 0.5, float_type stopattn = -60) {
  iir_coeff* filt = design_iir(iir_type, filter_type, order, fcd, ripple, fstop, stopattn);
  iir<Numeric, Coeff>* the_iir;
  the_iir = new iir<Numeric, Coeff>(*filt);
  delete filt;

  return the_iir;
}
}  // namespace SPUC

#ifndef SPUC_IIR_COMB
#define SPUC_IIR_COMB

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/quant.h>
#include <spuc/complex.h>
#include <spuc/quantiser.h>
#include <spuc/mixed_type.h>
#include <spuc/delay.h>
namespace SPUC {
//! \file
//! \brief  Template for IIR comb type filter with programmable delay and gain
//
//! \brief  Template for IIR comb type filter with programmable delay and gain
//! \author Tony Kirke
//! \image html iir_comb.png
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type> class iir_comb {
 protected:
  Coeff acc_gain;
  Coeff in_gain;
  Numeric out;
  delay<Numeric> dly;
  long delay_size;
  Numeric previous_out;
  Numeric previous_in;
  quantiser<Numeric> Q;

 public:
  iir_comb(Coeff A = 0, long delay = 2, long b = 0) : acc_gain(A), in_gain(1 - A), delay_size(delay), Q(b) {
    dly.set_size(delay);
    previous_in = previous_out = out = (Numeric)0;
  }
  void init(Coeff A, long delay) {
    in_gain = 1 - A;
    acc_gain = A;
    delay_size = delay;
    dly.set_size(delay);
  }

  void set_coeff(Coeff A) {
    in_gain = 1 - A;
    acc_gain = A;
  }
  //! Input new sample and calculate output
  Numeric clock(Numeric input) {
    typename mixed_type<Numeric, Coeff>::dtype sum;
    // Shift previous outputs and calculate new output
    sum = acc_gain * previous_out + in_gain * input;
    out = Q(sum);
    previous_out = dly.input(out);
    return (out);
  }
  //! Reset
  void reset() {
    previous_in = previous_out = out = (Numeric)0;
    dly.reset();
  }
};
}  // namespace SPUC
#endif

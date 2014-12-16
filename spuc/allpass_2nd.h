#ifndef SPUC_ALLPASS_2ND
#define SPUC_ALLPASS_2ND

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <iostream>
#include <fstream>
#include <spuc/complex.h>
#include <spuc/quantiser.h>
#include <spuc/mixed_type.h>
namespace SPUC {
//!
//! \file
//! \brief Template for 2nd order allpass filter<p>
//
//! \brief Template for 2nd order allpass filter<p>
//! \author Tony Kirke
//! \image html allpass_2nd.png
//! \ingroup double_templates Allpass
//!
//!  Template for 2nd order allpass filter<p>
//!   The filter is assumed to be a  2nd order allpass section
//!   of the form \f$ G(z) =  \frac{z^2 + b*z+a}{(a*z^2+b*z+1)} \f$
template <class Numeric, class Coeff = float_type> class allpass_2nd {
 protected:  // should be protected:
  long round_bits;
  Coeff b;
  Coeff a;
  Numeric in[3];

 public:
  Numeric fb2, fb1, fb0;
  Numeric scale;
  quantiser<Numeric> Q;
  quantiser<Numeric> OQ;
  typedef typename mixed_type<Numeric, Coeff>::dtype sum_type;

 public:
  allpass_2nd(Coeff B0, Coeff A0, long b = 0) : b(B0), a(A0), Q(b) {
    reset();
    round_bits = b;
    scale = (Numeric)(1 << round_bits);
  }
  allpass_2nd() : b(1), a(1), Q(0) {
    reset();
    round_bits = 0;
    scale = (Numeric)1;
  }
  void set_round_bits(long x) {
    round_bits = x;
    scale = (Numeric)(1 << round_bits);
  }
  void reset() { in[0] = in[1] = in[2] = fb2 = fb1 = fb0 = (Numeric)0; }
  void set_a(Coeff A0) { a = A0; }
  void set_b(Coeff B0) { b = B0; }
  Coeff get_a() { return (a); }
  Coeff get_b() { return (b); }
  void set_coeffs(Coeff B0, Coeff A0) {
    b = B0;
    a = A0;
  }
  //! Constructor reading coefficients from a file.
  allpass_2nd(const char* file) : Q(0) {
    std::ifstream iirf(file);
    iirf >> b;
    iirf >> a;
    iirf.close();
    reset();
  }
  //! Print out coefficients
  void print() {
    std::cout << "Allpass Coefficients B = " << b;
    std::cout << ", A =  " << a;
    std::cout << ".\n";
  }
  //! Input new sample and calculate output
  Numeric clock(Numeric input) {
    sum_type sum;
    // Shift inputs by one time sample and place new sample into array
    in[0] = in[1];
    in[1] = in[2];
    in[2] = input;
    // Shift previous outputs and calculate new output */
    fb0 = fb1;
    fb1 = fb2;

    sum = (a * (in[1] - fb1) + b * (in[2] - fb0) + in[0]);

    fb2 = Q(sum);
    return (OQ(sum));
  }
};
}  // namespace SPUC
#endif

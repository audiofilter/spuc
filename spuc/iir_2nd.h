#ifndef SPUC_IIR_2ND
#define SPUC_IIR_2ND

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <iostream>
#include <fstream>
#include <spuc/complex.h>
#include <spuc/quantiser.h>
#include <spuc/mixed_type.h>
namespace SPUC {
//! \file
//! \brief Template for 2nd Order IIR filter<p>
//
//! \brief Template for 2nd Order IIR filter<p>
//
//!   The filter is assumed to be a low pass 2nd order digital filter
//!   of the form \f$ G(z) =  \frac{b0*z^2 + b1*z+b2}{(z^2+a1*z+a2)} \f$
//! \image html iir_2nd.gif
//! \image latex iir_2nd.eps
//! \author Tony Kirke
//! \image html iir_2nd.png
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type> class iir_2nd {
 protected:  // should be protected:
  long round_bits;
  Coeff b0, b1, b2;
  Coeff a1, a2;
  Numeric in[3];
  quantiser<Coeff> Q;
  //  quantiser<Numeric>  OQ;
 public:
  Numeric fb2, fb1, fb0;
  //  Numeric scale;
  typedef typename mixed_type<Numeric, Coeff>::dtype sum_type;

 public:
  iir_2nd(Coeff B0, Coeff B1, Coeff B2, Coeff A1, Coeff A2, long b = 0) : b0(B0), b1(B1), b2(B2), a1(A1), a2(A2), Q(b) {
    reset();
    round_bits = b;
    fb0 = fb1 = fb2 = (Numeric)0;
    //	scale = (Numeric)(1<<round_bits);
  }
  iir_2nd(Coeff A1 = 0, Coeff A2 = 0) : b0(1), b1(2), b2(1), a1(A1), a2(A2), Q(0) {
    reset();
    round_bits = 0;
    fb0 = fb1 = fb2 = (Numeric)0;
    //	scale = 1;
  }
  void set_round_bits(long x) {
    round_bits = x;
    Q.set_bits(x);
    //	scale = (Numeric)(1<<round_bits);
  }
  int get_round_bits() { return (round_bits); }
  Coeff get_b0() { return (b0); }
  Coeff get_b1() { return (b1); }
  Coeff get_b2() { return (b2); }
  Coeff get_a1() { return (a1); }
  Coeff get_a2() { return (a2); }

  void reset() { in[0] = in[1] = in[2] = fb2 = fb1 = fb0 = (Numeric)0; }
  void set_a(Coeff A1, Coeff A2) {
    a1 = A1;
    a2 = A2;
  }
  void set_b(Coeff A1, Coeff A2) {
    b1 = A1;
    b2 = A2;
  }
  void set_coeffs(Coeff B0, Coeff B1, Coeff B2, Coeff A1, Coeff A2) {
    b0 = B0;
    b1 = B1;
    b2 = B2;
    a1 = A1;
    a2 = A2;
  }
  //! Constructor reading coefficients from a file.
  iir_2nd(const char* file) : Q(0) {
    std::ifstream iirf(file);
    iirf >> b0;
    iirf >> b1;
    iirf >> b2;
    iirf >> a1;
    iirf >> a2;
    iirf.close();
    reset();
  }
  //! Print out coefficients
  void print() {
    std::cout << "IIR Coefficients B0 = " << b0;
    std::cout << ", B1 =  " << b1;
    std::cout << ", B2 =  " << b2;
    std::cout << ", A0 =  1";
    std::cout << ", A1 =  " << a1;
    std::cout << ", A2 =  " << a2;
    std::cout << ".\n";
  }
  //! Input new sample and calculate output
  Numeric clock(Numeric input) {
    sum_type sum;
    // Shift inputs by one time sample and place new sample into array
    in[0] = in[1];
    in[1] = in[2];
    in[2] = input;
    // Shift previous outputs and calculate new output
    fb0 = fb1;
    fb1 = fb2;

    sum = (b0 * in[2] + b1 * in[1] + b2 * in[0] - a1 * fb1 - a2 * fb0);

    fb2 = Q(sum);
    return (fb2);
  }
};
}  // namespace SPUC
#endif

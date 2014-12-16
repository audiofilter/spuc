#ifndef SPUC_IIR
#define SPUC_IIR

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <spuc/iir_lpf1.h>
#include <spuc/iir_2nd.h>
#include <spuc/iir_coeff.h>
#include <spuc/quantiser.h>
#include <iostream>
#include <vector>
namespace SPUC {
//! \file
//! \brief  Template Class for iir filter
//
//! \brief Tempate Class for iir filter
//
//! consisting of first and second order filter sections
//! \author Tony Kirke
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type> class iir {
 public:
  long order;
  long odd;
  long n2;
  std::vector<iir_2nd<Numeric, Coeff> > sos;
  iir_lpf1<Numeric, Coeff> fos;
  Coeff gain;
  quantiser<Numeric> Q;
  typedef typename mixed_type<Numeric, Coeff>::dtype mult_type;

 public:
  //! ord = Filter order
  iir(iir_coeff& design) : sos(design.n2), fos(1) {
    order = design.order;
    n2 = design.n2;
    odd = design.odd;
    set_coeffs(design);
  }
  //! ord = Filter order
  iir(long ord = 1) : sos((ord + 1) / 2), fos(1) {
    // amax - attenuation at cutoff
    order = ord;
    n2 = (order + 1) / 2;
    odd = (order % 2);
  }
  void clear() { sos.resize(0); }
  void realloc(iir_coeff& design) {
    sos.resize(design.n2);
    order = design.order;
    n2 = design.n2;
    odd = design.odd;
    set_coeffs(design);
    reset();
  }

  //! Destructor
  ~iir() {}
  int stages() { return (n2); }
  //! Reset history
  void reset() {
    for (int j = odd; j < n2; j++) sos[j - odd].reset();
    if (odd) fos.reset();
  }
  //! Set 2nd order IIR coefficients
  void set_coeffs(iir_coeff& design) {
    if (design.state == 2) design.convert_to_ab();
    if (design.state == 3) {
      if (odd) fos.set_coeff(real(design.poles[0]));  // TBD
      for (int j = odd; j < n2; j++) {
        sos[j - odd].set_a(real(design.poles[j]), imag(design.poles[j]));
        sos[j - odd].set_b(real(design.zeros[j]), imag(design.zeros[j]));
      }
      gain = (Coeff)design.gain;
    } else {
      std::cout << "Error can not set coefficients";
      std::cout << "Design.state = " << design.state << "\n";
    }
  }
  //! Set 2nd order IIR coefficients
  void set_round_bits(int stage, int bits) {
    if (stage <= n2 && stage >= 0) {
      if (stage == n2) {
        if (odd)
          fos.set_round_bits(bits);
        else {
          std::cout << "Error non-existent stage\n";
        }
      } else { sos[stage].set_round_bits(bits); }
    } else { std::cout << "Error non-existent stage\n"; }
  }
  //! print coefficients
  void print() {
    if (odd) fos.print();
    for (int j = odd; j < n2; j++) sos[j - odd].print();
  }
  //! Clock in sample and get output.
  Numeric clock(Numeric in) {
    Numeric tmp = in;
    for (int i = odd; i < n2; i++) { tmp = sos[i - odd].clock(tmp); }
    if (odd) tmp = fos.clock(tmp);
    mult_type g = gain * tmp;
    return (Q(g));
  }
};
}  // namespace SPUC
#endif

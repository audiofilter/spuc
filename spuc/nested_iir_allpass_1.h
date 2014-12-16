#ifndef SPUC_NESTED_IIR_ALLPASS_1
#define SPUC_NESTED_IIR_ALLPASS_1

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/quant.h>
#include <spuc/allpass_2nd.h>
namespace SPUC {

template <class Numeric, class Coeff = float_type> class nested_iir_allpass_tmp {
 protected:
  //! The 2 1st order allpass filters
  int Delay;
  allpass_2nd<Numeric, Coeff> A0, A1;
  allpass_1<Numeric, Coeff> D0;
  Numeric prev_input;

 public:
  nested_iir_allpass_2(Coeff c0, Coeff c1, Coeff b0, Coeff b1, Coeff k) : A0(c0, c1), A1(b0, b1), D0(k) { reset(); }
  //! reset
  void reset() {
    A0.reset();
    A1.reset();
    prev_input = (Numeric)0;
    D0.reset();
  }
  //! Shift inputs by one time sample and place new sample into array
  Numeric clock(Numeric input) {
    Numeric out0, out1;

    out0 = A0.clock(input);
    prev_input = D0.clock(input);
    out1 = A1.clock(prev_input);

    return (out0 + out1);
    // Complimentary filter return(0.5*(out0 - out1));
  }
};
// template_instantiations: long; complex<long>; float_type; complex<float_type>

}  // namespace SPUC
#endif

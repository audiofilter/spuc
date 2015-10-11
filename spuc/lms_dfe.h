#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_utemplates
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/fir_adapt.h>
#include <spuc/spuc_math.h>
#include <spuc/base_type.h>
namespace SPUC {
//! \file
//! \brief Template Class for LMS Decision Feedback equalizer
//
//! \brief Template Class for LMS Decision Feedback equalizer
//
//! \author Tony Kirke
//! \image html lms_dfe.png
//! \ingroup double_utemplates equalizers
//! \author Tony Kirke
//! \image html lms_dfe.png
//! \ingroup double_utemplates comm
//! \image html lms_dfe.gif
//! \image latex lms_dfe.eps
template <class Numeric, class Coeff = double> class lms_dfe {
 public:
  typedef typename base_type<Numeric>::btype real_type;
  //! Feedforward FIR section
  fir_adapt<Numeric, Coeff> ff;
  //! Feedback FIR section
  fir_adapt<Numeric, Coeff> fb;
  //! Adaptation Gain
  real_type u;
  Numeric mid_tap;

 public:
  //! Constructor with feedforward size, feedback size and gain
  lms_dfe(char inf = 16, char inb = 0, real_type gain = 0, Numeric mid_val = 1) : u(gain) {
    mid_tap = mid_val;
    ff.set_size(inf);
    ff.set_gain(gain);
    if (inb > 0) {
      fb.set_size(inb);
      fb.set_gain(gain);
      ff.coeff[inf - 1] = mid_tap;
    } else {
      ff.coeff[inf / 2] = mid_tap;
    }
  }
  ~lms_dfe() {}
  void reset() {
    ff.reset();
    if (ff.num_taps > 0) {
      if (fb.num_taps > 0) {
        fb.reset();
        ff.settap(ff.num_taps - 1, mid_tap);
      } else {
        ff.settap(ff.num_taps / 2, mid_tap);
      }
    }
  }
  void set_ff_tap(long i, Numeric x) { ff.coeff[i] = x; }
  void set_fb_tap(long i, Numeric x) { fb.coeff[i] = x; }
  Coeff get_ff_tap(long x) { return (ff.coeff[x]); }
  Coeff get_fb_tap(long x) { return (fb.coeff[x]); }
  long ff_size() { return (ff.num_taps); }
  long fb_size() { return (fb.num_taps); }
  void set_gain(real_type g) {
    u = g;
    ff.set_gain(u);
    fb.set_gain(u);
  }
  // Perform convolutions
  Numeric update(Numeric in, Numeric slicer_output) {
    Numeric sff = 0;
    sff = ff.update(in);
    if (fb.num_taps > 0) sff += fb.update(slicer_output);
    return (sff);
  }
  // Update coefficients
  void update_taps_lms(Numeric err) {
    ff.update_lms(err);
    if (fb.num_taps > 0) fb.update_lms(err);
  }
};
}  // namespace SPUC

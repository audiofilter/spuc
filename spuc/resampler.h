#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/iir_allpass1_halfband.h>
#include <spuc/timing_nco.h>
#include <spuce/filters/lagrange.h>
namespace SPUC {
//! \file
//! \brief A resampling block using interpolator, halfband filter and NCO
//
//! \brief A resampling block using interpolator, halfband filter and NCO
//
//! Resampling block
//! This class uses
//! an interpolator
//! a halfband filter (for decimating by 2)
//! and a NCO
//! samples are input with each call to update,
//! but output samples are available when the
//! ready bit is set
//! The halfband filter is a simple IIR filter based on
//!  two first order allpass filters.
//! The interpolator is a Lagrange interpolating FIR
//! \author Tony Kirke
//! \ingroup templates examples
template <class Numeric> class resampler {
 public:
  bool ready;
  long sample2;
  spuce::lagrange<Numeric> interp;
  timing_nco symbol_nco;  //! Symbol NCO
  Numeric resampled;
  iir_allpass1_halfband<Numeric> half;  //! Halfband filter (decimate by 2)

  resampler(void) : interp(4), half(0.25, 0.75) {
    resampled = (Numeric)0;
    ready = 0;
  }
  Numeric update(Numeric input_data, long symbol_loop, long sym_clk) {
    float_type time1, time2;
    Numeric resampled1, resampled2;
    Numeric half_out;

    // Sampling NCO
    // Determine if 2nd sample should be processed
    sample2 = symbol_nco.run(symbol_loop, sym_clk);

    time1 = symbol_nco.get_off1();
    time2 = symbol_nco.get_off2();
    resampled1 = interp.update(input_data, time1);
    resampled2 = interp.rephase(time2);

    half_out = half.clock(resampled1);
    if (half.ready()) {
      ready = 1;
      resampled = half_out;
    } else {
      ready = 0;
      resampled = (Numeric)0;
    }

    // if 2nd sample should be used, send it through
    // the decimating halfband filter,
    // then check is output is ready
    if (sample2) {
      half_out = half.clock(resampled2);
      if (half.ready()) {
        ready = 1;
        resampled = half_out;
      }
    }

    return (resampled);
  }
};
}  // namespace SPUC

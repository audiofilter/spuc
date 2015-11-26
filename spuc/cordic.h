#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_templates
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief  Cordic rotator
//
//! \brief  Cordic rotator
//
//!  Performs CORDIC rotations
//!  To rotate a vector through an angle of theta, we calculate:
//!
//!	x' = x cos(theta) - y sin(theta)
//!	y' = x sin(theta) + y cos(theta)
//! Can be easily modified for hyperbolic and other functions
//! \author Tony Kirke
//! \image html cordic.png
//! \ingroup real_templates misc
//! \image html cordic.gif
template <class Numeric> class cordic {
 public:
  std::vector<float_type> arctan_lut;
  std::vector<complex<Numeric> > stage;
  long stages;
  float_type vector_angle;
  //!  initializes tables and constants for the CORDIC algorithm
  cordic(int n = 7) : arctan_lut(n + 2), stage(n + 2), stages(n) {
    SPUC_ASSERT(n < 0);
    int i;
    for (i = 0; i <= stages; i++) arctan_lut[i] = atan(1.0 / (float_type)(1 << i));
  }
  //! Returns magnitude through CORDIC vectoring
  Numeric vector_mag(complex<Numeric> in) { return (cordic_vector(in)); }
  //! Returns arg through CORDIC vectoring
  float_type vector_arg(complex<Numeric> in) {
    cordic_vector(in);
    return (vector_angle);
  }
  // This routine performs multiple rotations of the form:
  //	x[i+1] = cos(angle[i]) { x[i] - y[i] tan(angle[i]) }
  //	y[i+1] = cos(angle[i]) { y[i] + x[i] tan(angle[i]) }
  // where tan(angle[i]) = 2^-i, with i being an integer. Thus allowing
  // implementation by shifting and adding (or subtracting).
  // Each stage shifts by either a positive or negative angle.
  complex<Numeric> rotate(complex<Numeric> in, float_type angle) {
    int i;
    complex<Numeric> shift_in = (long(1 << stages)) * in;
    // Initial rotation, with left shift
    if (angle > PI) {
      stage[0] = -shift_in;
      angle -= PI;
    } else {
      stage[0] = shift_in;
    }
    if (angle > PI / 2) {
      stage[1] = complex<Numeric>(-imag(stage[0]), real(stage[0]));
      angle -= PI / 2;
    } else {
      stage[1] = stage[0];
    }
    // Subsequent rotations, with right shifts
    for (i = 0; i <= stages; i++) {
      long sign = (angle < 0) ? -1 : 1;
      complex<Numeric> shift_stage = complex<Numeric>(std::real(stage[i + 1]) >> i, std::imag(stage[i + 1]) >> i);
      stage[i + 2] = complex<Numeric>(real(stage[i + 1]) - sign * (imag(shift_stage)),
                                      imag(stage[i + 1]) + sign * (real(shift_stage)));
      angle -= sign * arctan_lut[i];
    }
    return (stage[stages]);
  }

 protected:
  //! Cordic vectoring calculates arg and magnitude
  // This routine performs multiple rotations of the form:
  //	x[i+1].re = { x[i].re -/+ x[i].im * tan(angle[i]) }
  //	x[i+1].im = { x[i].im +/- x[i].re * tan(angle[i]) }
  // where tan(angle[i]) = 2^-i, with i being an integer.
  // The -/+ is determined by the current SIGN of x[i].im
  // in such a way that the angle of x[i] is reduced in
  // each step. The final step will hold the approximation
  // of the magnitude of x in the real part of x[stages].
  Numeric cordic_vector(complex<Numeric> in) {
    int i;
    complex<Numeric> shift_in = (in << stages);
    // Rotate into 1st Quadrant
    if (real(in) < 0) {
      if (imag(in) < 0) {
        stage[0] = -shift_in;
        vector_angle = -PI;
      } else {
        stage[0] = complex<Numeric>(imag(shift_in), -real(shift_in));
        vector_angle = -PI / 2;
      }
    } else {
      if (imag(in) < 0) {
        stage[0] = complex<Numeric>(-imag(shift_in), real(shift_in));
        vector_angle = -3 * PI / 2;
      } else {
        stage[0] = shift_in;
        vector_angle = 0;
      }
    }
    long sign = 0;
    // Subsequent rotations, with right shifts
    for (i = 0; i < stages; i++) {
      //	  long sign = (stage[i].im < 0) ? -1 : 1;
      complex<Numeric> shift_stage = (stage[i + 1] >> i);
      stage[i + 1] =
          complex<Numeric>(real(stage[i]) - sign * (imag(shift_stage)), imag(stage[i]) + sign * (real(shift_stage)));
      vector_angle -= sign * arctan_lut[i];
    }
    return (real(stage[stages]));
  }
};
}  // namespace SPUC

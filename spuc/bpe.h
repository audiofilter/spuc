#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_double_templates
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/spuc_defines.h>
#include <spuc/spuc_math.h>
#include <vector>
#define RTD 2.0 / PI  // radian to decimal conversion factor
namespace SPUC {
//! \file
//! \brief Block Phase estimator
//
//! \brief Block Phase Estimator
//
//!  Unquantized BPE Calculate phase angle using a moving window
//!  <I>Notes:</I>
//!   Note that the BPE only cares about the phase of a vector, and not on the
//!    actual vector magnitude.  This results in a degradation of the average bpe
//!    vector magnitude as Eb/No decreases.
//! \author Tony Kirke
//! \ingroup real_double_templates comm
template <class Numeric, class Coeff = double> class bpe {
  std::vector<complex<Numeric> > bit;  //! array containing previous inputs
  int quad_prev;                       //! Previous quadrant
  int oqtstate;                        //! quadrant cross-over indicator
  float_type ang;                      //! current averaged angle
  char nbpe;                           //! length of BPE

 public:
  float_type angle() { return (ang); }  //! current averaged angle
  //! Reference Vector
  complex<Numeric> refvect(void) { return (polar(1.0, -ang)); }
  // Constructor
  bpe(char len = 16) : bit(len), nbpe(len) {
    oqtstate = 0;
    quad_prev = 0;
    for (char i = 0; i < nbpe; i++) bit[i] = complex<Numeric>(0, 0);
  }
  //! Perform BPE but don't calculate output
  void clock(const complex<Numeric>& in) {
    float_type out_angle, out_angle4;
    int quad_now;
    char i;

    for (i = nbpe; i > 0; i--) bit[i] = bit[i - 1];
    bit[0] = in;

    complex<Coeff> vx(0, 0);

    for (i = 0; i < nbpe; i++) vx += polar(1 / (float_type)nbpe, fq_angle(bit[i]));
    out_angle4 = arg(vx);
    if (out_angle4 <= 0.) out_angle4 += TWOPI;

    // take out bias due to inacurracy in RTD since out_angle4 is always < 2*PI
    if (out_angle4 >= TWOPI) out_angle4 = TWOPI - 0.000001;

    // output quadrant translator
    quad_now = (int)(out_angle4 * RTD);
    quad_now = quad_now % 4;

    // keep track of quadrant cross-overs
    if ((quad_prev == 3) && (quad_now == 0)) {
      oqtstate += 1;
      oqtstate = oqtstate % 4;
    } else if ((quad_prev == 0) && (quad_now == 3)) {
      oqtstate += 3;
      oqtstate = oqtstate % 4;
    }
    // end output quadrant translator

    out_angle = (out_angle4 / 4.0 - PI / 4.0);

    /*  compensate for quadrant cross-overs */
    out_angle += oqtstate * PI / 2;
    if (out_angle <= 0.) out_angle += TWOPI;
    /*  keep track of the phase introduced */
    ang = out_angle;
    /*  store the current quadrant number */
    quad_prev = quad_now;
  }
  //
  // Put vector into first quadrant so that it can be quadrupled
  // return angle value in first quadrant
  float_type fq_angle(const complex<Numeric>& pid) {
    complex<Numeric> pid1;
    float_type xangle;

    if ((real(pid) >= 0) & (imag(pid) >= 0))
      pid1 = pid;
    else if ((real(pid) >= 0) & (imag(pid) < 0))
      pid1 = pid * complex<Numeric>(0, 1);
    else if ((real(pid) < 0) & (imag(pid) >= 0))
      pid1 = pid * complex<Numeric>(0, -1);
    else
      pid1 = -pid;

    xangle = (float_type)(4.0 * arg(pid1));
    while (fabs(xangle) > TWOPI) {
      if (xangle > 0)
        xangle -= TWOPI;
      else
        xangle += TWOPI;
    }
    if (xangle < 0.) xangle += 2 * PI;
    return (xangle);
  }
  //
  //  Phase rotation
  //  Rotate phase angle of I and Q data relative to the bpe phase estimate
  //  Get output for Complex float_type input
  //! Perform BPE and return transformed input
  complex<Numeric> output(const complex<Numeric>& in) {
    clock(in);
    return (in * refvect());
  }
};
}  // namespace SPUC

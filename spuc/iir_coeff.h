#ifndef SPUC_IIR_COEFF
#define SPUC_IIR_COEFF

/*
    Copyright (C) 2014 Tony Kirke

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <spuc/smart_array.h>
namespace SPUC {
//!
//!  \file
//!  \brief  Class for iir filter design
//
//!  \brief  Class for iir filter design
//! \author Tony Kirke
//!  \ingroup classes iir
class iir_coeff
{
public:
  long order;
  long odd;
  long n2;
  smart_array<complex<float_type> > poles;
  smart_array<complex<float_type> > zeros;
  smart_array<float_type > a_tf;
  smart_array<float_type > b_tf;
  float_type gain;
  float_type hpf_gain;
  long state;
  long tf_state;
  long ap_state;
  
public:
  //! ord = Filter order
  iir_coeff(long ord=1);
  //! Destructor
  ~iir_coeff();
  //! Do bilinear transformation
  void bilinear();
  void bilinear2();
  void convert_to_ab();
  void z_root_to_ab(smart_array<complex<float_type> > z);
  void pz_to_ap(); 
  void ab_to_tf();
  void p2_to_poly(smart_array<complex<float_type> > ab,
				  smart_array<float_type>& tf);
  smart_array<float_type> pz_to_poly(smart_array<complex<float_type> > z);
  complex<float_type> get_root(long i);
  complex<float_type> get_zero(long i);
  float_type get_a(long i);
  float_type get_b(long i);
  float_type get_coeff_a(long i);
  float_type get_coeff_b(long i);
  float_type max_abs_coeff();
  void quantize(int bits);
  float_type freqz_mag(float_type freq);
};
// template_instantiations: float_type, complex<float_type>
} // namespace SPUC
#endif

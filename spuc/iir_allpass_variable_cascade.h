#ifndef SPUC_IIR_ALLPASS_VARIABLE_CASCADE
#define SPUC_IIR_ALLPASS_VARIABLE_CASCADE

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
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <spuc/quant.h>
#include <spuc/circ_buffer.h>
#include <spuc/allpass.h>
#include <spuc/elliptic_allpass.h>
#include <spuc/qnoise.h>
#include <iostream>
namespace SPUC {

//! \file
//! \brief  Template Class for iir filter consisting of 1st order allpass sections
//
//! This is a halfband IIR filter with two branches of cascades of
//! 1st order allpass sections
//! \author Tony Kirke
//! \image html iir_allpass1_cascade.png
//! \author Tony Kirke
//! \ingroup double_templates double_templates iir
template <class Numeric, class Coeff=float_type> class iir_allpass_variable_cascade
{
public:
  long stages;
  allpass< Numeric,Coeff > A0;
  allpass< Numeric,Coeff > A1;
#ifdef OLD_WAY_B
  delay<Numeric> prev_input;
#else
  circ_buffer<Numeric> prev_input;
#endif
  bool hpf;
  Numeric out0,out1;
  
public:
  //! n = Filter stages
  iir_allpass_variable_cascade(float_type fp=0, int n=1, int dly=2, int coeff_bits=0) {
	int j=0;
	int k=0;
	hpf = false;
	prev_input.set_size(dly/2);
	stages = n;
	//prev_input = (Numeric)0;
	qnoise<Coeff> Quantize((char)coeff_bits);
	if (stages > 0) {
	  std::vector<float_type> a0(stages);
	  std::vector<float_type> a1(stages);
	  elliptic_allpass(a0,a1, fp, stages);
	  j = (stages+1)/2;
	  k = stages - j;
	  // CONVERT FROM DOUBLE to COEFF
	  std::vector<Coeff> a0c(stages);
	  std::vector<Coeff> a1c(stages);
	  if (coeff_bits != 0) {
		// Don't use convert but quantized float_type coefficients
		for (int i=0;i<stages;i++) {
		  a0c[i] = (Coeff)(Quantize(a0[i]));
		  a1c[i] = (Coeff)(Quantize(a1[i]));
		}
	  } else {
		for (int i=0;i<stages;i++) {
		  a0c[i] = (Coeff)a0[i];
		  a1c[i] = (Coeff)a1[i];
		}
	  }
	  A0.init(a0c, j, dly);
	  A1.init(a1c, k, dly);
	}
  }

  //! n = Filter stages
  void set_coeffs(float_type fp, int n=1, int dly=2, int coeff_bits=0) {
	int j=0;
	int k=0;
	stages = n;
	prev_input.set_size(dly/2);
	prev_input.reset(); //= (Numeric)0;
	qnoise<Coeff> Quantize((char)coeff_bits);
	if (stages > 0) {
	  std::vector<float_type> a0(stages);
	  std::vector<float_type> a1(stages);
	  elliptic_allpass(a0, a1, fp, stages);
	  j = (stages+1)/2;
	  k = stages - j;
	  // CONVERT FROM DOUBLE to COEFF
	  std::vector<Coeff> a0c(stages);
	  std::vector<Coeff> a1c(stages);
	  if (coeff_bits != 0) {
		// Don't use convert but quantized float_type coefficients
		for (int i=0;i<stages;i++) {
		  a0c[i] = (Coeff)(Quantize(a0[i]));
		  a1c[i] = (Coeff)(Quantize(a1[i]));
		}
	  } else {
		for (int i=0;i<stages;i++) {
		  a0c[i] = (Coeff)a0[i];
		  a1c[i] = (Coeff)a1[i];
		}
	  }

	  A0.init(a0c, j, dly);
	  A1.init(a1c, k, dly);
	}
  }

  Coeff get_a0(int i) {
	int j = (stages+1)/2;
	if ((i<j) && (i>-1)) return(A0.ap[i].get_coefficient()); 
	else return(0);
  }
  Coeff get_a1(int i) {
	int j = (stages+1)/2;
	if ((i<stages-j) && (i>-1)) return(A1.ap[i].get_coefficient()); 
	else return(0);
  }
  //! Destructor
  ~iir_allpass_variable_cascade() {
  }
  //! Reset history
  void reset() {
	A0.reset();
	A1.reset();
	prev_input.reset();
 } 
  void set_hpf(bool h) { hpf = h; }
  //! Clock in sample and get output.
  Numeric clock(Numeric input) {
	out0 = A0.clock(input);
	out1 = A1.clock(input);
	//	std::cout << "IAVC out1 = " << out1 << " ";
#ifdef OLD_WAY_B
	out1 = prev_input.input(out1);
#else
	prev_input.input(out1);
    out1 = prev_input.last();
#endif
	//	std::cout << out1 << "\n";
	if (hpf) {
	  return(round((out0 - out1),1));
	} else {
	  return(round((out0 + out1),1));
	}
  }
  //! Clock in sample and get output.
  Numeric get_hp_out() { return(round((out0 - out1),1));  }
};
// template_instantiations: float_type


} // namespace SPUC
#endif

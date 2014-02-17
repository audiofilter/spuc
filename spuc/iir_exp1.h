#ifndef SPUC_IIR_EXP1
#define SPUC_IIR_EXP1

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
#include <iostream>
#include <fstream>
#include <spuc/complex.h>
#include <spuc/quantiser.h>
#include <spuc/mixed_type.h>
namespace SPUC {
//! \file
//! \brief  Template Class for 1st Order lowpass iir filter
//
//! \brief  Template Class for 1st Order lowpass iir filter
//
//!   The filter is the first order low pass digital filter given by
//!   \f$ G(z) =  \frac{1+z^-1}{1-az^-1} \f$ <p>where a is real and |a| < 1
//!   Note: Not normalized
//! \author Tony Kirke
//! \ingroup double_templates iir
template <class Numeric, class Coeff=float_type> class iir_exp1
{
protected:   
  Coeff gain;                    
  Numeric out;
  Numeric previous_out;
  Numeric previous_in;
  quantiser<Numeric> Q;
  
public:
  iir_exp1(Coeff A=0, long b=0) : gain(A), Q(b) {
	previous_in = previous_out = out = (Numeric)0 ; }
  void set_coeff(Coeff A) { gain=A;}
  void set_round_bits(long x) {	Q.set_bits(x);  }
  //! Constructor reading coefficient from a file.
  iir_exp1(const char* file) : Q(0) {
	std::ifstream iirf(file); 
	iirf >> gain;
	iirf.close();
	previous_in = previous_out = out = (Numeric)0;
  }             
  //! Print out coefficients
  void print() { std::cout << "IIR Coefficient gain = " << gain << "\n";}
  //! Input new sample and calculate output
  Numeric clock(Numeric input) {
	typename mixed_type<Numeric,Coeff>::dtype sum;
	// Shift previous outputs and calculate new output */
	sum = gain*previous_out + (1-gain)*input;
	out = Q(sum);
	previous_out = out;
	previous_in = input;
	return(out);
  }
  //! Reset
  void reset() {
	previous_in = previous_out = out = (Numeric)0;
  }
};                                               
} // namespace SPUC
#endif

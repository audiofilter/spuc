#ifndef SPUC_ALLPASS_1
#define SPUC_ALLPASS_1

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
#include <spuc/delay.h>
#include <spuc/circ_buffer.h>
namespace SPUC {
//! 
//! \file
//! \brief  Template class for 1st order allpass filter with programmble gain and delay
//
//! \brief  Template class for 1st order allpass filter with programmble gain and delay
//
//! Template class for 1st-order Allpass filter.
//! The filter is a "first-order" Allpass section of 
//! the form  G(z,n) =  (a*z^n + 1)/(z^n+a)
//! The delay n can be specified
//! \image html allpass_1.gif
//! \image latex allpass_1.eps
//! \author Tony Kirke
//! \image html allpass_1.png
//! \ingroup double_templates Allpass
template <class Numeric,class Coeff=float_type> class allpass_1
{
 protected:  
  //! number of unit sample delays
  long size;
  long round_bits;
  float_type gain;
#ifdef OLD_WAY_A
  delay<Numeric> mult;
  delay<Numeric> sum;
#else
  circ_buffer<Numeric> mult;
  circ_buffer<Numeric> sum;
#endif
  quantiser<Numeric>  Q;
  typedef typename mixed_type<Numeric,Coeff>::dtype sum_type;
        
 public:
  //! Constructor with gain and delay
  allpass_1(Coeff Gain=0, long s=1, long b=0) : Q(b) { 
    gain = Gain;
    size = s;
	round_bits = b;
    mult.set_size(size);
    sum.set_size(size);
  }
  Coeff get_coefficient(void) { return((Coeff)(gain)); }
  //! Reset
  void reset() {
	mult.reset();
	sum.reset();
  }
    void set_gain(Coeff Gain) { gain = Gain; }
  //! Initializes gain and delay
  void init(Coeff Gain, long s) { 
	gain = Gain;
	size = s;
	mult.set_size(size);
	sum.set_size(size);
  }
  //! Shift inputs by one time sample and place new sample into array
  Numeric clock(Numeric input) {
	Numeric current_mult,out;
	Numeric current_sum;
	sum_type mult_gain;

	out = sum.check(size-1);
	current_sum = (input + mult.check(size-1));
	mult_gain = -gain*current_sum;

	current_mult = Q(mult_gain);
	out -= current_mult;
	// update delay lines
	mult.input(current_mult);
	sum.input(current_sum);
	return(out);
  }
};                                               
} // namespace SPUC
#endif

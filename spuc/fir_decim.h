#ifndef SPUC_FIR_DECIM
#define SPUC_FIR_DECIM

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
#include <spuc/fir.h>
namespace SPUC {
//! \file
//! \brief template class for fir decimation based on FIR class
//
//! \brief template class for fir decimation based on FIR class
//
//! created to support polyphase FIR decimation
//! \author Tony Kirke
//! \ingroup double_templates fir
template <class Numeric,class Coeff=float_type> class fir_decim : public fir<Numeric,Coeff>
{
  using SPUC::fir<Numeric,Coeff>::num_taps;
  using SPUC::fir<Numeric,Coeff>::coeff;
  using SPUC::fir<Numeric,Coeff>::z;
  using SPUC::fir<Numeric,Coeff>::read_taps;
  using SPUC::fir<Numeric,Coeff>::Q;
  typedef typename base_type<Numeric>::btype Numeric_base;
  typedef typename mixed_type<Numeric,Coeff>::dtype sum_type;
public: 
	//! Constructor
	fir_decim<Numeric,Coeff>(void) { }
	fir_decim<Numeric,Coeff>(long n) : fir<Numeric,Coeff>(n) {	}
	fir_decim<Numeric,Coeff>(const char* file) { read_taps(file); }
	
	void input(Numeric in) {
		int i;                                           
		// Update history of inputs
		for (i=num_taps-1;i>0;i--) z[i] = z[i-1];  
		// Add new input
		z[0] = in;   
	}
	//! Phase increments when in automatic mode
	//! Otherwise phase does not change
	Numeric decim(void) {
	  sum_type sum(0);
	  // Perform FIR
	  Numeric output;
	  int i;
	  for (i=0;i<num_taps;i++) sum += coeff[i]*z[i];

	  output = Q(sum);
	  return(output); 
	}
};	
} // namespace SPUC
#endif

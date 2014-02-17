#ifndef SPUC_FIXED_DELAY
#define SPUC_FIXED_DELAY

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
#include <spuc/spuc_defines.h>
#include <spuc/smart_array.h>
namespace SPUC {
//! \file
//! \brief  Template class for Delay line with Fixed Delay
//
//! \brief  Template class for Delay line with Fixed Delay
//
//! Template class for a Delay line (primitive used in other classes)
//!  Allows user to check at various points in delay line,
//!  but default use is a pure delay.
//! \author Tony Kirke
//! \ingroup double_templates misc
//! \image html delay.gif
//! \image latex delay.eps
template <class Numeric, int D> class fixed_delay 
{
 public: 
  long NumTaps;
 protected:
  Numeric z[D+1]; 
      
 public: 
  //! Constructor
  fixed_delay() : NumTaps(D+1) {
	for (int i=0;i<NumTaps;i++) z[i] = (Numeric)0;
  }
  void reset(void) { for (int i=0;i<NumTaps;i++) z[i] = (Numeric)0; }
  //! Get delay at tap i
  Numeric check(long i) {
	SPUC_ASSERT(i<=this->NumTaps);
	return(z[i]); 
  }
  //! Look back in delay line by i samples
  Numeric checkback(long i) { 
	SPUC_ASSERT(i<=this->NumTaps);
	return(z[NumTaps-1-i]); 
  }
  //! Get last tap
  Numeric last() { return(z[NumTaps-1]);}
  //! Clock in new input sample  
  Numeric input(Numeric in) {
	int i;                                           
	// Update history of inputs
	for (i=NumTaps-1;i>0;i--) z[i] = z[i-1];  
	// Add new input
	z[0] = in;   
	return(z[NumTaps-1]);
  }
  //! Clock in new sample and get output from delay line
  inline Numeric update(Numeric in) {
	input(in);
	return(z[NumTaps-1]);
  }	
};
} // namespace SPUC
#endif

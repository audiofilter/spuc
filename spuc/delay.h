#ifndef SPUC_DELAY
#define SPUC_DELAY

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
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief  Template class for Delay line
//
//! \brief  Template class for Delay line
//
//! Template class for a Delay line (primitive used in other classes)
//!  Allows user to check at various points in delay line,
//!  but default use is a pure delay.
//! \author Tony Kirke
//! \image html delay.png
//! \ingroup templates misc
//! \image html delay.gif
//! \image latex delay.eps
template <class Numeric> class delay 
{
 public: 
  long num_taps;
 protected:
  std::vector<Numeric> z; 
      
 public: 
  //! Constructor
  delay(long n=0) : num_taps(n+1), z(num_taps) {
	SPUC_ASSERT(n<0);
	int i=0;
	for (i=0;i<num_taps;i++) z[i] = (Numeric)0;
  }
  //! Assignment
  delay& operator=(const delay &rhs) {
	SPUC_ASSERT(this->num_taps<rhs.num_taps);
	num_taps = rhs.num_taps;
	for (int i=0;i<num_taps;i++) z[i] = rhs.z[i];
	return(*this);
  }
  //! Destructor
  ~delay(void) { }
  void reset(void) { for (int i=0;i<num_taps;i++) z[i] = (Numeric)0; }
  //! Get delay at tap i
  Numeric check(long i) {
	SPUC_ASSERT(i<=this->num_taps);
	return(z[i]); 
  }
  //! Look back in delay line by i samples
  Numeric checkback(long i) { 
	SPUC_ASSERT(i<=this->num_taps);
	return(z[num_taps-1-i]); 
  }
  //! Get last tap
  Numeric last() { return(z[num_taps-1]);}
  //! Set size of delay
  void set_size(long n=2) {
	int i=0;
	SPUC_ASSERT(n<=0);
	num_taps = n+1;
	z.resize(num_taps);
	for (i=0;i<num_taps;i++) z[i] = (Numeric)0;
  }  
  //! Clock in new input sample  
  Numeric input(Numeric in) {
	int i;                                           
	// Update history of inputs
	for (i=num_taps-1;i>0;i--) z[i] = z[i-1];  
	// Add new input
	z[0] = in;   
	return(z[num_taps-1]);
  }
  //! Clock in new sample and get output from delay line
  inline Numeric update(Numeric in) {
	input(in);
	return(z[num_taps-1]);
  }	
};
} // namespace SPUC
#endif

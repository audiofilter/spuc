#ifndef SPUC_CIC
#define SPUC_CIC

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
#include <spuc/complex.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief   class for CIC digital filter
//
//! \brief   class for CIC digital filter
//
//!  Implementation for cascaded integrator comb filters
//!  This implementation provides for both decimation and
//!  interpolation filtering. Registers are signed long and
//!  the default number of stages is 3.
//! \author Tony Kirke
//! \ingroup templates fir interpolation
//! \image html cic.gif
//! \image latex cic.eps
template <class Numeric> class cic
{
 protected:
  std::vector<Numeric> diff; //! Differentiators
  std::vector<Numeric> nacc; //! Accumulators
  std::vector<Numeric> prev; //! Previous values
  char stages; //! Number of stages
 public:                         
  //! Constructor
  cic(char n=3) : diff(n), nacc(n), prev(n), stages(n)
  {
	SPUC_ASSERT(n<1);
	int i;
	for (i=0;i<stages;i++) nacc[i] = diff[i] = prev[i] = (Numeric)0;
  }
  //! Reset
  void reset() { 	
	for (int i=0;i<stages;i++) nacc[i] = diff[i] = prev[i] = (Numeric)0;
  }
  //! To change the number of stages dynamically
  void num_stages(char n)
  {
	int i;
	SPUC_ASSERT(n<1);
	stages = n; 
	nacc.resize(n);
	diff.resize(n);
	prev.resize(n);
	for (i=0;i<stages;i++) nacc[i] = diff[i] = prev[i] = (Numeric)0;
  }
  //! For CIC interpolation, non-zero dump implies new input
  Numeric interpolate(Numeric in=0, signed char dump=0) {
	char i;
	if (dump) {
	  diff[0] = in - prev[0];
	  prev[0] = in;
	  for (i=1;i<stages;i++) {
		diff[i] = diff[i-1] - prev[i];
		prev[i] = diff[i-1];
	  }
	  nacc[0] += diff[stages-1];
	}  
	for (i=0;i<(stages-1);i++) nacc[i+1] += nacc[i];
	return(nacc[stages-1]);
  } 
  //! For CIC decimation, non-zero dump implies output required
  Numeric decimate(Numeric in, signed char dump) {
	char i;
	nacc[0] += in;
	for (i=0;i<(stages-1);i++) nacc[i+1] += nacc[i];
	if (dump) {
	  diff[0] = nacc[stages-1] - prev[0];
	  prev[0] = nacc[stages-1];
	  for (i=1;i<stages;i++) {
		diff[i] = diff[i-1] - prev[i];
		prev[i] = diff[i-1];
	  }
	}
	return(diff[stages-1]);
  }
};
} // namespace SPUC
#endif

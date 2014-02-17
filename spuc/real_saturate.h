#ifndef SPUC_REAL_SATURATE
#define SPUC_REAL_SATURATE

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
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
namespace SPUC {
//! \file
//! \brief Templated saturation functions
//
//! \brief Templated saturation functions
//! \author Tony Kirke
//! \ingroup real_template_functions misc
template <class T> T real_saturate(T in, long bits);
//! \file
//! \brief Templated saturation functions
//
//! \brief Templated saturation functions
//! \author Tony Kirke
//! \ingroup real_template_functions misc
template <>  inline long real_saturate(long in, long bits)
{
  long low_mask = ((1<<(bits-1)) - 1);
  if (ABS(in) > low_mask) return((in>0) ? low_mask : ~low_mask);
  else return(in);
}  
template <>  inline int real_saturate(int in, long bits)
{
  int low_mask = ((1<<(bits-1)) - 1);
  if (ABS(in) > low_mask) return((in>0) ? low_mask : ~low_mask);
  else return(in);
}  
template <>  inline double real_saturate(double in, long bits)
{
  int low_mask = ((1<<(bits-1)) - 1);
  if (ABS(in) > (double)low_mask) {
	int lm =  (in<0) ? ~low_mask : low_mask;
	return(double(lm));
  } else return(in);
}  
template <>  inline float real_saturate(float in, long bits)
{
  int low_mask = ((1<<(bits-1)) - 1);
  if (ABS(in) > (float)low_mask) {
	int lm =  (in<0) ? ~low_mask : low_mask;
	return(float(lm));
  } else return(in);
}  
} // namespace SPUC
#endif

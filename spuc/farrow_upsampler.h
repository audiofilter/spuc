#ifndef SPUC_FARROW_UPSAMPLER
#define SPUC_FARROW_UPSAMPLER

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
#include <spuc/farrow.h>
namespace SPUC {
//! \file
//! \brief Upsampler/interpolator using farrow structure
//
//! \brief Upsampler/interpolator using farrow structure
//
//! Essentially a wrapper around farrow to allow one to
//! upsample by specifing a fractional time increment
//! input should always be available, need_sample returns
//! 1 when the input needs to be update for next call
//! \author Tony Kirke
//! \ingroup classes examples interpolators
class farrow_upsampler {

public:
  float_type time_offset;
  farrow<float_type> INTERP;
  
  int need_sample(float_type t_inc,float_type x);
  float_type output(float_type t_inc);
  farrow_upsampler(int order=4);
};
} // namespace SPUC
#endif

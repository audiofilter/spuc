#ifndef SPUC_QUANTIZED_TYPE
#define SPUC_QUANTIZED_TYPE

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
// from directory: spuc_traits
#include <spuc/spuc_types.h>
#include <spuc/spuc_typedefs.h>
namespace SPUC {
//! \file
//! \brief Determine quantized version of particular type, i.e complex<double> -> complex<long>, etc
//
//! \brief Determine quantized version of particular type, i.e complex<double> -> complex<long>, etc
//! \author Tony Kirke,  Copyright(c) 2005
//! \author Tony Kirke
//! \ingroup traits traits 
template <typename T> class quantized_type {
public:
  typedef long dtype;
};
template <typename T> class quantized_type<complex<T> > {
 public:
  typedef complex<long> dtype;
};
// template_instantiations: double, long, int_s
} // namespace SPUC
#endif

#ifndef SPUC_BASE_TYPE
#define SPUC_BASE_TYPE

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
#include <spuc/spuc_typedefs.h>
#ifdef USE_STD_COMPLEX
#include <complex>
using std::complex;
#endif
namespace SPUC {
//! Trait classes for type transformations/conversions
//! \author Tony Kirke,  Copyright(c) 2005
//
//! \file
//! \brief Determine base class for complex, builtin, sint, etc, classes
//
//! \brief Determine base class for complex, builtin, sint, etc, classes
//! \author Tony Kirke
//! \ingroup traits traits
template <typename T> class base_type {
public:
  typedef T btype;
};
template <typename T> class base_type<complex<T> > {
public:
  typedef T btype;
};
#ifndef NO_SINT
template <int T> class base_type<sint<T> > {
public:
  typedef int_s btype;
};
#endif
#ifndef NO_INT_S
template <> class base_type<int_s> {
public:
  typedef int_s btype;
};
#endif
#ifndef NO_FPINT
template <int T,int M> class base_type<fpint<T,M> > {
public:
  typedef double btype;
};
#endif
#ifndef NO_VFIXED
template <> class base_type<vfixed> {
public:
  typedef double btype;
};
#endif
#ifndef NO_VFLOAT
template <> class base_type<vfloat> {
public:
  typedef double btype;
};
#endif
#ifndef NO_VLOG
template <> class base_type<vlog> {
public:
  typedef double btype;
};
#endif
#ifndef NO_FXD
template <> class base_type<fxd> {
public:
  typedef double btype;
};
#endif
#ifndef NO_BUILTIN
template <typename T> class base_type<builtin<T> > {
public:
  typedef T btype;
};
#endif
} // namespace SPUC
#endif

#ifndef SPUC_FUNDTYPE
#define SPUC_FUNDTYPE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_traits
namespace SPUC {
//! \author Tony Kirke,  Copyright(c) 2005
//! \file
//! \brief Determine fundamental type when using builtin template
//
//! \brief Determine fundamental type when using builtin template
//! \author Tony Kirke
//! \ingroup traits traits
template <typename T> class fundtype {
 public:
  typedef T ftype;
};
template <typename T> class fundtype<builtin<T> > {
 public:
  typedef T ftype;
};
}  // namespace SPUC
#endif

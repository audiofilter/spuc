#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
namespace SPUC {
//! \author Tony Kirke,  Copyright(c) 2005
//! \file
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

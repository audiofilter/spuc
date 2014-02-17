#ifndef SPUC_SMART_ARRAY
#define SPUC_SMART_ARRAY

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
#include "boost/shared_array.hpp"
namespace SPUC {
//! author="Tony Kirke" *
//! SPUC - Signal processing using C++ - A DSP libraryy

//! 
//!  \file 
//!  \brief wrapper for boost shared array that keeps track of 
//!  number of elements
template<class T> class smart_array : public boost::shared_array<T> {
 public:
  //! Default constructor
  smart_array() {} 
  //! Create an smart_array of size n
  smart_array(long n) : boost::shared_array<T>(new T[n]) {
	elements = n;
  }
  void resize(long n) { 
	elements = n;
	boost::shared_array<T>::reset(new T[n]); 
  }
  long len() const { return(elements); }
 private:
  long elements;
};
} // namespace SPUC
#endif

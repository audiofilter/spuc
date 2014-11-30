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
//! author="Tony Kirke" *
//! SPUC - Signal processing using C++ - A DSP libraryy
//! 
//!  \file 
//!  \brief wrapper for shared pointer that keeps track of number of elements
#ifndef NO_BOOST
#include "boost/shared_array.hpp"
#endif
namespace SPUC {
	template<class T> class smart_array {
	public:
		//! Default constructor
		smart_array() {
			elements=0;
		} 
		//! Create an smart_array of size n
		smart_array(long n) {
			pointer.reset(new T[n]);
			elements = n;
		}
		void resize(long n) { 
			elements = n;
			pointer.reset(new T[n]); 
		}
		long len() const { return(elements); }
		// observers
		T& operator[](size_t i) const {
			return pointer[i];
		}
	private:
#ifndef NO_BOOST
		boost::shared_array<T> pointer;
#else
		std::unique_ptr<T []> pointer;
#endif
		long elements;
	};
} // namespace SPUC
#endif

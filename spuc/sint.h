#ifndef SPUC_SINT
#define SPUC_SINT

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
// from directory: spuc_n_templates
#include <spuc/spuc_types.h>
#include <spuc/int_s.h>
#include <iostream>
namespace SPUC {
//! \file
//! \brief Template class for signed integers (<33 bits).
//
//! \brief Template class for signed integers (<33 bits).
//
//!   Template class for signed integers (<33 bits). The template parameter 
//!   is the number of bits in the integer (default 32)
//!   Derived from base class int_s.  
//! \author Tony Kirke
//! \ingroup n_templates base
template <long Bits=32> class sint : public int_s
{
	public:
	  sint<Bits>() { 
		  bits=Bits-1;
		  mask = -1 << bits;
	  }
	  sint<Bits>(long y) { 
		  bits=Bits-1;
		  mask = -1 << bits;
		  q = y;
		  if (((mask&q)==mask) || ((mask&q)==0)) {
		  } else {
			std::cout << "Overflow in sint<> constructor, ";
			std::cout << "in " << __FILE__ << " on line " << __LINE__ << " ";
			std::cout << "Input = " << y << " Max value = " << ~mask << "\n";
			q &= ~mask;
			if (y>0) q = ~q;
		  }
	  }
	  inline sint<Bits> operator =(const int_s& y) {   
		q = y.q;
		xbits = y.bits;
		sign = (y.q & (1 << bits));
		if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
			q &= ~mask;
			if (sign) q |= mask;
		}
       return *this; 
	  } 
      inline sint<Bits> operator =(const long& y) { 
		q = y;	
		sign = (y & (1 << bits));
		if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
		  q &= ~mask;
		  if (sign) q |= mask;
		}
		return *this; 
	  } 
};
// template_instantiations: 5
} // namespace SPUC
#endif

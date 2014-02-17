
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
//! \author Tony Kirke
// from directory: spuc_types
#include <spuc/vfixed.h>
#include <spuc/real_round.h>
#include <spuc/real_saturate.h>
namespace SPUC {
typedef vfixed self;
// IO functions
std::ostream& operator <<(std::ostream& os, self r) {  
  os << (float_type)r;
  return(os);
}
std::istream& operator >>(std::istream& is, self r) {  
  float_type x;
  is >> x;
  r = x;
  return(is);
}
self operator %(const self& r, const self& l) {
  self x;
  x.q = r.q % l.q;
  x.bits = r.bits;
  return(x);
}
self operator +(const self& r, const self& l) {
  self x;
  x.frac_bits = MAX(r.frac_bits,l.frac_bits);
  x.int_bits = MAX(r.int_bits,l.int_bits)+1;
  x.q = (r.q << (x.frac_bits - r.frac_bits)) + (l.q << (x.frac_bits - l.frac_bits));
  return(x);
}
self operator -(const self& r, const self& l) {
  self x;
  x.frac_bits = MAX(r.frac_bits,l.frac_bits);
  x.int_bits = MAX(r.int_bits,l.int_bits)+1;
  x.q = (r.q << (x.frac_bits - r.frac_bits)) - (l.q << (x.frac_bits - l.frac_bits));
  return(x);
}
self operator -(const self& r) {
  self x;
  x.q = -r.q;
  x.int_bits = r.int_bits+1;
  x.frac_bits = r.frac_bits;
  return(x);
}

self operator *(const self& r, const self& l) {
  self x;
  x.q = r.q*l.q;
#ifndef ALLOW_FP_OVERFLOW
  long long c = (long long)r.q * (long long)l.q;
  if ((long long)x.q != c) {
	std::cout << "LHS should be " << c << " actual value = " << x.q << "\n";
	std::cout << "in " << __FILE__ << " on line " << __LINE__ << "\n";
	std::cout << "Fatal integer overflow\n";
	std::cout << "Compile with ALLOW_FP_OVERFLOW to ignore\n";
	std::cout << "or use less bits into multiply\n";
	//	throw "Fatal integer overflow\n";
	//	abort();
  }
#endif
  x.int_bits = r.int_bits + l.int_bits;
  x.frac_bits = r.frac_bits + l.frac_bits;
  return(x);  
};
float_type operator /(const self& r, const self& l) {  return((float_type)r/(float_type)l);};

self operator *(long r, const self& l) {
  self x;
  x.q = r*l.q;
#ifndef ALLOW_FP_OVERFLOW
  long long c = (long long)r * (long long)l.q;
  if ((long long)x.q != c) {
	std::cout << "LHS should be " << c << " actual value = " << x.q << "\n";
	std::cout << "in " << __FILE__ << " on line " << __LINE__ << "\n";
	std::cout << "Fatal integer overflow\n";
	std::cout << "Compile with ALLOW_FP_OVERFLOW to ignore\n";
	std::cout << "or use less bits into multiply\n";
	//	throw "Fatal integer overflow\n";
	//	abort();
  }
#endif
  x.int_bits = 2*l.int_bits;
  x.frac_bits = l.frac_bits;
  return(x);  
};
self operator *(const self& r, long l) {
  self x;
  x.q = r.q*l;
#ifndef ALLOW_FP_OVERFLOW
  long long c = (long long)r.q * (long long)l;
  if ((long long)x.q != c) {
	std::cout << "LHS should be " << c << " actual value = " << x.q << "\n";
	std::cout << "in " << __FILE__ << " on line " << __LINE__ << "\n";
	std::cout << "Fatal integer overflow\n";
	std::cout << "Compile with ALLOW_FP_OVERFLOW to ignore\n";
	std::cout << "or use less bits into multiply\n";
	//	throw "Fatal integer overflow\n";
	//	abort();
  }
#endif
  x.int_bits = 2*r.int_bits;
  x.frac_bits = r.frac_bits;
  return(x);  
};

self operator <<(const self& r, const long shift)  {
  self x;
  x.q = r.q;
  x.mask = r.mask << shift;
  x.int_bits  = r.int_bits + shift; 
  int frac_bits = r.frac_bits - shift;
  if (frac_bits < 0) {
	x.frac_bits = 0;
  } else {
	x.frac_bits = frac_bits;
  }
  return(x);
};

self operator >>(const self& r, const long shift)  {
  self x;
  x.q = r.q;
  x.mask = r.mask >> shift;
  x.frac_bits  = r.frac_bits + shift; 
  int int_bits = r.int_bits - shift;
  if (int_bits < 0) {
	x.int_bits = 0;
  } else {
	x.int_bits = int_bits;
  }
  return(x);
};


//------------------------------------------------
template <>  inline vfixed real_saturate(vfixed in, long rbits) {
  vfixed out;
  long low_mask = MASK_LOW(rbits);
  if (ABS(in.q) > low_mask) out.q = (in.q>0) ? low_mask : ~low_mask;
  else out.q = in.q;
  out.bits = rbits;
  return(out);
}
template <> vfixed real_round(vfixed in, long rbits) {
  vfixed out = in;
  int frac_bits = in.frac_bits - rbits;
  if (frac_bits < 0) {
	out.frac_bits = 0;
	//error!!!!!
  }
  else out.frac_bits = frac_bits;
  
  float_type scale = 1.0/(float_type)MASK_BIT(rbits);
  scale = scale*MASK_BIT(out.frac_bits);
  out.q = SPUC_TOLONG(scale*(float_type)in);
  out.bits = in.bits-rbits;
  return(out);
}
} // namespace SPUC

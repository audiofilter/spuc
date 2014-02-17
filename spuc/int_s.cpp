
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
#include <spuc/int_s.h>
#include <spuc/real_round.h>
#include <spuc/real_saturate.h>
//#define CLIP(A,B,C) (A>B) ? B : ((A<C) ? C : A)
namespace SPUC {

typedef int_s self;

// IO functions
std::ostream& operator <<(std::ostream& os, self r) {  
  os << (long)r;
  return(os);
}
std::istream& operator >>(std::istream& is, self r) {  
  long x;
  is >> x;
  r = x;
  return(is);
}


self clip(self in, self min_clp, self max_clp) {
  self out = (in>max_clp) ? max_clp : ((in<min_clp) ? min_clp : in);
  out.bits = in.bits;
  return out;
}

bool or_bits(const self& r) {
  long x=r.q;
  bool s=0;
  for (int i=0;i<r.bits;i++) { 
	s |= x & 0x1;
	x >>= 1;
  }
  return(s);
}

bool operator >(const int_s& r, const int_s&l) {
  return(r.q > l.q);
}
bool operator <(const int_s& r, const int_s&l) {
  return(r.q < l.q);
}


self operator %(const self& r, const self& l) {
  self x;
  x.q = r.q % l.q;
  x.bits = r.bits;
  return(x);
}
self operator +(const self& r, const self& l) {
  self x;
  x.q = r.q + l.q;
  x.bits = MAX(r.bits,l.bits)+1;
  return(x);
}
self operator -(const self& r, const self& l) {
  self x;
  x.q = r.q - l.q;
  x.bits = MAX(r.bits,l.bits)+1;
  return(x);
}
self operator -(const self& r) {
  self x;
  x.q = -r.q;
  x.bits = r.bits+1;
  return(x);
}
self operator &(const self& r, const self& l) {
  self x;
  x.q = r.q & l.q;
  x.bits = MAX(r.bits,l.bits);
  return(x);
}
self operator ^(const self& r, const self& l) {
  self x;
  x.q = r.q ^ l.q;
  x.bits = MAX(r.bits,l.bits);
  return(x);
}
self operator |(const self& r, const self& l) {
  self x;
  x.q = r.q | l.q;
  x.bits = MAX(r.bits,l.bits);
  return(x);
}
self operator *(const self& r, const self& l) {
  self x;
  x.q = r.q*l.q;
  x.bits = r.bits+l.bits;
  return(x);  
};
self operator /(const self& r, const self& l) {
  self x;
  x.q = r.q/l.q;
  return(x);  
};
self operator <<(const self& r, const long shift)  {
  self x;
  x.q = r.q << shift;
  x.mask = r.mask << shift;
  x.bits = r.bits+shift;
  return(x);
};

self operator >>(const self& r, const long shift)  {
  self x;
  x.q = r.q >> shift;
  x.mask = r.mask >> shift;
  x.bits = r.bits-shift;
  return(x);
};
self operator ,(const self& r, const self& l) {
  self x;
  if (l.q > 0) x.q = (r.q << l.bits) | l.q;
  else x.q = (r.q << l.bits) | (l.q & ~l.mask);
  return(x);
}
////////////////////////////////////////////////////
template <> int_s real_saturate(int_s in, long rbits) {
  int_s out;
  long low_mask = MASK_LOW(rbits);
  if (ABS(in.q) > low_mask) out.q = (in.q>0) ? low_mask : ~low_mask;
  else out.q = in.q;
  out.bits = rbits;
  return(out);
}
//------------------------------------------------
template <> int_s real_round(int_s in, long rbits) {
  int_s out;
  float_type scale = 1.0/(float_type)MASK_BIT(rbits);
  out.q = SPUC_TOLONG(scale*in.q);
  out.bits = in.bits-rbits;
  return(out);
}
} // namespace SPUC

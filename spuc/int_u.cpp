
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
#include <spuc/int_u.h>
#include <spuc/real_round.h>
#include <spuc/real_saturate.h>
namespace SPUC {
//! Round to rbits
int_u magsq(int_u y) { 
  int_u x;
  x.q = y.q*y.q;
  x.mask = -1 << (y.bits * 2);
  return(x); 
};

//! Uses CLIP macro
int_u clip(int_u in, int_u min_clp, int_u max_clp) {
  int_u out = CLIP(in, max_clp, min_clp);
  return out;
}
// OR reduction of number
bool or_bits(int_u r) {
  natural x=r.q;
  bool s=0;
  for (int i=0;i<r.bits;i++) { 
	s |= x & 0x1;
	x >>= 1;
  }
  return(s);
}
int_u operator %(int_u r, int_u l) {
  int_u x;
  x.q = r.q % l.q;
  return(x);
}
int_u operator %(int_u r, natural l) {
  int_u x;
  x.q = r.q % l;
  return(x);
}
int_u operator %(natural r, int_u l) {
  int_u x;
  x.q = r % l.q;
  return(x);
}
int_u operator +(int_u r, int_u l) {
  int_u x;
  x.q = r.q + l.q;
  return(x);
}
int_u operator +(int_u r, natural l) {
  int_u x;
  x.q = r.q + l;
  return(x);
}
int_u operator +(natural r, int_u l) {
  int_u x;
  x.q = r + l.q;
  return(x);
}
int_u operator -(int_u r, int_u l) {
  int_u x;
  x.q = r.q - l.q;
  return(x);
}
int_u operator -(int_u r, natural l) {
  int_u x;
  x.q = r.q - l;
  return(x);
}
int_u operator -(natural r, int_u l) {
  int_u x;
  x.q = r - l.q;
  return(x);
}
int_u operator &(int_u r, int_u l) {
  int_u x;
  x.q = r.q & l.q;
  return(x);
}
int_u operator &(int_u r, natural l) {
  int_u x;
  x.q = r.q & l;
  return(x);
}
int_u operator &(natural r, int_u l) {
  int_u x;
  x.q = r & l.q;
  return(x);
}
int_u operator ^(int_u r, int_u l) {
  int_u x;
  x.q = r.q ^ l.q;
  return(x);
}
int_u operator ^(int_u r, natural l) {
  int_u x;
  x.q = r.q ^ l;
  return(x);
}
int_u operator ^(natural r, int_u l) {
  int_u x;
  x.q = r ^ l.q;
  return(x);
}
int_u operator |(int_u r, int_u l) {
  int_u x;
  x.q = r.q | l.q;
  return(x);
}
int_u operator |(int_u r, natural l) {
  int_u x;
  x.q = r.q | l;
  return(x);
}
int_u operator |(natural r, int_u l) {
  int_u x;
  x.q = r | l.q;
  return(x);
}
int_u operator *(int_u r, int_u l) {
  int_u x;
  x.q = r.q*l.q;
  return(x);  
};
int_u operator *(int_u r, natural l) {
  int_u x;
  x.q = r.q*l;
  return(x);  
};
int_u operator *(natural r, int_u l) {
  int_u x;
  x.q = r*l.q;
  return(x);  
};
int_u operator /(int_u r, int_u l) {
  int_u x;
  x.q = r.q/l.q;
  return(x);  
};
int_u operator /(natural r, int_u l) {
  int_u x;
  x.q = r/l.q;
  return(x);  
};
int_u operator /(int_u r, natural l) {
  int_u x;
  x.q = r.q/l;
  return(x);  
};

int_u operator <<(int_u r, const natural shift)  {
  int_u x;
  x.q = r.q << shift;
  x.mask = r.mask << shift;
  x.bits = r.bits + shift;
  return(x);
};
int_u operator >>(int_u r, const natural shift)  {
  int_u x;
  x.q = r.q >> shift;
  x.mask = r.mask >> shift;
  x.bits = r.bits - shift;
  return(x);
};
int_u operator ,(int_u r, int_u l) {
  int_u x;
  x.q = (r.q << l.bits) | l.q;
  return(x);
}
//------------------------------------------------
template <>  inline int_u real_saturate(int_u in, long rbits) {
  int_u out;
  long low_mask = MASK_LOW(rbits);
  if (in.q > low_mask) out.q = low_mask;
  else out.q = in.q;
  out.mask = ~low_mask;
  out.bits = rbits;
  return(out);
}
template <> int_u real_round(int_u in, long rbits) {
  int_u out;
  float_type scale = 1.0/(float_type)MASK_BIT(rbits);
  out.q = SPUC_TOLONG(scale*in.q);
  out.bits = in.bits-rbits;
  return(out);
}

} // namespace SPUC

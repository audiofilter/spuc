//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014 Tony Kirke. All Rights reserved.

//////////////////////////////////////////////////////////////////////////////

#ifndef SPUC_UINT_20140509_CLASS_FUNCTIONS_H_
#define SPUC_UINT_20140509_CLASS_FUNCTIONS_H_

#include <SPUC/spuc_fixed_common.h>
namespace SPUC {

// IO functions
template <int NINT>
std::ostream &operator<<(std::ostream &os, const spuc_uint<NINT> &r) {
  return os << r.to_int();
};
template <int NINT>
std::istream &operator>>(std::istream &os, const spuc_uint<NINT> &r) {
  return os >> r;
};

// TEMPLATE functions for +,-,*,/ (divide returns double)

// addition
template <int W_, int W_1>
spuc_uint<Template_Max<W_, W_1>::maxval + 1> operator+(
    const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  spuc_uint<Template_Max<W_, W_1>::maxval + 1> tmp(a);
  tmp += b;
  return (tmp);
}

template <int W_, int W_1>
spuc_uint<Template_Max<W_, W_1>::maxval + 1> operator-(
    const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  spuc_uint<Template_Max<W_, W_1>::maxval + 1> tmp(a);
  tmp -= b;
  return (tmp);
}

// multiplication
template <int W_, int W_1>
spuc_uint<W_ + W_1> operator*(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  spuc_uint<W_ + W_1> tmp(a);
  tmp *= b;
  return (tmp);
}
// division
template <int W_, int W_1>
spuc_uint<W_> operator/(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  spuc_uint<W_> tmp(a);
  tmp /= b;
  return (tmp);
}
// <<
template <int W_, int W_1>
spuc_uint<W_ + (1 << W_1) - 1> operator<<(const spuc_uint<W_> &a,
                                          const spuc_uint<W_1> &shift) {
  spuc_uint<W_ + (1 << W_1) - 1> tmp(a);
  tmp <<= shift;
  return (tmp);
}
// >>
template <int W_, int W_1>
spuc_uint<W_> operator>>(const spuc_uint<W_> &a, const spuc_uint<W_1> &shift) {
  spuc_uint<W_> tmp(a);
  tmp >>= shift;
  return (tmp);
}

// Operations to support mixing with ints & doubles, etc

// Comparison operators "==,!=,<<=,>,>=" between this type and 'double'

// or
template <int W_, int W_1>
spuc_uint<Template_Max<W_, W_1>::maxval> operator|(const spuc_uint<W_> &a,
                                                   const spuc_uint<W_1> &b) {
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpa(a);
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpb(b);
  tmpa.val |= tmpb.val;
  return (tmpa);
}
template <int W_, int W_1>
spuc_uint<Template_Max<W_, W_1>::maxval> operator&(const spuc_uint<W_> &a,
                                                   const spuc_uint<W_1> &b) {
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpa(a);
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpb(b);
  tmpa.val &= tmpb.val;
  return (tmpa);
}
template <int W_, int W_1>
spuc_uint<Template_Max<W_, W_1>::maxval> operator^(const spuc_uint<W_> &a,
                                                   const spuc_uint<W_1> &b) {
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpa(a);
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpb(b);
  tmpa.val ^= tmpb.val;
  return (tmpa);
}

template <int W_, int W_1>
bool operator==(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpa(a);
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpb(b);
  return (tmpa.val == tmpb.val);
}

template <int W_, int W_1>
bool operator<(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpa(a);
  spuc_uint<Template_Max<W_, W_1>::maxval> tmpb(b);
  return (tmpa.val < tmpb.val);
}
template <int W_, int W_1>
bool operator!=(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  return !(a == b);
}

template <int W_, int W_1>
bool operator>(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  return (b < a);
}
template <int W_, int W_1>
bool operator<=(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  return !(b < a);
}
template <int W_, int W_1>
bool operator>=(const spuc_uint<W_> &a, const spuc_uint<W_1> &b) {
  return !(a < b);
}

}  // end of namespace SPUC

#endif

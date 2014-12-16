//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014 Tony Kirke. All Rights reserved.

//////////////////////////////////////////////////////////////////////////////

#ifndef SPUC_INT_20140509_MIXED_FUNCTIONS_H_
#define SPUC_INT_20140509_MIXED_FUNCTIONS_H_

namespace SPUC {

// TEMPLATE functions for +,-,*,/ (divide returns double)
template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1 + 1>::maxval + 1> operator+(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<Template_Max<W_, W_1 + 1>::maxval + 1> tmp(a);
  tmp += b;
  return (tmp);
}
template <int W_, int W_1>
spuc_int<Template_Max<W_ + 1, W_1>::maxval + 1> operator+(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<Template_Max<W_ + 1, W_1>::maxval + 1> tmp(a);
  tmp += b;
  return (tmp);
}

template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1 + 1>::maxval + 1> operator-(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<Template_Max<W_, W_1 + 1>::maxval + 1> tmp(a);
  tmp -= b;
  return (tmp);
}
template <int W_, int W_1>
spuc_int<Template_Max<W_ + 1, W_1>::maxval + 1> operator-(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<Template_Max<W_ + 1, W_1>::maxval + 1> tmp(a);
  tmp -= b;
  return (tmp);
}

// multiplication
template <int W_, int W_1> spuc_int<W_ + W_1> operator*(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<W_ + W_1> tmp;
  typedef typename spuc_int<W_ + W_1>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)(b.getVal());
  return tmp;
}
template <int W_, int W_1> spuc_int<W_ + W_1> operator*(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<W_ + W_1> tmp;
  typedef typename spuc_int<W_ + W_1>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)(b.getVal());
  return tmp;
}
template <int W_, int W_1> spuc_int<W_ + W_1> operator/(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<W_ + W_1> tmp;
  typedef typename spuc_int<W_ + W_1>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) / (mult_val_type)(b.getVal());
  return tmp;
}
template <int W_, int W_1> spuc_int<W_ + W_1> operator/(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<W_ + W_1> tmp;
  typedef typename spuc_int<W_ + W_1>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) / (mult_val_type)(b.getVal());
  return tmp;
}

// <<
template <int W_, int W_1>
spuc_int<W_ + (1 << W_1) - 1> operator<<(const spuc_int<W_> &a, const spuc_uint<W_1> &shift) {
  spuc_int<W_ + (1 << W_1) - 1> tmp(a);
  tmp <<= shift;
  return (tmp);
}
// Non-fixed bit-width type shifts
template <int W_, typename T_> spuc_int<W_> operator<<(const spuc_int<W_> &a, const T_ &shift) {
  spuc_int<W_> tmp(a);
  tmp <<= shift;
  return (tmp);
}
template <int W_, typename T_> spuc_uint<W_> operator<<(const spuc_uint<W_> &a, const T_ &shift) {
  spuc_uint<W_> tmp(a);
  tmp <<= shift;
  return (tmp);
}
// >>
template <int W_, int W_1> spuc_int<W_> operator>>(const spuc_int<W_> &a, const spuc_uint<W_1> &shift) {
  spuc_int<W_> tmp(a);
  tmp >>= shift;
  return (tmp);
}

template <int W_, typename T_> spuc_int<W_> operator>>(const spuc_int<W_> &a, const T_ &shift) {
  spuc_int<W_> tmp(a);
  tmp >>= shift;
  return (tmp);
}
template <int W_, typename T_> spuc_uint<W_> operator>>(const spuc_uint<W_> &a, const T_ &shift) {
  spuc_uint<W_> tmp(a);
  tmp >>= shift;
  return (tmp);
}

template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1>::maxval> operator|(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval> tmp(a);
  tmp |= b;
  return (tmp);
}
template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1>::maxval> operator|(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval> tmp(a);
  tmp |= b;
  return (tmp);
}

template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1>::maxval> operator&(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval> tmp(a);
  tmp &= b;
  return (tmp);
}
template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1>::maxval> operator&(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval> tmp(a);
  tmp &= b;
  return (tmp);
}

template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1>::maxval> operator^(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval> tmp(a);
  tmp |= b;
  return (tmp);
} template <int W_, int W_1>
spuc_int<Template_Max<W_, W_1>::maxval> operator^(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval> tmp(a);
  tmp |= b;
  return (tmp);
}

// Operations to support mixing with ints & doubles, etc

// Comparison operators "==,!=,<<=,>,>=" between this type and 'double'

// int with uint
template <int W_, int W_1>
bool operator==(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpa(a);
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpb(b);
  return (tmpa.val == tmpb.val);
}

template <int W_, int W_1> bool operator<(const spuc_int<W_> &a, const spuc_uint<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpa(a);
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpb(b);
  return (tmpa.val < tmpb.val);
}

template <int W_, int W_1> bool operator!=(const spuc_int<W_> &a, const spuc_uint<W_1> &b) { return !(a == b); }
template <int W_, int W_1> bool operator>(const spuc_int<W_> &a, const spuc_uint<W_1> &b) { return (b < a); }
template <int W_, int W_1> bool operator<=(const spuc_int<W_> &a, const spuc_uint<W_1> &b) { return !(b < a); }
template <int W_, int W_1> bool operator>=(const spuc_int<W_> &a, const spuc_uint<W_1> &b) { return !(a < b); }
// uint with int
template <int W_, int W_1> bool operator==(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpa(a);
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpb(b);
  return (tmpa.val == tmpb.val);
}

template <int W_, int W_1> bool operator<(const spuc_uint<W_> &a, const spuc_int<W_1> &b) {
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpa(a);
  spuc_int<Template_Max<W_, W_1>::maxval + 1> tmpb(b);
  return (tmpa.val < tmpb.val);
}
template <int W_, int W_1> bool operator!=(const spuc_uint<W_> &a, const spuc_int<W_1> &b) { return !(a == b); }
template <int W_, int W_1> bool operator>(const spuc_uint<W_> &a, const spuc_int<W_1> &b) { return (b < a); }
template <int W_, int W_1> bool operator<=(const spuc_uint<W_> &a, const spuc_int<W_1> &b) { return !(b < a); }
template <int W_, int W_1> bool operator>=(const spuc_uint<W_> &a, const spuc_int<W_1> &b) { return !(a < b); }

// --------------------- BOOLEAN Comparisions "==,<=, <. >=, > , !="
// -------------------------------------------
// Compare with doubles
template <int W_> bool operator==(const double &a, const spuc_int<W_> &b) { return (b.to_double() == a); }
template <int W_> bool operator!=(const double &a, const spuc_int<W_> &b) { return (b.to_double() != a); }
template <int W_> bool operator<(const double &a, const spuc_int<W_> &b) { return (b.to_double() > a); }
template <int W_> bool operator<=(const double &a, const spuc_int<W_> &b) { return (b.to_double() >= a); }
template <int W_> bool operator>(const double &a, const spuc_int<W_> &b) { return (b.to_double() < a); }
template <int W_> bool operator>=(const double &a, const spuc_int<W_> &b) { return (b.to_double() <= a); }

template <int W_> bool operator==(const spuc_int<W_> &b, const double &a) { return (b.to_double() == a); }
template <int W_> bool operator!=(const spuc_int<W_> &b, const double &a) { return (b.to_double() != a); }
template <int W_> bool operator<(const spuc_int<W_> &b, const double &a) { return (b.to_double() < a); }
template <int W_> bool operator<=(const spuc_int<W_> &b, const double &a) { return (b.to_double() <= a); }
template <int W_> bool operator>(const spuc_int<W_> &b, const double &a) { return (b.to_double() > a); }
template <int W_> bool operator>=(const spuc_int<W_> &b, const double &a) { return (b.to_double() >= a); }

// compare with uint64
template <int W_> bool operator==(const uint64_t &a, const spuc_int<W_> &b) { return (b.to_int() == a); }
template <int W_> bool operator!=(const uint64_t &a, const spuc_int<W_> &b) { return (b.to_int() != a); }
template <int W_> bool operator<(const uint64_t &a, const spuc_int<W_> &b) { return (b.to_int() > a); }
template <int W_> bool operator<=(const uint64_t &a, const spuc_int<W_> &b) { return (b.to_int() >= a); }
template <int W_> bool operator>(const uint64_t &a, const spuc_int<W_> &b) { return (b.to_int() < a); }
template <int W_> bool operator>=(const uint64_t &a, const spuc_int<W_> &b) { return (b.to_int() <= a); }
template <int W_> bool operator==(const spuc_int<W_> &b, const uint64_t &a) { return (b.to_int() == a); }
template <int W_> bool operator!=(const spuc_int<W_> &b, const uint64_t &a) { return (b.to_int() != a); }
template <int W_> bool operator<(const spuc_int<W_> &b, const uint64_t &a) { return (b.to_int() < a); }
template <int W_> bool operator<=(const spuc_int<W_> &b, const uint64_t &a) { return (b.to_int() <= a); }
template <int W_> bool operator>(const spuc_int<W_> &b, const uint64_t &a) { return (b.to_int() > a); }
template <int W_> bool operator>=(const spuc_int<W_> &b, const uint64_t &a) { return (b.to_int() >= a); }

// compare with int64
template <int W_> bool operator==(const int &a, const spuc_int<W_> &b) { return (b.to_int() == a); }
template <int W_> bool operator!=(const int &a, const spuc_int<W_> &b) { return (b.to_int() != a); }
template <int W_> bool operator<(const int &a, const spuc_int<W_> &b) { return (b.to_int() > a); }
template <int W_> bool operator<=(const int &a, const spuc_int<W_> &b) { return (b.to_int() >= a); }
template <int W_> bool operator>(const int &a, const spuc_int<W_> &b) { return (b.to_int() < a); }
template <int W_> bool operator>=(const int &a, const spuc_int<W_> &b) { return (b.to_int() <= a); }

template <int W_> bool operator==(const spuc_int<W_> &b, const int &a) { return (b.to_int() == a); }
template <int W_> bool operator!=(const spuc_int<W_> &b, const int &a) { return (b.to_int() != a); }
template <int W_> bool operator<(const spuc_int<W_> &b, const int &a) { return (b.to_int() < a); }
template <int W_> bool operator<=(const spuc_int<W_> &b, const int &a) { return (b.to_int() <= a); }
template <int W_> bool operator>(const spuc_int<W_> &b, const int &a) { return (b.to_int() > a); }
template <int W_> bool operator>=(const spuc_int<W_> &b, const int &a) { return (b.to_int() >= a); }

// Math Ops
template <int W_> double operator+(const double &a, const spuc_int<W_> &b) { return (((double)a + (double)b)); }
template <int W_> double operator+(const spuc_int<W_> &b, const double &a) { return (((double)a + (double)b)); }
template <int W_> double operator-(const double &a, const spuc_int<W_> &b) { return (((double)a - (double)b)); }
template <int W_> double operator-(const spuc_int<W_> &a, const double &b) { return (((double)a - (double)b)); }
template <int W_> double operator*(const double &a, const spuc_int<W_> &b) { return (((double)a * (double)b)); }
template <int W_> double operator*(const spuc_int<W_> &a, const double &b) { return (((double)a * (double)b)); }
template <int W_> double operator/(const double &a, const spuc_int<W_> &b) { return (((double)a / (double)b)); }
template <int W_> double operator/(const spuc_int<W_> &a, const double &b) { return (((double)a / (double)b)); }
template <int W_> double operator+(const int &a, const spuc_int<W_> &b) { return (((double)a + (double)b)); }
template <int W_> double operator+(const spuc_int<W_> &b, const int &a) { return (((double)a + (double)b)); }
template <int W_> double operator-(const int &a, const spuc_int<W_> &b) { return (((double)a - (double)b)); }
template <int W_> double operator-(const spuc_int<W_> &a, const int &b) { return (((double)a - (double)b)); }
template <int W_> double operator*(const int &a, const spuc_int<W_> &b) { return (((double)a * (double)b)); }
template <int W_> double operator*(const spuc_int<W_> &a, const int &b) { return (((double)a * (double)b)); }
template <int W_> double operator/(const int &a, const spuc_int<W_> &b) { return (((double)a / (double)b)); }
template <int W_> double operator/(const spuc_int<W_> &a, const int &b) { return (((double)a / (double)b)); }
template <int W_> double operator+(const uint64_t &a, const spuc_int<W_> &b) { return (((double)a + (double)b)); }
template <int W_> double operator+(const spuc_int<W_> &b, const uint64_t &a) { return (((double)a + (double)b)); }
template <int W_> double operator-(const uint64_t &a, const spuc_int<W_> &b) { return (((double)a - (double)b)); }
template <int W_> double operator-(const spuc_int<W_> &a, const uint64_t &b) { return (((double)a - (double)b)); }
template <int W_> double operator*(const uint64_t &a, const spuc_int<W_> &b) { return (((double)a * (double)b)); }
template <int W_> double operator*(const spuc_int<W_> &a, const uint64_t &b) { return (((double)a * (double)b)); }
template <int W_> double operator/(const uint64_t &a, const spuc_int<W_> &b) { return (((double)a / (double)b)); }
template <int W_> double operator/(const spuc_int<W_> &a, const uint64_t &b) { return (((double)a / (double)b)); }

// Bool Ops
template <int W_> spuc_int<W_ + 1> operator+(const bool &a, const spuc_int<W_> &b) { return (spuc_int<1>(a) + b); }
template <int W_> spuc_int<W_ + 1> operator+(const spuc_int<W_> &a, const bool &b) { return (a + spuc_int<1>(b)); }
template <int W_> spuc_int<W_ + 1> operator-(const bool &a, const spuc_int<W_> &b) { return (spuc_int<1>(a) - b); }
template <int W_> spuc_int<W_ + 1> operator-(const spuc_int<W_> &a, const bool &b) { return (a - spuc_int<1>(b)); }

}  // end of namespace SPUC

#endif

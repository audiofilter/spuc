//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014 Tony Kirke. All Rights reserved.

//////////////////////////////////////////////////////////////////////////////

#ifndef SPUC_UINT_20140509_CLASS_H_
#define SPUC_UINT_20140509_CLASS_H_
#include <iostream>
#include <sstream>
#include <cmath>  // for floor in spuc_fixed
#include <SPUC/spuc_fixed_common.h>

namespace SPUC {

/// A faster version of the older systemc spuc_uint
template <int I_>
class spuc_uint {
 public:
  typedef typename int_type_size<NEXT_INT_SIZE<I_>::val>::uint_type val_type;
  typedef uint64_t max_val_type;
  val_type val;
  static const int INTEGER_BITS = I_;

 public:
  /// constructors
  spuc_uint() : val(0) {}

  /// From exact same type - just copy val
  spuc_uint(const spuc_uint &a) : val(a.getVal()) {}
  spuc_uint(const double &a) : val((int64_t)a) {}
  // Constructors (generated)
  spuc_uint(const int8_t &a) { val = a & UMask<I_>::val; }
  spuc_uint(const int16_t &a) { val = a & UMask<I_>::val; }
  spuc_uint(const int32_t &a) { val = a & UMask<I_>::val; }
  spuc_uint(const int64_t &a) { val = a & UMask<I_>::val; }
  spuc_uint(const uint8_t &a) { val = a & UMask<I_>::val; }
  spuc_uint(const uint16_t &a) { val = a & UMask<I_>::val; }
  spuc_uint(const uint32_t &a) { val = a & UMask<I_>::val; }
  spuc_uint(const uint64_t &a) { val = a & UMask<I_>::val; }

  /// from another spuc_uint<>
  template <int I_1>
  spuc_uint(const spuc_uint<I_1> &a) {
    val = a.val;
  }

  // for now
  val_type getVal() const { return (val); }

  /// Conversions
  void from_int(int64_t x) { val = (max_val_type)x; }
  double to_double(void) const { return ((double)val); }
  int64_t to_int(void) const { return ((int64_t)val); }

  // conversion to bool
  bool operator!() const { return (val == 0); }

  operator int64_t() const { return ((int64_t)val); }

  spuc_uint &operator++() {
    val++;
    return *this;
  }
  spuc_uint operator++(int) {
    spuc_uint tmp(*this);
    ++*this;
    return (tmp);
  }
  spuc_uint &operator--() {
    val--;
    return *this;
  }
  spuc_uint operator--(int) {
    spuc_uint tmp(*this);
    --*this;
    return (tmp);
  }

  // assignment operator, just copy the only member variable - no checks!
  // could use copy constructor + swap?
  spuc_uint &operator=(const spuc_uint &a) {
    val = a.getVal();
    return *this;
  }

  /// assignment operator from another size, use copy constructor, then copy
  /// val;
  template <int I_1>
  spuc_uint<I_> &operator=(const spuc_uint<I_1> &a) {
    spuc_uint<I_> temp(a);
    val = temp.getVal();
    return *this;
  }

  /// sign operator
  spuc_uint<I_ + 1> operator-() const {
    spuc_uint<I_ + 1> tmp(*this);
    tmp.val = -tmp.val;
    return tmp;
  }
  spuc_uint<I_> operator+() const {
    spuc_uint<I_> tmp(*this);
    return tmp;
  }

  /// bit flip
  spuc_uint operator~() const {
    spuc_uint tmp(*this);
    tmp.val = ~tmp.val;
    return (tmp);
  }

  // Assign from different built-in types
  spuc_uint &operator=(const int8_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const int16_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const int32_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const int64_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const uint8_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const uint16_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const uint32_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const uint64_t &a) {
    *this = spuc_uint(a);
    return *this;
  }
  spuc_uint &operator=(const double &a) {
    *this = spuc_uint(a);
    return *this;
  }

  template <int I_1>
  spuc_uint &operator+=(const spuc_uint<I_1> &a) {
    val += a.val;
    return *this;
  }

  template <int I_1>
  spuc_uint &operator-=(const spuc_uint<I_1> &a) {
    *this += (-a);  // re-use +=
    return *this;
  }

  template <int I_1>
  spuc_uint &operator*=(const spuc_uint<I_1> &b) {
    val *= b.val;
    return *this;
  }
  spuc_uint &operator+=(const int8_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const int8_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const int8_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const int8_t &b) {
    val /= b;
    return *this;
  }
  spuc_uint &operator+=(const int16_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const int16_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const int16_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const int16_t &b) {
    val /= b;
    return *this;
  }
  spuc_uint &operator+=(const int32_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const int32_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const int32_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const int32_t &b) {
    val /= b;
    return *this;
  }
  spuc_uint &operator+=(const int64_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const int64_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const int64_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const int64_t &b) {
    val /= b;
    return *this;
  }
  spuc_uint &operator+=(const uint8_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const uint8_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const uint8_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const uint8_t &b) {
    val /= b;
    return *this;
  }
  spuc_uint &operator+=(const uint16_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const uint16_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const uint16_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const uint16_t &b) {
    val /= b;
    return *this;
  }
  spuc_uint &operator+=(const uint32_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const uint32_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const uint32_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const uint32_t &b) {
    val /= b;
    return *this;
  }
  spuc_uint &operator+=(const uint64_t &b) {
    val += b;
    return *this;
  }
  spuc_uint &operator-=(const uint64_t &b) {
    val -= b;
    return *this;
  }
  spuc_uint &operator*=(const uint64_t &b) {
    val *= b;
    return *this;
  }
  spuc_uint &operator/=(const uint64_t &b) {
    val /= b;
    return *this;
  }
  // "+= and -=" from different built-in types

  spuc_uint &operator*=(const double &a) {
    spuc_uint tmp(a);
    val *= tmp.getVal();
    return *this;
  }
  spuc_uint &operator/=(const double &a) {
    spuc_uint tmp(a);
    val /= tmp.getVal();
    return *this;
  }
  spuc_uint &operator+=(const double &a) {
    spuc_uint tmp(a);
    val += tmp.getVal();
    return *this;
  }
  spuc_uint &operator-=(const double &a) {
    spuc_uint tmp(a);
    val -= tmp.getVal();
    return *this;
  }
  spuc_uint &operator>>=(const int &a) {
    val >>= a;
    return *this;
  }
  spuc_uint &operator<<=(const int &a) {
    val <<= a;
    return *this;
  }

  template <typename T>
  spuc_uint &operator&=(const T &l) {
    val &= l;
    return *this;
  }
  template <typename T>
  spuc_uint &operator|=(const T &l) {
    val |= l;
    return *this;
  }
  template <typename T>
  spuc_uint &operator^=(const T &l) {
    val ^= l;
    return *this;
  }

  void print(std::ostream &os = ::std::cout) const { os << to_int(); }

};  // end of class

}  // end of namespace SPUC

#endif

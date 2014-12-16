//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014 Tony Kirke. All Rights reserved.

//////////////////////////////////////////////////////////////////////////////

#ifndef SPUC_INT_20140509_CLASS_H_
#define SPUC_INT_20140509_CLASS_H_
#include <iostream>
#include <sstream>
#include <cmath>  // for floor in spuc_fixed
#include <SPUC/spuc_fixed_common.h>

namespace SPUC {

/// A faster version of the older systemc spuc_int
template <int I_> class spuc_int {
 public:
  typedef typename int_type_size<NEXT_INT_SIZE<I_>::val>::int_type val_type;
  typedef int64_t max_val_type;
  val_type val;
  static const int INTEGER_BITS = I_;

 public:
  /// constructors
  spuc_int() : val(0) {}

  /// From exact same type - just copy val
  spuc_int(const spuc_int &a) : val(a.getVal()) {}
  spuc_int(const double &a) : val((int64_t)a) {}
  // Constructors (generated)
  spuc_int(const int8_t &a) : val((int64_t)a) {}
  spuc_int(const int16_t &a) : val((int64_t)a) {}
  spuc_int(const int32_t &a) : val((int64_t)a) {}
  spuc_int(const int64_t &a) : val((int64_t)a) {}
  spuc_int(const uint8_t &a) : val((int64_t)a) {}
  spuc_int(const uint16_t &a) : val((int64_t)a) {}
  spuc_int(const uint32_t &a) : val((int64_t)a) {}
  spuc_int(const uint64_t &a) : val((int64_t)a) {}

  /// from another spuc_int<>
  template <int I_1> spuc_int(const spuc_int<I_1> &a) { val = a.val; }

  // for now
  val_type getVal() const { return (val); }

  /// Conversions
  void from_int(int64_t x) { val = (max_val_type)x; }
  double to_double(void) const { return ((double)val); }
  int64_t to_int(void) const { return ((int64_t)val); }

  // conversion to bool
  bool operator!() const { return (val == 0); }

  operator int64_t() const { return ((int64_t)val); }

  spuc_int &operator++() {
    val++;
    return *this;
  }
  spuc_int operator++(int) {
    spuc_int tmp(*this);
    ++*this;
    return (tmp);
  }
  spuc_int &operator--() {
    val--;
    return *this;
  }
  spuc_int operator--(int) {
    spuc_int tmp(*this);
    --*this;
    return (tmp);
  }

  // assignment operator, just copy the only member variable - no checks!
  // could use copy constructor + swap?
  spuc_int &operator=(const spuc_int &a) {
    val = a.getVal();
    return *this;
  }

  /// assignment operator from another size, use copy constructor, then copy
  /// val;
  template <int I_1> spuc_int<I_> &operator=(const spuc_int<I_1> &a) {
    spuc_int<I_> temp(a);
    val = temp.getVal();
    return *this;
  }

  /// sign operator
  spuc_int<I_ + 1> operator-() const {
    spuc_int<I_ + 1> tmp(*this);
    tmp.val = -tmp.val;
    return tmp;
  }
  spuc_int<I_> operator+() const {
    spuc_int<I_> tmp(*this);
    return tmp;
  }

  /// bit flip
  spuc_int operator~() const {
    spuc_int tmp(*this);
    tmp.val = ~tmp.val;
    return (tmp);
  }

  // Assign from different built-in types
  spuc_int &operator=(const int8_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const int16_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const int32_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const int64_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const uint8_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const uint16_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const uint32_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const uint64_t &a) {
    *this = spuc_int(a);
    return *this;
  }
  spuc_int &operator=(const double &a) {
    *this = spuc_int(a);
    return *this;
  }

  template <int I_1> spuc_int &operator+=(const spuc_int<I_1> &a) {
    val += a.val;
    return *this;
  }

  template <int I_1> spuc_int &operator-=(const spuc_int<I_1> &a) {
    *this += (-a);  // re-use +=
    return *this;
  }

  template <int I_1> spuc_int &operator*=(const spuc_int<I_1> &b) {
    val *= b.val;
    return *this;
  }
  spuc_int &operator+=(const int8_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const int8_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const int8_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const int8_t &b) {
    val /= b;
    return *this;
  }
  spuc_int &operator+=(const int16_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const int16_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const int16_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const int16_t &b) {
    val /= b;
    return *this;
  }
  spuc_int &operator+=(const int32_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const int32_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const int32_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const int32_t &b) {
    val /= b;
    return *this;
  }
  spuc_int &operator+=(const int64_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const int64_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const int64_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const int64_t &b) {
    val /= b;
    return *this;
  }
  spuc_int &operator+=(const uint8_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const uint8_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const uint8_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const uint8_t &b) {
    val /= b;
    return *this;
  }
  spuc_int &operator+=(const uint16_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const uint16_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const uint16_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const uint16_t &b) {
    val /= b;
    return *this;
  }
  spuc_int &operator+=(const uint32_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const uint32_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const uint32_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const uint32_t &b) {
    val /= b;
    return *this;
  }
  spuc_int &operator+=(const uint64_t &b) {
    val += b;
    return *this;
  }
  spuc_int &operator-=(const uint64_t &b) {
    val -= b;
    return *this;
  }
  spuc_int &operator*=(const uint64_t &b) {
    val *= b;
    return *this;
  }
  spuc_int &operator/=(const uint64_t &b) {
    val /= b;
    return *this;
  }
  // "+= and -=" from different built-in types

  spuc_int &operator*=(const double &a) {
    spuc_int tmp(a);
    val *= tmp.getVal();
    return *this;
  }
  spuc_int &operator/=(const double &a) {
    spuc_int tmp(a);
    val /= tmp.getVal();
    return *this;
  }
  spuc_int &operator+=(const double &a) {
    spuc_int tmp(a);
    val += tmp.getVal();
    return *this;
  }
  spuc_int &operator-=(const double &a) {
    spuc_int tmp(a);
    val -= tmp.getVal();
    return *this;
  }
  spuc_int &operator>>=(const int &a) {
    val >>= a;
    return *this;
  }
  spuc_int &operator<<=(const int &a) {
    val <<= a;
    return *this;
  }

  template <typename T> spuc_int &operator&=(const T &l) {
    val &= l;
    return *this;
  }
  template <typename T> spuc_int &operator|=(const T &l) {
    val |= l;
    return *this;
  }
  template <typename T> spuc_int &operator^=(const T &l) {
    val ^= l;
    return *this;
  }

  void print(std::ostream &os = ::std::cout) const { os << to_int(); }

};  // end of class

}  // end of namespace SPUC

#endif

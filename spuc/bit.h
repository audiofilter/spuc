#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <iostream>
namespace SPUC {
class bit {
 public:
  bit() { b = 0; }
  bit(int value) { b = (char)value; }

  inline bit &operator=(const short &value) {
    b = (char)value;
    return *this;
  }
  inline bit &operator=(const bit &x) {
    b = x.b;
    return *this;
  }
  inline bit &operator/=(const bit &x) {
    b = b | x.b;
    return *this;
  }
  inline bit &operator|=(const bit &x) {
    b = b | x.b;
    return *this;
  }
  inline bit &operator+=(const bit &x) {
    b = b ^ x.b;
    return *this;
  }
  inline bit &operator^=(const bit &x) {
    b = b ^ x.b;
    return *this;
  }
  inline bit &operator-=(const bit &x) {
    b = b ^ x.b;
    return *this;
  }
  inline bit &operator*=(const bit &x) {
    b = b & x.b;
    return *this;
  }
  inline bit &operator&=(const bit &x) {
    b = b & x.b;
    return *this;
  }

  bit operator+(const bit &x) const { return bit(b ^ x.b); }
  bit operator^(const bit &x) const { return bit(b ^ x.b); }
  bit operator-(const bit &x) const { return bit(b ^ x.b); }
  bit operator-() const { return bit(b ^ 1); }
  //  bit operator*(const bit &x) const { return bit(b&x.b); }
  bit operator&(const bit &x) const { return bit(b & x.b); }
  bit operator!(void)const { return bit(b ^ 1); }
  bit operator~(void) const { return bit(b ^ 1); }
  //  bit operator/(const bit &x) const { return bit(b|x.b); }
  bit operator|(const bit &x) const { return bit(b | x.b); }

  bool operator==(const bit &x) const { return b == x.b; }
  bool operator==(const int &x) const { return b == x; }
  bool operator!=(const bit &x) const { return b != x.b; }
  bool operator!=(const int &x) const { return b != x; }

  operator short() const { return short(b); }
  operator int() const { return int(b); }
  operator bool() const { return b != 0; }
  operator float() const { return float(b); }
  operator double() const { return double(b); }

  char value() const { return b; }

 protected:
 private:
  char b;
};
#ifndef PYSTE
std::ostream &operator<<(std::ostream &output, const bit &x);
std::istream &operator>>(std::istream &input, bit &outbin);
#endif
}  // namespace SPUC

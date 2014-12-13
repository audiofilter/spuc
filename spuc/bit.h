#ifndef SPUC_BIT
#define SPUC_BIT

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
#endif

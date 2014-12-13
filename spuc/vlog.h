#ifndef SPUC_VLOG
#define SPUC_VLOG

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
// from directory: spuc_types
#include <iostream>
#include <spuc/spuc_defines.h>
#include <cmath>
#ifndef NO_INT_S
#include <spuc/int_s.h>
#endif
#define FLP_FRAC_BITS 9
namespace SPUC {
//! \file
//! \brief Logarithmic number system class
//
//! \brief Logarithmic number system class
//
//! \author Tony Kirke
//! \ingroup types base
class vlog {
 public:
  typedef vlog self;
  long sign;
  long frac;
  long intlog;
  long frac_bits;

  void reset() {
    frac = 0;
    frac_bits = FLP_FRAC_BITS;
    intlog = 0;
  }
  vlog() { reset(); }
#ifndef NO_INT_S
  vlog(const int_s& y) {
    reset();
    frac = (long)y;
  }
#endif
  vlog(const int& y) {
    reset();
    frac = y;
  }
  vlog(const long& y) {
    reset();
    frac = y;
  }
  void from_double(double y) {
    double x = log2(ABS(y));
    sign = (y < 0) ? -1 : 1;
    intlog = (int)floor(x);
    double z = x - intlog;
    frac = SPUC_TOLONG(z * (1 << frac_bits));
  }
  double to_double(self y) {
    double z = (double)y.frac / (1 << frac_bits) + y.intlog;
    return (y.sign * pow(2.0, z));
  }
  double to_double() {
    double z = (double)frac / (1 << frac_bits) + intlog;
    return (sign * pow(2.0, z));
  }
  vlog(const double& y) {
    reset();
    from_double(y);
  }

 public:
  inline self operator=(const self& y) {
    frac = y.frac;
    intlog = y.intlog;
    sign = y.sign;
    return *this;
  }
  inline self operator=(const long& y) {
    frac = (y << intlog);
    return *this;
  }
  inline self operator=(const int& y) {
    frac = (y << intlog);
    return *this;
  }
  inline self operator=(const double& y) {
    from_double(y);
    return *this;
  }
  inline self operator+=(self r) {
    self z;
    *this = to_double(*this) + to_double(r);
    return *this;
  }

  inline self operator-=(self r) {
    self z;
    *this = to_double(*this) - to_double(r);
    return *this;
  }
  inline self operator*=(self r) {
    self z;
    *this = to_double(*this) * to_double(r);
    return *this;
  }
  inline self operator/=(self r) {
    self z;
    *this = to_double(*this) / to_double(r);
    return *this;
  }

  inline long operator~() { return (~frac); }
  inline bool operator==(self r) {
    return ((frac == r.frac) && (intlog = r.intlog) && (sign == r.sign) &&
            (frac_bits = r.frac_bits));
  }
  inline bool operator!=(long r) { return ((frac != (r << intlog))); }

  inline bool operator<(self r) { return ((double)*this < (double)r); }
  inline bool operator<=(self r) { return ((double)*this <= (double)r); }
  inline bool operator>(self r) { return ((double)*this > (double)r); }
  inline bool operator>=(self r) { return ((double)*this >= (double)r); }

  inline bool operator<(double r) { return (((double)*this < r)); }
  inline bool operator<(float r) { return (((float)*this < r)); }
  inline bool operator<(int r) { return (((double)*this < (double)r)); }
  inline bool operator<(long r) { return ((double)*this < (double)r); }
  inline bool operator>(double r) { return (((double)*this > r)); }
  inline bool operator>(float r) { return (((float)*this > r)); }
  inline bool operator>(int r) { return (((double)*this > (double)r)); }
  inline bool operator>(long r) { return ((double)*this > (double)r); }

  inline bool operator<=(double r) { return (((double)*this <= r)); }
  inline bool operator<=(float r) { return (((float)*this <= r)); }
  inline bool operator<=(int r) { return (((double)*this <= (double)r)); }
  inline bool operator<=(long r) { return ((double)*this <= (double)r); }
  inline bool operator>=(double r) { return (((double)*this >= r)); }
  inline bool operator>=(float r) { return (((float)*this >= r)); }
  inline bool operator>=(int r) { return (((double)*this >= (double)r)); }
  inline bool operator>=(long r) { return ((double)*this >= (double)r); }

  operator double() const {
    double z = (double)frac / (1 << frac_bits) + intlog;
    return (sign * pow((double)2.0, z));
  }
  operator float() const {
    float z = (float)frac / (1 << frac_bits) + intlog;
    return (sign * pow((float)2.0, z));
  }
  operator long() const {
    double z = (double)frac / (1 << frac_bits) + intlog;
    double t = sign * pow((double)2.0, z);
    return ((long)floor(t + 0.5));
  }
  operator int() const {
    double z = (double)frac / (1 << frac_bits) + intlog;
    double t = sign * pow((double)2.0, z);
    return ((int)floor(t + 0.5));
  }
};
// IO functions
#ifndef PYSTE
std::ostream& operator<<(std::ostream& os, vlog r);
std::istream& operator>>(std::istream& is, vlog r);

inline vlog operator-(const vlog& r) {
  vlog x;
  x = r;
  x.frac = -x.frac;
  return (x);
}

inline vlog operator+(const vlog& r, const vlog& l) {
  vlog z;
  double x, y;
  x = (double)r;
  y = (double)l;
  z = (x + y);
  return (z);
}

inline vlog operator-(const vlog& r, const vlog& l) {
  vlog z;
  double x, y;
  x = (double)r;
  y = (double)l;
  z = (x - y);
  return (z);
}

inline vlog operator*(const vlog& r, const vlog& l) {
  vlog z;
  z.intlog = r.intlog + l.intlog;
  long f = r.frac + l.frac;
  // TBD>>>>>>>>>>>>
  if (ABS(f) >= 1) {
    if (f < 0) {
      z.intlog--;
      f += 1;
    } else {
      z.intlog++;
      f -= 1;
    }
  }
  z.frac = f;
  z.sign = (r.sign != l.sign) ? -1 : 1;
  return (z);
}
inline vlog operator/(const vlog& r, const vlog& l) {
  vlog z;
  z.intlog = r.intlog - l.intlog;
  long f = r.frac - l.frac;
  // TBD>>>>>>>>>>>>
  if (ABS(f) >= 1) {
    if (f < 0) {
      z.intlog--;
      f += 1;
    } else {
      z.intlog++;
      f -= 1;
    }
  }
  z.frac = f;
  z.sign = (r.sign != l.sign) ? -1 : 1;
  return (z);
}
inline vlog operator<<(const vlog& r, const long shift) {
  vlog z(r);
  z.intlog--;
  return (z);
}
inline vlog operator>>(const vlog& r, const long shift) {
  vlog z(r);
  z.intlog++;
  return (z);
}

#define ILOG_MULTOP(T1, T2, RESULT)                               \
  RESULT inline operator+(T1 r, T2 l) { return (r + (RESULT)l); } \
  RESULT inline operator+(T2 r, T1 l) { return (l + (RESULT)r); } \
  RESULT inline operator-(T1 r, T2 l) { return (r - (RESULT)l); } \
  RESULT inline operator-(T2 r, T1 l) { return ((RESULT)r - l); } \
  RESULT inline operator/(T1 r, T2 l) { return (r / (RESULT)l); } \
  RESULT inline operator/(T2 r, T1 l) { return (l / (RESULT)r); } \
  RESULT inline operator*(T1 r, T2 l) { return (r * (RESULT)l); } \
  RESULT inline operator*(T2 r, T1 l) { return (l * (RESULT)r); }

ILOG_MULTOP(float, vlog, float)
ILOG_MULTOP(long, vlog, long)
ILOG_MULTOP(double, vlog, double)
ILOG_MULTOP(int, vlog, int)

#endif
}  // namespace SPUC
#endif

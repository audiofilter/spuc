
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
#include <spuc/vfloat.h>
namespace SPUC {
typedef vfloat self;
// IO functions
std::ostream& operator<<(std::ostream& os, const self& r) {
  os << (double)r;
  return (os);
}
std::istream& operator>>(std::istream& is, self r) {
  double x;
  is >> x;
  r = x;
  return (is);
}
vfloat operator<<(vfloat r, const natural shift) {
  vfloat x = r;
  x.exp += shift;
  return (x);
};

vfloat operator>>(vfloat r, const natural shift) {
  vfloat x = r;
  x.exp -= shift;
  return (x);
};

}  // namespace SPUC

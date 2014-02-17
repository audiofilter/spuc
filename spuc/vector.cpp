
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
// from directory: spuc_vector
#include <iostream>
#include <spuc/vector.h>
namespace SPUC {
template <class T> std::ostream &operator<<(std::ostream& os, const vector<T> &v)
{
    int sz=v.len();
    os << "[" ;
    for (int i=0; i<sz; i++) {
	  os << v(i);
	  if (i < sz-1)
	    os << " ";
    }
    os << "]" ;

    return os;
}
} // namespace SPUC

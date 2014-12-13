
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
// from directory: spuc_src
#include <spuc/utils.h>
namespace SPUC {

using namespace std;
// Removes single quotes ' from beginning and end of string
void remove_quotes(string& paramValStr) {
  const char* startCharacter = "'";
  const char* endCharacter = "'";
  size_t foundFirst, foundSecond, len;
  string paramStr;
  // Look for first
  foundFirst = paramValStr.find_first_of(startCharacter, 0);
  // Look for second
  foundSecond = paramValStr.find_last_of(endCharacter);
  len = foundSecond - foundFirst - 1;
  // Extract substring
  paramValStr = paramValStr.substr(foundFirst + 1, len);
}
void remove_path(string& in) {
  char delim = '/';
  // Split on delim
  size_t pos = in.find_last_of(delim);
  if (pos != string::npos) {
    in = in.substr(pos + 1);
  }
}
}  // namespace SPUC

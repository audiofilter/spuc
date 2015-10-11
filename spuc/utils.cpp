// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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
  if (pos != string::npos) { in = in.substr(pos + 1); }
}
}  // namespace SPUC

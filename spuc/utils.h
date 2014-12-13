#ifndef SPUC_UTILS
#define SPUC_UTILS

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
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <iostream>
#include <fstream>
#include <string>
namespace SPUC {
// Remove ' from beginning and ending of string
void remove_quotes(std::string& p);
// Remove directory path from string
void remove_path(std::string& in);
}  // namespace SPUC
#endif

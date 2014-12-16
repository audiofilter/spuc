#ifndef SPUC_UTILS
#define SPUC_UTILS

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
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

#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
std::vector<double> xcorr(const std::vector<double> &x, unsigned maxlag);
}  // namespace SPUC

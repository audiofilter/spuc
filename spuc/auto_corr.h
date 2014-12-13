#ifndef SPUC_AUTO_CORR
#define SPUC_AUTO_CORR

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
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief Compute the autocorrelation of the Vector
//
//! \brief Compute the autocorrelation of the Vector
//
//! \author Tony Kirke,  Copyright(c) 2001 
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> std::vector<T> auto_corr(const std::vector<T>& x) {
	int i,j;
	T d;
	long N=x.size();
	std::vector<T> autoc(N);
	for (j=0;j<N;j++) {
		for (i = j, d = 0; i < N; i++) d += x[i] * x[i-j];
		autoc[j] = d;
	}
	return(autoc);
}
} // namespace SPUC
#endif

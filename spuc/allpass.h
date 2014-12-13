#ifndef SPUC_ALLPASS
#define SPUC_ALLPASS

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
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <iostream>
#include <fstream>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <spuc/allpass_1.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief  Template Class for allpass filter consisting of
//
//! \brief  Template Class for allpass filter consisting of
//!  several stages of 1st order allpass sections
//! \author Tony Kirke
//! \ingroup double_templates Allpass
template <class Numeric,class Coeff=float_type> class allpass
{
public:
  long stages;
  std::vector<allpass_1<Numeric,Coeff> > ap;
  
public:
  //! ord = Filter order
  allpass(std::vector<Coeff>& design, int n) : ap(n) {
	stages =    n;
	set_coeffs(design);
  }
  Coeff get_coefficient(int i) { return(ap[i].get_coefficient()); }
  //! ord = Filter order
  allpass(long n=1) : ap(n) {  }
  void init(std::vector<Coeff>& design, int n, int d=2) {
	stages =    n;
	ap.resize(stages);
	if (stages>0) set_coeffs(design,d);
  }
  //! Destructor
  ~allpass() {  }
  //! Reset history
  void reset() {
	for (int j=0;j<stages;j++) ap[j].reset();
  } 
  //! Set 1st order ALLPASS coefficients
  void set_coeffs(std::vector<Coeff>& design, int d=2) {
	for (int j=0;j<stages;j++) ap[j].init(design[j],d);
  }
  //! Clock in sample and get output.
  Numeric clock(Numeric in) {
	Numeric tmp = in;
	for (int i=0;i<stages;i++) tmp = ap[i].clock(tmp);
	return(tmp);
  }
};
} // namespace SPUC
#endif

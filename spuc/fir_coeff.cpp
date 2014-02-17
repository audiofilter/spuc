
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
// from directory: spuc_templates
#include <iostream>
#include <fstream>
#include <spuc/complex.h>
#include <spuc/fir_coeff.h>
using namespace std;
namespace SPUC {
template <> void fir_coeff<float_type>::print() {
  cout << "FIR filter coefficients" << '\n';
  for (long i=0;i<num_taps;i++) {
	cout << coeff[i] << cout.width(10) << ' ';
	if ((i+1)%6 == 0) cout << '\n';
  }
  cout << '\n';
  cout.flush();
}
template <> void fir_coeff<long>::print() {
  cout << "FIR filter coefficients" << '\n';
  for (long i=0;i<num_taps;i++) {
	cout << coeff[i] << " ";
	if ((i+1)%6 == 0) cout << '\n';
  }
  cout << '\n';
  cout.flush();
}
template <> void fir_coeff<complex<float_type> >::print() {
  long i;
  cout << "Real FIR filter coefficients" << '\n';
  for (i=0;i<num_taps;i++) {
	cout << real(coeff[i]) << cout.width(10) << ' ';
		if ((i+1)%6 == 0) cout << '\n';
  }
  cout << '\n';
  cout << "Imaginary FIR filter coefficients" << '\n';
  for (i=0;i<num_taps;i++) {
	cout << imag(coeff[i]) << cout.width(10) << ' ';
	if ((i+1)%6 == 0) cout << '\n';
  }	
  cout << '\n';
  cout.flush();
}    
template <> void fir_coeff<complex<long> >::print() {
  long i;
  cout << "Real FIR filter coefficients" << '\n';
  for (i=0;i<num_taps;i++) {
	cout << (long)real(coeff[i]) << cout.width(10) << ' ';
	if ((i+1)%6 == 0) cout << '\n';
  }
  cout << '\n';
  cout << "Imaginary FIR filter coefficients" << '\n';
  for (i=0;i<num_taps;i++) {
	cout << (long)imag(coeff[i]) << cout.width(10) << ' ';
	if ((i+1)%6 == 0) cout << '\n';
  }	
  cout << '\n';
  cout.flush();
}
template <> int fir_coeff< complex<long> >::read_taps(const char* file)
{
// Assumes coeficients are real ONLY.
	int i=0;
	long tmp;
	num_taps = 0;

	ifstream firf(file);
	if (!firf) {
	  cout << "Could not open file " << file << "\n";
	  return(-1);
	}
	while (!firf.eof()) {
	  firf >>	tmp;
	  num_taps++;
	}
	firf.close();

	coeff.resize(num_taps);

	firf.open(file);
	while (!firf.eof()) {
	  firf >> tmp;
	  coeff[i++] = tmp;
	}							
	firf.close();
   
	return(0);
}
template <> int fir_coeff< complex<float_type> >::read_taps(const char* file)
{
// Assumes coeficients are real ONLY.
	int i=0;
	float_type tmp;
	num_taps = 0;

	ifstream firf(file);
	if (!firf) {
	  cout << "Could not open file " << file << "\n";
	  return(-1);
	}
	while (!firf.eof()) {
	  firf >>	tmp;
	  num_taps++;
	}
	firf.close();

	coeff.resize(num_taps);

	ifstream firfx(file);
	while (!firfx.eof()) {
	  firfx >> tmp;
	  coeff[i++] = tmp;
	}							
	firfx.close();
	
	return(0);
}
template <> int fir_coeff<long>::read_taps(const char* file)
{
	int i=0;
	long tmp;
	num_taps = 0;

	ifstream firf(file);
	if (!firf) {
	  cout << "Could not open file " << file << "\n";
	  return(-1);
	}
	while (!firf.eof()) {
			firf >>	tmp;
			num_taps++;
	}
	firf.close();

	coeff.resize(num_taps);

	firf.open(file);
	while (!firf.eof()) firf >> coeff[i++];
	firf.close();
   
	return(0);
}
template <> int fir_coeff<float_type>::read_taps(const char* file)
{
	int i=0;
	float_type tmp;
	num_taps = 0;

	ifstream firf(file);
	if (! firf) {
	  cout << "Error opening file " << file << "\n";
	  return(-1);
	}

	while (!firf.eof()) {
	  firf >>	tmp;
	  num_taps++;
	}
	firf.close();
	
	coeff.resize(num_taps);

	ifstream firfx(file);
	if (! firfx) {
	  cout << "Error opening file " << file << "\n";
	}
	while (!firfx.eof()) {
	  firfx >> coeff[i++];
	}
	firfx.close();
   
	return(0);
}   
} // namespace SPUC

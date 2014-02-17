
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
#include <cmath>
#include <spuc/fir_coeff.h>
#include <spuc/spuc_defines.h>
#include <spuc/butterworth_fir.h>
namespace SPUC {
//! \file
//! \brief calculates the sampled butterworth (max flat) filter impulse response
void butterworth_fir(fir_coeff<float_type>& butfir, float_type spb)
{
/*! 

  With B(p) the butterworth response we have:

\f$ B(p)  = \displaystyle\sum_{k=1}^{N/2} \frac{\lambda(k)*(1+\alpha(k)*p/wc)}{1+2*cos(\beta(k))*p/wc + (p/wc)^2)}.\f$


	   with<p>
	   N = Order of Butterworth filter (always even)<p>
\f$	   \beta(k) = (2 * k - 1) / (2 * N)         k = 1, 2, ..  N/2 \f$<p>
\f$	   \alpha(k) = sin((N/2 - 1) * \beta(k)) / sin(N * \beta(k) / 2) \f$<p>

\f$ \lambda(p)  = \frac{\sin(N*\beta(k)/2)}{sin(\beta(k))}. \displaystyle\prod_{m=1,m!=k}^{N/2} 2*cos(\beta(k) - cos(\beta(m))) \f$


	  The impulse response of B(p) can be found by realizing that:

\f$ \frac{p+a}{(p+a)^2 + w^2} <-> e^{-at} * cos(w*t) \f$

\f$ \frac{w}{(p+a)^2 + w^2} <-> e^{-at} * sin(w*t) \f$

and that B(p) can be written as a linear combination of the these two
expressions:

\f$ \frac{x*(p+a)+y*w}{(p+a)^2 + w^2} <-> e^{-at}*x*cos(w*t) + y* sin(w*t) \f$

We find after some algebra:<p>
\f$ x(k) = \alpha(k) \f$<p>
\f$ w(k) = \sqrt{1 - cos(\beta(k)) * cos((\beta(k)))} \f$<p>
\f$ a(k) = cos(\beta(k)) \f$<p>
\f$ y(k) = (1 - \alpha(k) * cos(\beta(k)) / w(k) \f$<p>
Also used is the time scaling rule for Fourier transforms:
|a| * y(at) <--> Y(f/a)

*/
  int end, i, i2,j;
  float_type x, xend,t;
  int taps = butfir.num_taps;
  int spbi = (int)floor(1.0/spb+0.5);
  int ord = (int)floor(taps/spbi+0.5);
  if (ord%2) ord += 1; // make even
  end = ord / 2;
  xend = (float_type) end;
  smart_array<float_type> beta(end);
  smart_array<float_type> alpha(end);
  smart_array<float_type> ak(end);
  smart_array<float_type> xk(end);
  smart_array<float_type> yk(end);
  smart_array<float_type> wk(end);
  smart_array<float_type> lamda(end);

  for (i = 0; i < end; i++) 	{ 
	x = (float_type) i + 1.0; 
	beta[i] = PI * (2.0 * x - 1.0) / (2.0 * ord); 
	lamda[i] = sin(xend * beta[i]) / sin(beta[i]); 
	alpha[i] = sin((xend - 1.0) * beta[i]) / sin(xend * beta[i]); 
	ak[i] = cos(beta[i]); 
	wk[i] = sqrt(1 - ak[i] * ak[i]); 
	xk[i] = alpha[i];
	yk[i] = ( 1.0 - alpha[i] * ak[i]) / wk[i]; 
  }

  for (i =0; i < end; i++) 
	for (i2 = 0; i2 < end ; i2++) 
	  if (i2 != i) lamda[i] /= ( 2.0 * ( ak[i] - cos(beta[i2])));

  float_type ht;
  for (j=0;j<taps;j++) {
	ht = 0.0;
 	t = TWOPI*j/(float_type)spbi;
	for(i = 0; i < end; i++)
		ht += lamda[i] * ::exp(-t * ak[i]) * ( xk[i] * cos(t * wk[i]) + yk[i] * sin(t * wk[i]));
	butfir.coeff[j] = TWOPI*ht;
  }
}
} // namespace SPUC

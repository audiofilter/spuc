#ifndef SPUC_OTHER_FREQ
#define SPUC_OTHER_FREQ

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
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
namespace SPUC {

template <typename T> void other_freq(T& AP, int pts, double* w, int freq_off, double inc) {

  double d[pts];
#ifdef MONO_ONLY
	  double imp = 1;
#else
  complex<double> imp = 1;
#endif
  double dsum = 0;
  double db=0;
  
  // Calculate equivalent FIR impulse response
  for (int i=0;i<pts;i++) {
#ifdef MONO_ONLY
	  d[i] = (AP.clock(imp));
#else
    d[i] = real(AP.clock(imp));
#endif
    dsum += d[i];
    imp = 0;
    //	  std::cout << "d[" << i << "] = " << d[i] << "\n";
  }
  // Normalization should no longer be needed since scaling should be good!!!
  //  dsum = 1.0/dsum;
  dsum = 1.0;
	  
  // Now calculate frequency response using equivalent normalized 
  // FIR coefficients
  for (int k=0;k<pts;k++) {
    complex<double> sum = 0;
    complex<double> z = complex<double>(1.0,0.0);
    double wf = inc*PI*(k-freq_off)/(double)pts;
    complex<double> z_inc = polar(1.0,(double)wf);
    for (int i=0;i<pts;i++) {
      sum += dsum*d[i]*z;
      z	= z*z_inc;
    }
    //	  std::cout << "w1[" << k << "] = " << sum << "\n";
    db = 10.0*log(magsq(sum))/log(10.0);
    w[k] = db;
  }
}

template <typename T> void fir_freq(T& MF, int pts, double* w, int freq_off, double inc) {

  double t;
  double w_inc = inc*PI/(float)pts; 
  complex<double> z_inc, nom;
	
  for (int i=0;i<pts;i++) {
    double wf = w_inc*(i-freq_off);
    complex<double> z(1,0);
	z_inc = complex<double>(cos(wf),sin(wf));
	nom = 0;
	for (int j=0;j<MF.num_taps;j++) {
	  nom += z*(complex<double>(MF.coeff[j]));
	  //if (i==0) std::cout << "nom = " << nom << " " << MF.coeff[j] << "\n";
	  z *= z_inc;
	}
	t = sqrt(magsq(nom));
    if (t==0) t = 0.00001;
    t = 20.0*log(t)/log(10.0);
    w[i] = t;
  }
}
void cic_freq(int rate, int order, int pts, double* w, int freq_off, double inc); 

/*
 template <typename T> void filt_freq(T& MF, int pts, int bits, double* w, double inc) {

  double h0;
  MF.quantize(bits);
  h0 = MF.freqz_mag(0);
  double h,t,tl;

  double w_inc = inc*PI/(float)pts;
  
  for (int i=0;i<pts;i++) {
    double wf = w_inc*i;
    h = MF.freqz_mag(wf);
    t = h;
    if (t==0) t = 0.00001;
    tl = 20.0*log(t)/log(10.0);
    w[i] = tl;
    //std::cout << "w[" << i << "]=" << w[i] << "\n";
  }
}
*/
	
template <typename T> void iir_freq(T& MF, bool hpf, int pts, int bits, double* w, int freq_off, double inc) {
		
		double h0;
		MF.quantize(bits);
		h0 = MF.freqz_mag(0);
		double h,t,tl;
		
		if (h0 < 0.01) h0 = 1.0;
		if (hpf) h0 = 1.0/MF.hpf_gain;
		
		double w_inc = inc*PI/(float)pts;
		
		for (int i=0;i<pts;i++) {
			double wf = w_inc*(i-freq_off);
			h = MF.freqz_mag(wf);
			t = h/h0;
			if (t==0) t = 0.00001;
			tl = 20.0*log(t)/log(10.0);
			w[i] = tl;
			//std::cout << "w[" << i << "]=" << w[i] << "\n";
		}
	}
	

template <typename T> void other_freq(T& AP, int pts, double* w) {

  double d[pts];
  double imp = 1;
  double dsum = 0;
  double db=0;
  
  // Calculate equivalent FIR impulse response
  for (int i=0;i<pts;i++) {
    d[i] = AP.clock(imp);
    dsum += d[i];
    imp = 0;
  }
  dsum = 1.0/dsum;
    
  // Now calculate frequency response using equivalent normalized 
  // FIR coefficients
  for (int k=0;k<pts;k++) {
    complex<double> sum = 0;
    complex<double> z = complex<double>(1.0,0.0);
    double wf = PI*k/(double)pts;
    complex<double> z_inc = polar(1.0,(double)wf);
    for (int i=0;i<pts;i++) {
      sum += dsum*d[i]*z;
      z	= z*z_inc;
    }
    db = 10.0*log(magsq(sum))/log(10.0);
    w[k] = db;
  }
}

 template <typename T> void filt_freq(T& MF, int pts, int bits, double* w) {

  double h0;
  MF.quantize(bits);
  h0 = MF.freqz_mag(0);
  double h,t,tl;
  
  if (h0 < 0.01) h0 = 1.0;
  
  for (int i=0;i<pts;i++) {
    double wf = PI*i/(float)pts;
    h = MF.freqz_mag(wf);
    t = h/h0;
    if (t==0) t = 0.00001;
    tl = 20.0*log(t)/log(10.0);
    w[i] = tl;
    //std::cout << "w[" << i << "]=" << w[i] << "\n";
  }
}



} // namespace SPUC
#endif

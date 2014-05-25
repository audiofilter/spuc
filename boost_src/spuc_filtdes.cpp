
#include <spuc/fir_coeff.h>
#include <spuc/iir_allpass1.h>
#include <spuc/iir_allpass1_cascade.h>
#include <spuc/notch_allpass.h>
#include <spuc/cutboost.h>
#include <spuc/iir_coeff.h>
#include <spuc/butterworth_iir.h>
#include <spuc/chebyshev_iir.h>
#include <spuc/elliptic_iir.h>
#include <spuc/butterworth_fir.h>
#include <spuc/gaussian_fir.h>
#include <spuc/create_remez_lpfir.h>
#include <spuc/raised_cosine.h>
#include <spuc/root_raised_cosine.h>

#include <string>
#include <iostream>
#include <boost/python/numeric.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>

using std::string;
using namespace boost::python;
using namespace SPUC;

template <typename F> void other_freq(
									  numeric::array& data_out,
									  F AP, 
									  int pts
									  ) {

  float_type d[pts];
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
  //  std::cout << "impulse scale = " << dsum << "\n";

  // Now calculate frequency response using equivalent normalized 
  // FIR coefficients
  for (int k=0;k<pts;k++) {
	complex<double> sum = 0;
	complex<double> z = complex<double>(1.0,0.0);
	double w = PI*k/(double)pts;
	complex<double> z_inc = polar(1.0,(double)w);
	for (int i=0;i<pts;i++) {
	  sum += dsum*d[i]*z;
	  z	= z*z_inc;
	}
	db = 10.0*log(magsq(sum))/log(10.0);
	data_out[k] = db;
	//	std::cout << " db[" << k << "] = " << db << "\n";
  }
}


template <typename F> void filt_freq(
									 numeric::array& data_out,
									 F MF, int taps,
									 int bits,
									 int pts)
{
  MF.quantize(bits);
  double h0 = MF.freqz_mag(0);
  double h,t,tl;
  
  if (h0 < 0.01) h0 = 1.0;
  
  for (int i=0;i<pts;i++) {
	double w = PI*i/(float_type)pts;
	h = MF.freqz_mag(w);
	t = h/h0;
	if (t==0) t = 0.00001;
	tl = 20.0*log(t)/log(10.0);
	data_out[i] = tl;
  }
}


void filtdes(numeric::array& data_out,
			 string filtType,
			 int pts,
			 float_type pass_edge,
			 float_type trans,
			 float_type stop_dBs,
			 int taps,
			 int bits,
			 int order,
			 float_type alpha)
{

  float_type iir_pass_edge = 2*pass_edge;
  float_type hb_trans = trans/2;
  float_type stop_edge = pass_edge + trans;
  float_type notch_trans = 1.0-hb_trans;


  if (stop_edge > 0.42) stop_edge = 0.42;
  float_type stop_weight = pow(10.0,(-stop_dBs/20.0));
  float_type	ripple = stop_weight;

  if(ripple>1) ripple = 1;

  float_type elliptic_ripple = 2*alpha;

  iir_coeff CF(order);
  fir_coeff<float_type> MF(taps);

  int use_fir = 0;
  int use_iir = 0;

  std::cout << "Type = " << filtType << "\n";

  if (filtType == "Maxflat FIR") {
	butterworth_fir(MF, pass_edge);
	use_fir = 1;
  }	else if (filtType == "Remez FIR") {
	create_remez_lpfir(MF,pass_edge,stop_edge,stop_weight);
	use_fir = 1;
  }	else if (filtType == "Gaussian FIR") {
	gaussian_fir(MF, pass_edge, 8);
	use_fir = 1;
  }	else if (filtType == "Raised Cosine FIR") {
	raised_cosine(MF, alpha, 2);
	use_fir = 1;
  }	else if (filtType == "Root Raised Cosine FIR") {
	root_raised_cosine(MF, alpha, 2);
	use_fir = 1;
  } else if (filtType == "Elliptic") {
    elliptic_iir(CF,iir_pass_edge,true,stop_edge,stop_dBs,elliptic_ripple);
    use_iir = 1;
  } else if (filtType == "Chebyshev") {
    chebyshev_iir(CF,iir_pass_edge,true,ripple);
    use_iir = 1;
  }	else if (filtType == "Notch IIR") {
    notch_allpass<float_type,float_type> NF(pass_edge,notch_trans);
    other_freq(data_out,NF,pts);
  }	else if (filtType == "Cut Boost") {
	cutboost<float_type,float_type> BF(pass_edge,notch_trans,stop_weight);
	other_freq(data_out,BF,pts);
  } else if ((filtType == "Elliptic Halfband IIR") || (filtType == "Maxflat Halfband IIR")) {
	// when edge >= 0, then butterworth coefficients are calculated
	if (filtType == "Maxflat Halfband IIR") pass_edge = 0.0;
	iir_allpass1_cascade<float_type,float_type> AF(pass_edge,order,bits);
	other_freq(data_out,AF,pts);
  } else {
    butterworth_iir(CF,iir_pass_edge,true,3.0);
	use_iir = 1;
  }


  if (use_fir) {
	filt_freq(data_out, MF, taps, bits, pts);
	//	for (int i=0;i<taps;i++) std::cout << "MF[" << i << "] = " << MF.gettap(i) << "\n";
  }
  if (use_iir) {
	filt_freq(data_out, CF, taps, bits, pts);
  }



}

BOOST_PYTHON_MODULE(spuc_filtdes)
{
  numeric::array::set_module_and_type("numpy","ndarray");
  def("filtdes", &filtdes);
}

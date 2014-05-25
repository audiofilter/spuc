#include <spuc/quantize.h>
#include <spuc/cutboost.h>
#include <spuc/noise.h>
#include <spuc/butterworth_iir.h>
#include <spuc/iir.h>
#include <spuc/iir_coeff.h>
#include <iostream>
#include <boost/python/numeric.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
//#define DEBUG
using namespace boost::python;
using namespace SPUC;

void audio_noise(numeric::array& data_in, float gain) {
  static noise N;
  int l,r;
  int samples=extract<int>(data_in.attr("__len__")());
  float amp = gain*2048.0;
  for (int i=0;i<samples/4;i++) {
	float y = amp*N.gauss();
	l = (int)floor(y+0.5);
	r = 0;
#ifdef DEBUGX
	std::cout << l << "\n";
#endif
	data_in[i]   = (l << 16) + (r & 0xffff);
  }
}
// edge is tone frequency in kHz
void audio_tone(numeric::array& data_in, float edge, float gain)
{
  int samples=extract<int>(data_in.attr("__len__")());
  static float phase=0;
  float phase_inc = TWOPI*edge/22.050;
  long l,r;
  for (int i=0;i<samples;i++) {
	phase = phase + phase_inc;
	l = (long)floor(gain*16384.0*::cos(phase)+0.5);
	r = l;
#ifdef DEBUGX
	std::cout << l << " " << r << "\n";
#endif
	data_in[i]   = (long)((l << 16) + (r & 0xffff));
  }
}
void audio_cutboost(numeric::array& data_in, float freq, float depth) {
  static cutboost<complex<float> > N(0.1,0.0,0.0);
  static float last_freq = 0;
  static float last_depth = 0;
  const float gain = 1.0;
  //  static int call_count = 0;
  //  int dump_audio = 0;
  int l,r,lr;
  if (freq != last_freq) {
	N.set_depth(freq);
	last_freq = freq;
	//	dump_audio = 1;
#ifdef DEBUG
	std::cout << "Notch Frequency change = " << freq << "\n";
#endif
  }
  if (depth != last_depth) {
	N.set_freq(depth);
	last_depth = depth;
#ifdef DEBUG
	std::cout << "Notch Depth change = " << depth << "\n";
#endif
  }
  if(freq != 0.0) {
	int samples=extract<int>(data_in.attr("__len__")());
	//	std::cout << " Len = " << samples << "\n";
	for (int i=0;i<samples;i++) {
	  // Get as 32-bit int with I and Q contained within
	  // would be better as 16-bit stuff!!!
	  lr  =  extract<int>(data_in[i]);
	  // Separate
	  l  =  lr >> 16;
	  r  =  (lr << 16) >> 16;
	  complex<float> y = N.clock(complex<float>(l,r));
	  complex<long>  z = quantize(gain*y);
#ifdef DEBUG
	  std::cout << l << " " << r << " ";
	  std::cout << real(z) << " " << imag(z) << "\n";
#endif
	  data_in[i]   = ((int)(real(z)) << 16) + ((int)(imag(z)) & 0xffff);
	}
	//  call_count++;
	//  if (call_count > WRAP_COUNT) call_count = 0;
  }
}
void audio_butterworth(numeric::array& data_in, float edge)
{
  int l,r,lr;
  int i;
  static iir_coeff CF(8);
  static iir<complex<float> > BW(8);
  static float saved_edge = 0.25;
  static float gain=1.0;
  if (edge != saved_edge) {
    butterworth_iir(CF,edge,true,3.0);
    BW.set_coeffs(CF);
    complex<float> sum(0.0,0.0);
    // Crude way to normalize the filter gain
    // first flush
    for(i=0;i<1000;i++) BW.clock(complex<float>(0.0,0.0));
    // then impulse response
    sum += BW.clock(complex<float>(1.0,0.0));
    for(i=0;i<1000;i++) sum += BW.clock(complex<float>(0.0,0.0));
    gain = 1.0/real(sum);
    std::cout << " gain = " << gain << "\n";
    saved_edge = edge;
  }
  if(edge != 0.0) {
	int samples=extract<int>(data_in.attr("__len__")());
	//	std::cout << " Len = " << samples << "\n";
	for (int i=0;i<samples;i++) {
	  // Get as 32-bit int with I and Q contained within
	  // would be better as 16-bit stuff!!!
	  lr  =  extract<int>(data_in[i]);
	  // Separate
	  l  =  lr >> 16;
	  r  =  (lr << 16) >> 16;
	  complex<float> y = BW.clock(complex<float>(l,r));
	  complex<long>  z = quantize(gain*y);
#ifdef DEBUG
	  std::cout << l << " " << r << " ";
	  std::cout << real(z) << " " << imag(z) << "\n";
#endif
	  data_in[i]   = ((int)(real(z)) << 16) + ((int)(imag(z)) & 0xffff);
	}
  }
}

BOOST_PYTHON_MODULE(spuc_audio)
{
  def("set_module_and_type", &numeric::array::set_module_and_type);
  def("audio_noise", &audio_noise);
  def("audio_tone", &audio_tone);
  def("audio_cutboost", &audio_cutboost);
  def("audio_butterworth", &audio_butterworth);
}

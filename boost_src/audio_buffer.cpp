#include <spuc/audio_buffer.h>
#include <spuc/audio_examples.h>
namespace SPUC {
std::string audio_buffer::bypass(const std::string& ibuf,  float gain) {
  buf = ibuf;
  int samples = ibuf.length();
  for (int i=0;i<samples/2;i++) {
	int x        = ((int)ibuf[2*i+1] << 8) | ((int)ibuf[2*i] & 0xff);
	buf[2*i+1]   = (x >> 8) & 0xff;
	buf[2*i]     = x & 0xff;
  }
  return(buf);
}
std::string audio_buffer::random_noise(const std::string& ibuf,  float gain) {
  buf = ibuf;
  run_noiseb(buf,gain);
  return(buf);
}
std::string audio_buffer::tone(const std::string& ibuf,  float edge) {
  buf = ibuf;
  run_toneb(buf,edge);
  return(buf);
}
std::string audio_buffer::cutboost(const std::string& ibuf, 
							  float freq, float depth) {
  buf = ibuf;
  run_cutboostb(buf,freq,depth);
  return(buf);
}
std::string audio_buffer::butterworth(const std::string& ibuf,  float edge) {
  buf = ibuf;
  run_butterworthb(buf,edge);
  return(buf);
}
std::string audio_buffer::gen_noise(float gain) {
  return(gen_noiseb(gain));
}
std::string audio_buffer::gen_tone(float edge) {
  return(gen_toneb(edge));
}
char* audio_buffer::toneb(float edge) {
  run_tone(&lbuf[0],512,edge);
  return(lbuf); 
}
}


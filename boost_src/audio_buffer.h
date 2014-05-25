#ifndef SPUC_AUDIO_BUFFER
#define SPUC_AUDIO_BUFFER
#include <iostream>
#include <string>
namespace SPUC {
class audio_buffer
{
 public:
	float saved_edge;
	float phase;
	float last_freq;
	float last_depth;

	audio_buffer(const std::string& ibuf) : 
		saved_edge(0.25), phase(0), last_freq(0), last_depth(0)
		{ this->buf = ibuf; }
	~audio_buffer() {;}
	std::string gen_tone(float edge); 
	std::string gen_noise(float gain); 
	char* toneb(float edge);
	inline int len() const { return buf.length(); }
	inline char operator()(int i) const { return buf[i]; }
	inline char operator[](int i) const { return buf[i]; }
	std::string tone(const std::string& ibuf,  float edge); 
	std::string random_noise(const std::string& ibuf, float gain); 
	std::string bypass(const std::string& ibuf, float gain); 
	std::string cutboost(const std::string& ibuf,  
						 float freq, float depth); 
	std::string butterworth(const std::string& ibuf,  float edge); 
 private:
	std::string buf;
	char lbuf[512];

};
} // namespace
#endif

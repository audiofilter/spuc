#ifndef EQUALIZER_H
#define EQUALIZER_H
namespace SPUC {
class equalizer
{
 public:
	equalizer(void) {;}
	bool symclk() { return(1); };
	bool data() { return(1); };
	void clock(cmplx<double> in) {;	}
};
}
#endif

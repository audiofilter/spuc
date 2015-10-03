#include "plot_fft.h"
#include "MPLPlot.h"
#include <spuc/cfft.h>
using namespace SPUC;

void plot_fft(std::vector<double>& data)
{
  const long N=data.size();
	Dictionary d;
	d.add("lw", 3.1);

	std::unique_ptr<complex<double> []> z(new complex<double>[N]);
	for (unsigned int i = 0; i < N; i++) z[i] = data[i];
	
	cfft F(N);
	F.fft(z.get());

	std::vector<double> fft(N/2);

	for (int i=0;i<N/2;i++) {
		double val = magsq(N*z[i]);
		if (val < 1e-6) val = 1e-6;
		fft[i] = 10.0*log10(val);
	}

	PyPlotter plt;
	plt.init();
	plt.plot_data(fft, &d);
	plt.load_data();
	plt.show();
}

void plot_data(std::vector<double>& data)
{
	Dictionary d;
	d.add("lw", 3.1);
	PyPlotter plt;
	plt.init();
	plt.plot_data(data, &d);
	plt.load_data();
	plt.show();
}

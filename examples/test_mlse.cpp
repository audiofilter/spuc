#include <spuc/max_pn.h>
#include <spuc/delay.h>
#include <spuc/fir.h>
#include <spuc/mle.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace SPUC;
using namespace std;
int main(int argv, char* argc[]) {

	int i;
	max_pn pn(0x006d, 63, -1);  // Maximal length PN sequence for data
	char data=-1;
	char taps=3;
	fir<float_type,float_type> tx_fir(taps);
	float_type tx_data,rx_data;
	long path_out;
	bool bit_out;
	bool ref_data;
	bool ref_dly;
	long error=0;
	ofstream resf("mlse.dat");
	ofstream reff("refmlse.dat");
	ofstream rawf("raw.dat");
	delay <bool> delayed_ref(34);
	tx_fir.settap(0,1.0);
	tx_fir.settap(1,-1.5);
	tx_fir.settap(2,0.5);
	mle<float_type> viterbi(taps);
	for (i=0;i<taps;i++) {
		viterbi.cfir.settap(i,tx_fir.coeff[i]);
	}

	for (i=0;i<20;i++) pn.out();

	for (i=0;i<132;i++) {
		data = pn.out(); 
		ref_data = (data == 1) ? 1 : 0;
		ref_dly = delayed_ref.update(ref_data);
		tx_data = tx_fir.update(data);
		rx_data = tx_data; // + noise?
		path_out = viterbi.mlsd(rx_data);
		bit_out = (path_out & 0x80000000) ? 1 : 0;
		rawf << rx_data << '\n';
		reff << ref_dly;
		resf << bit_out;
		error += (ref_dly != bit_out);
		cout << setw(8) << setfill('0') << hex << path_out << ' ' << error << '\n';
	}
	reff.close();
	resf.close();
	rawf.close();
	return(1);
}

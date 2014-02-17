#ifndef SPUC_CONVOLUTIONAL_INTERLEAVER
#define SPUC_CONVOLUTIONAL_INTERLEAVER

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
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <spuc/delay.h>
#include <spuc/bit.h>
#include <spuc/matrix.h>
namespace SPUC {
//! \file 
//!  \brief Definitions of convolution interleaver class
//!  \author T Kirke
#define MAXINTLVR 128
//! \author Tony Kirke
//! \ingroup templates interl
//!  \class convolutional_interleaver comm/conv_interleaver.h
//!  \endcode
template <class T> class convolutional_interleaver {
 public:
	//! convolutional_interleaver constructor
	convolutional_interleaver(void) {rows = 0; cols = 0; rd_sel = wr_sel = 0;}
	//! convolutional_interleaver constructor
	convolutional_interleaver(int in_rows, int in_cols);
	//! Function for convolutional interleaving.
	T interleave(const T input);
	void interleave_write(const T input);
	T interleave_read(void);
	//! Function for convolutional deinterleaving.
	T deinterleave(const T input);
	//! Set the number of \a rows for block interleaving
	void set_size(int in_rows, int in_cols) {
		int i;
		rows = in_rows;
		cols = in_cols;
		input_length = 0;
		if (rows > MAXINTLVR) rows = MAXINTLVR;
		for (i=0;i<rows;i++) {
				D[i].set_size(i*cols);
		}
		wr_sel = 0;
			rd_sel = 0;
	}
	//! Get the number of \a rows for block interleaving
	int get_rows(void) {return rows;}
	//! Get the number of \a columns for block interleaving    
	int get_cols(void) {return cols;}
	void reset(void)
	{
		int i;
		for (i=0;i<rows;i++) D[i].reset();
		wr_sel = 0;
		rd_sel = 0;
	}
	void resync(void) { 
		wr_sel = 0;
		rd_sel = 0;
	}
 private:
	int rows, cols, input_length;
	int wr_sel;
	int rd_sel;
	delay<T> D[MAXINTLVR];

};
	
//
// Convolutional Interleaver
//
template<class T>
convolutional_interleaver<T>::convolutional_interleaver(int in_rows, int in_cols)
{
	int i;
	rows = in_rows;
	cols = in_cols;
	input_length = 0;
	if (rows > MAXINTLVR) rows = MAXINTLVR;
	for (i=0;i<rows;i++) {
		D[i].set_size(i*cols);
	}
	rd_sel = wr_sel = 0;
}
	
template<class T>
T convolutional_interleaver<T>::interleave(const T input)
{
	interleave_write(input);
	return(interleave_read());
}
template<class T>
void convolutional_interleaver<T>::interleave_write(const T input)
{
	D[wr_sel].input(input);
	wr_sel++;
	wr_sel = wr_sel % rows;
}
template<class T>
T convolutional_interleaver<T>::interleave_read(void)
{
	T outp = D[rd_sel].last();
	rd_sel++;
	rd_sel = rd_sel % rows;
	return(outp);
}
template<class T>
T convolutional_interleaver<T>::deinterleave(const T input)
{
	// not using rd_sel yet!
	T outp = D[rows-1-wr_sel].update(input);
	wr_sel++;
	wr_sel = wr_sel % rows;
	return(outp);
}
} // namespace SPUC
#endif

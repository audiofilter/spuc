
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
#include <spuc/sigma_delta.h>
namespace SPUC {

sigma_delta::sigma_delta(char nin, char nout) {
	nbit_in = 31-nin;
	nbit_out = 32-nout;
	acc = 0;
	mask = (0xffffffff>>nout);
}               
signed char sigma_delta::single(signed long in)
{          
	signed long tmp = (in<<nbit_in); 
	acc += tmp;
	tmp = acc&(~mask);
	signed char out = (char)(tmp>>nbit_out);
	acc -= tmp;
	return(out);
}
} // namespace SPUC

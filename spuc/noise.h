#ifndef SPUC_NOISE
#define SPUC_NOISE

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
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief Gaussian noise routine
//
//! \brief Gaussian noise routine
//
//!  Can create (float_type) gaussian white noise,
//!             <p>complex<float_type> gaussian white noise
//!             <p>or (float_type) uniform noise
//!  <p>Requires complex template class
//! \author Tony Kirke
//! \ingroup classes misc random
class noise
{   
	protected:
	char s;            //! Switch 
	float_type x;          //! Saved calculated value
    long idum;         //! Random seed
    
	public:                            
    //! Constructor
	noise(float_type i=1349555.0);						// Constructor
  	//! Gaussian noise
	float_type gauss();
	//! complex gaussian noise
	complex<float_type> Cgauss(void);
	//! Uniform noise
	float_type uni();             
	//! Uniform noise
	float_type uniform();
	//!  Change seed
    //	void set_seed(float_type i=1349555.0) { idum = (long)i;}
	//!  Change seed
	void set_seed(unsigned i=1349555) { idum = i;}
} ;
} // namespace SPUC
#endif

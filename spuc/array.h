#ifndef SPUC_ARRAY
#define SPUC_ARRAY

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
namespace SPUC {
/*---------------------------------------------------------------------------*
 *                                   IT++			             *
 *---------------------------------------------------------------------------*
 * Copyright (c) 1995-2002 by Tony Ottosson, Thomas Eriksson, Pål Frenger,   *
 * Tobias Ringström, and Jonas Samuelsson.                                   *
 *                                                                           *
 * Permission to use, copy, modify, and distribute this software and its     *
 * documentation under the terms of the GNU General Public License is hereby *
 * granted. No representations are made about the suitability of this        *
 * software for any purpose. It is provided "as is" without expressed or     *
 * implied warranty. See the GNU General Public License for more details.    *
 *---------------------------------------------------------------------------*/
//! 
//! Original code modified by Tony Kirke Feb 1, 2003
//! author="Tony Kirke" *
//  SPUC - Signal processing using C++ - A DSP library

//! 
//!  \file 
//!  \brief array class (container)
//!  \author Tobias Ringstrom
//!  1.10  2003/01/04 00:21:53
/*  
  This file is not separated into a .h and a .cpp file. The reason is to avoid problems with template initializations of this class.
  An \c array<type> can contain any type and it is not possible to initialize and pre-compile all types that might be put into an \c array.
  
*/
/*! 
  \brief General array class

  This class is a general linear array class for arbitrary types. The operations
  and functions are the same as for the vector Vec class (except for the arithmetics).
  
  For rarely used types you will need to instantiate the class by
  \code
  template class array<type>;
  \endcode

  The following example shows how to define an array of vectors:
  \code
  vec a = randn(10);
  vec b = randn(20);
  vec c = randn(30);
  array<vec> my_array(3);
  my_array(0) = a;
  my_array(1) = b;
  my_array(2) = c;
  \endcode
*/
template<class T> class array {
 public:
  //! Default constructor
  array();
  //! Create an array of size \c n
  array(int n);
  //! Create a copy of \c a
  array(const array<T> &a);
  //! Default destructor
  virtual ~array();
	
  //! Get the \c i element
  T &operator()(int i) {
//    it_assert0(i>=0&&i<ndata,"array::operator()"); 
	  return data[i]; }
  //! Get the \c i element
  T operator()(int i) const {
    //it_assert0(i>=0&&i<ndata,"array::operator()");
	  return data[i]; }
  //! Sub-array from element \c i1 to element \c i2
  array<T> operator()(int i1, int i2) const;
  //! Sub-array with the elements given by the integer array
  array<T> operator()(const array<int> &indices) const;
  
  //! Assignment operator
  void operator=(T e);
  //! Assignment operator
  void operator=(const array<T> &a);
	
  //! Append element \c e to the end of the array \c a
  //  friend array<T> concat TEMPLATE_FUN(const array<T> &a1, const T e);
  //! Concat element \c e to the beginning of the array \c a
  //  friend array<T> concat TEMPLATE_FUN(const T e, const array<T> &a);
  //! Concat arrays \c a1 and \c a2
  //  friend array<T> concat TEMPLATE_FUN(const array<T> &a1,const array<T> &a2);
  //! Concat arrays \c a1, \c a2 and \c a3
  //  friend array<T> concat TEMPLATE_FUN(const array<T> &a1, const array<T> &a2, const array<T> &a3);

  //! Returns the number of data elements in the array object
  int size() const { return ndata; }
  //! Returns the number of data elements in the array object
  int length() const { return ndata; }
  //! Resizing an array<T>.
  void set_size(int n, bool copy=false);
  //! Resizing an array<T>.
  void set_length(int n, bool copy=false) { set_size(n, copy); }

  //! Shift in data at position 0. return data at last position.
  T shift_right(T e);
  //! Shift in array at position 0. return data at last position.
  array<T> shift_right(const array<T> &a);
  //! Shift in data at position Ndata()-1. return data at last position.
  T shift_left(T e);
  //! Shift in array at position Ndata()-1. return data at last position.
  array<T> shift_left(const array<T> &a);
  //! Swap elements i and j.
  void swap(int i, int j);

  //! Set the subarray defined by indicies i1 to i2 to array<T> a.
  void set_subarray(int i1, int i2, const array<T> &a);
  //! Set the subarray defined by indicies i1 to i2 the element value t.
  void set_subarray(int i1, int i2, const T t);

//protected:
 private:
  bool in_range(int i) { return ((i<ndata) && (i>=0)); }
  int ndata;
  T *data;

 private:
  void alloc(int n);
  void free();
};

// --------------------------- Implementation starts here ----------------------------------

template<class T>
array<T>::array()
{
    data = 0;
    ndata = 0;
}

template<class T>
array<T>::array(int n)
{
    alloc(n);
}

template<class T>
array<T>::array(const array<T> &a)
{

  //  data=NULL;
  ndata=0;
  alloc(a.ndata);
  for (int i=0; i<a.ndata; i++)
    data[i] = a.data[i];
}

template<class T>
array<T>::~array()
{
  free();
}

template<class T>
void array<T>::alloc(int n)
{
  if (n == 0) {
	//    data = NULL;
    ndata = 0;
  }
  else {
    data = new T[n];
//    it_assert1(data!=0, "Out of memory in array::alloc");
  }
  ndata = n;
}

template<class T>
void array<T>::free()
{

  delete [] data;
	
  data = 0;
  ndata = 0;
}

template<class T>
array<T> array<T>::operator()(int i1, int i2) const
{
	//    it_assert0(i1>=0 && i2>=0 && i1<ndata && i2<ndata && i2>=i1, "array::operator()(i1,i2)");
    array<T> s(i2-i1+1);
    int i;
	
    for (i=0; i<s.ndata; i++)
	s.data[i] = data[i1+i];
	
    return s;
}

template<class T>
array<T> array<T>::operator()(const array<int> &indices) const
{
    array<T> a(indices.size());

    for (int i=0; i<a.size(); i++) {
		//	it_assert0(indices(i)>=0&&indices(i)<ndata,"array::operator()(indicies)");
	a(i) = data[indices(i)];
    }

    return a;
}

template<class T>
void array<T>::operator=(const array<T> &a)
{
    set_size(a.ndata);
    for (int i=0; i<ndata; i++)
	data[i] = a.data[i];
}


template<class T>
void array<T>::operator=(T e)
{
    for (int i=0; i<ndata; i++)
	data[i] = e;
}


template<class T>
void array<T>::set_size(int sz, bool copy)
{
    int i, min;
    T *tmp;

    if (ndata == sz)
      return;
		
    if (copy) {
      tmp = data;
      min = ndata < sz ? ndata : sz;
      alloc(sz);
      for (i=0; i<min; i++)
	data[i] = tmp[i];
      delete [] tmp;
    } else {
      free();
      alloc(sz);
    }
    ndata = sz;
}

template<class T>
T array<T>::shift_right(T x)
{
    T ret;

	//    it_assert1(ndata>0, "shift_right");
    ret = data[ndata-1];
    for (int i=ndata-1; i>0; i--)
	data[i] = data[i-1];
    data[0] = x;
	
    return ret;
}


template<class T>
array<T> array<T>::shift_right(const array<T> &a)
{
    int	i;
    array<T> out(a.ndata);

	//    it_assert1(a.ndata<=ndata, "Shift array too large");
    for (i=0; i<a.ndata; i++)
	out.data[i] = data[ndata-a.ndata+i];
    for (i=ndata-1; i>=a.ndata; i--)
	data[i] = data[i-a.ndata];
    for (i=0; i<a.ndata; i++)
	data[i] = a.data[i];
	
    return out;
}

template<class T>
T array<T>::shift_left(T x)
{
    T temp = data[0];
	
    for (int i=0; i<ndata-1; i++)
	data[i]=data[i+1];
    data[ndata-1] = x;
	
    return temp;
}

template<class T>
array<T> array<T>::shift_left(const array<T> &a)
{
    int	i;
    array<T> out(a.ndata);

	//    it_assert1(a.ndata<=ndata, "Shift array too large");
    for (i=0; i<a.ndata; i++)
	out.data[i] = data[i];
    for (i=0; i<ndata-a.ndata; i++) {
      // out.data[i] = data[i]; removed. Is not necessary
	data[i] = data[i+a.ndata];
    }
    for (i=ndata-a.ndata; i<ndata; i++)
	data[i] = a.data[i-ndata+a.ndata];
	
    return out;
}

template<class T>
void array<T>::swap(int i, int j)
{
  //    it_assert1(in_range(i) && in_range(j) , "Shift array too large");
    
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

template<class T>
void array<T>::set_subarray(int i1, int i2, const array<T> &a)
{
  if (i1 == -1)	i1 = ndata-1;
  if (i2 == -1) i2 = ndata-1;
  
  //  it_assert1(in_range(i1) && in_range(i2), "array<T>::set_subarray(): indicies out of range");
  //  it_assert1(i2>=i1, "array<T>::set_subarray(): i2 >= i1 necessary");
  //  it_assert1(i2-i1+1 == a.ndata, "array<T>::set_subarray(): wrong sizes");

  memcpy(data+i1, a.data, a.ndata*sizeof(T));
}

template<class T>
void array<T>::set_subarray(int i1, int i2, const T t)
{
  if (i1 == -1)	i1 = ndata-1;
  if (i2 == -1) i2 = ndata-1;
  
  //  it_assert1(in_range(i1) && in_range(i2), "array<T>::set_subarray(): indicies out of range");
  //  it_assert1(i2>=i1, "array<T>::set_subarray(): i2 >= i1 necessary");

  for (int i=i1;i<=i2;i++)
    data[i] = t;
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS 
//Doxygen warnings on these functions

template<class T>
array<T> concat(const array<T> &a, const T e)
{
    array<T> temp(a.size()+1);

    for (int i=0; i<a.size(); i++)
	temp(i) = a(i);
    temp(a.size()) = e;

    return temp;
}

template<class T>
array<T> concat(const T e, const array<T> &a)
{
    array<T> temp(a.size()+1);

    temp(0) = e;

    for (int i=0; i<a.size(); i++)
	temp(i+1) = a(i);

    return temp;
}

template<class T>
array<T> concat(const array<T> &a1, const array<T> &a2)
{
    int i;
    array<T> temp(a1.size()+a2.size());

    for (i=0;i<a1.size();i++) {
	temp(i) = a1(i);
    }
    for (i=0;i<a2.size();i++) {
	temp(a1.size()+i) = a2(i);
    }
    return temp;
}

template<class T>
array<T> concat(const array<T> &a1, const array<T> &a2, const array<T> &a3)
{
  // There should be some error control?
    int i;
    array<T> temp(a1.size()+a2.size()+a3.size());

    for (i=0;i<a1.size();i++) {
	temp(i) = a1(i);
    }
    for (i=0;i<a2.size();i++) {
	temp(a1.size()+i) = a2(i);
    }
    for (i=0;i<a3.size();i++) {
	temp(a1.size()+a2.size()+i) = a3(i);
    }
    return temp;
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*! 
  \relates array
  \brief Output stream for the array class
*/
#ifdef XXX
template<class T>
inline std::ostream &operator<<(std::ostream &o, const array<T> &a)
{
  o << "{";
    for (int i=0; i<a.size()-1; i++)
	o << a(i) << " ";
    if (a.size() > 0)
	o << a(a.size()-1);

    o << "}";

    return o;
}
#endif
} // namespace SPUC
#endif

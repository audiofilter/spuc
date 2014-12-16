#ifndef SPUC_ARRAY2D
#define SPUC_ARRAY2D
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <cstdlib>
#include <iostream>
#ifdef SPUC_BOUNDS_CHECK
#include <cassert>
#endif
namespace SPUC {
/*
*
* Template Numerical Toolkit (TNT): Two-dimensional numerical array
*
* Mathematical and Computational Sciences Division
* National Institute of Technology,
* Gaithersburg, MD USA
*
*
* This software was developed at the National Institute of Standards and
* Technology (NIST) by employees of the Federal Government in the course
* of their official duties. Pursuant to title 17 Section 105 of the
* United States Code, this software is not subject to copyright protection
* and is in the public domain. NIST assumes no responsibility whatsoever for
* its use by other parties, and makes no guarantees, expressed or implied,
* about its quality, reliability, or any other characteristic.
*
*/
//! \file
//! \brief  Templated two-dimensional, numerical array which
//!  looks like a conventional C multiarray.
/**
        Templated two-dimensional, numerical array which
        looks like a conventional C multiarray.
        Storage corresponds to C (row-major) ordering.
        Elements are accessed via A[i][j] notation.

        <p>
        Array assignment is by reference (i.e. shallow assignment).
        That is, B=A implies that the A and B point to the
        same array, so modifications to the elements of A
        will be reflected in B. If an independent copy
        is required, then B = A.copy() can be used.  Note
        that this facilitates returning arrays from functions
        without relying on compiler optimizations to eliminate
        extensive data copying.

        <p>
        The indexing and layout of this array object makes
        it compatible with C and C++ algorithms that utilize
        the familiar C[i][j] notation.  This includes numerous
        textbooks, such as Numercial Recipes, and various
        public domain codes.

        <p>
        This class employs its own garbage collection via
        the use of reference counts.  That is, whenever
        an internal array storage no longer has any references
        to it, it is destoryed.
*/
template <class T> class array2d {
 private:
  T** v_;
  int m_;
  int n_;
  int* ref_count_;

  void initialize_(int m, int n);
  void copy_(T* p, const T* q, int len) const;
  void set_(const T& val);
  void destroy_();
  inline const T* begin_() const;
  inline T* begin_();

 public:
  typedef T value_type;

  array2d();
  array2d(int m, int n);
  array2d(int m, int n, T* a);
  array2d(int m, int n, const T& a);
  inline array2d(const array2d& A);
  inline array2d& operator=(const T& a);
  inline array2d& operator=(const array2d& A);
  inline array2d& ref(const array2d& A);
  array2d copy() const;
  array2d& inject(const array2d& A);
  inline T* operator[](int i);
  inline const T* operator[](int i) const;
  inline int dim1() const;
  inline int dim2() const;
  inline int ref_count() const;
  ~array2d();
  // NEW
  inline int cols() const;
  inline int rows() const;
  array2d<T>& newsize(int m, int n) { return (set_size(m, n)); }
  array2d<T>& set_size(int m, int n) {
    if (dim1() == m && dim2() == n) return *this;
    destroy_();
    initialize_(m, n);
    return *this;
  }
  // NEW
};

/**
        Copy constructor. Array data is NOT copied, but shared.
        Thus, in array2d B(A), subsequent changes to A will
        be reflected in B.  For an indepent copy of A, use
        array2d B(A.copy()), or B = A.copy(), instead.
*/
template <class T> array2d<T>::array2d(const array2d<T>& A) : v_(A.v_), m_(A.m_), n_(A.n_), ref_count_(A.ref_count_) {
  (*ref_count_)++;
}

/**
        Create a new (m x n) array, WIHOUT initializing array elements.
        To create an initialized array of constants, see array2d(m,n,value).

        <p>
        This version avoids the O(m*n) initialization overhead and
        is used just before manual assignment.

        @param m the first (row) dimension of the new matrix.
        @param n the second (column) dimension of the new matrix.
*/
template <class T> array2d<T>::array2d(int m, int n) : v_(0), m_(m), n_(n), ref_count_(0) {
  initialize_(m, n);
  ref_count_ = new int;
  *ref_count_ = 1;
}

/**
        Create a new (m x n) array,  initializing array elements to
        constant specified by argument.  Most often used to
        create an array of zeros, as in A(m, n, 0.0).

        @param m the first (row) dimension of the new matrix.
        @param n the second (column) dimension of the new matrix.
        @param val the constant value to set all elements of the new array to.
*/
template <class T> array2d<T>::array2d(int m, int n, const T& val) : v_(0), m_(m), n_(n), ref_count_(0) {
  initialize_(m, n);
  set_(val);
  ref_count_ = new int;
  *ref_count_ = 1;
}

/**
        Create a new (m x n) array,  as a view of an existing one-dimensional
        array stored in <b>C order</b>, i.e. right-most dimension varying
   fastest.
        (Often referred to as "row-major" ordering.)
        Note that the storage for this pre-existing array will
        never be garbage collected by the array2d class.

        @param m the first (row) dimension of the new matrix.
        @param n the second (column) dimension of the new matrix.
        @param a the one dimensional C array to use as data storage for
                the array.
*/
template <class T> array2d<T>::array2d(int m, int n, T* a) : v_(0), m_(m), n_(n), ref_count_(0) {
  T* p = a;
  v_ = new T* [m];
  for (int i = 0; i < m; i++) {
    v_[i] = p;
    p += n;
  }
  ref_count_ = new int;
  *ref_count_ = 2; /* this avoid destorying original data. */
}

/**
        Used for A[i][j] indexing.  The first [] operator returns
        a conventional pointer which can be dereferenced using the
        same [] notation.

        If TNT_BOUNDS_CHECK macro is define, the left-most index (row index)
        is checked that it falls within the array bounds (via the
        assert() macro.) Note that bounds checking can occur in
        the row dimension, but the not column, since
        this is just a C pointer.
*/
template <class T> inline T* array2d<T>::operator[](int i) {
#ifdef SPUC_BOUNDS_CHECK
  assert(i >= 0);
  assert(i < m_);
#endif

  return v_[i];
}

template <class T> inline const T* array2d<T>::operator[](int i) const { return v_[i]; }

/**
        Assign all elemnts of A to a constant scalar.
*/
template <class T> array2d<T>& array2d<T>::operator=(const T& a) {
  set_(a);
  return *this;
}
/**
        Create a new of existing matrix.  Used in B = A.copy()
        or in the construction of B, e.g. array2d B(A.copy()),
        to create a new array that does not share data.

*/
template <class T> array2d<T> array2d<T>::copy() const {
  array2d A(m_, n_);
  copy_(A.begin_(), begin_(), m_ * n_);

  return A;
}

/**
        Copy the elements to from one array to another, in place.
        That is B.inject(A), both A and B must conform (i.e. have
        identical row and column dimensions).

        This differs from B = A.copy() in that references to B
        before this assignment are also affected.  That is, if
        we have
        <pre>
        array2d A(m,n);
        array2d C(m,n);
        array2d B(C);        // elements of B and C are shared.

</pre>
        then B.inject(A) affects both and C, while B=A.copy() creates
        a new array B which shares no data with C or A.

        @param A the array from elements will be copied
        @return an instance of the modifed array. That is, in B.inject(A),
        it returns B.  If A and B are not conformat, no modifications to
        B are made.

*/
template <class T> array2d<T>& array2d<T>::inject(const array2d& A) {
  if (A.m_ == m_ && A.n_ == n_) copy_(begin_(), A.begin_(), m_ * n_);

  return *this;
}

/**
        Create a reference (shallow assignment) to another existing array.
        In B.ref(A), B and A shared the same data and subsequent changes
        to the array elements of one will be reflected in the other.
        <p>
        This is what operator= calls, and B=A and B.ref(A) are equivalent
        operations.

        @return The new referenced array: in B.ref(A), it returns B.
*/
template <class T> array2d<T>& array2d<T>::ref(const array2d<T>& A) {
  if (this != &A) {
    (*ref_count_)--;
    if (*ref_count_ < 1) { destroy_(); }

    m_ = A.m_;
    n_ = A.n_;
    v_ = A.v_;
    ref_count_ = A.ref_count_;

    (*ref_count_)++;
  }
  return *this;
}

/**
        B = A is shorthand notation for B.ref(A).
*/
template <class T> array2d<T>& array2d<T>::operator=(const array2d<T>& A) { return ref(A); }

/**
        @return the size of the first dimension of the array, i.e.
        the number of rows.
*/
template <class T> inline int array2d<T>::dim1() const { return m_; }
template <class T> inline int array2d<T>::rows() const { return m_; }

/**
        @return the size of the second dimension of the array, i.e.
        the number of columns.
*/
template <class T> inline int array2d<T>::dim2() const { return n_; }
template <class T> inline int array2d<T>::cols() const { return n_; }

/**
        @return the number of arrays that share the same storage area
        as this one.  (Must be at least one.)
*/
template <class T> inline int array2d<T>::ref_count() const { return *ref_count_; }

template <class T> array2d<T>::~array2d() {
  (*ref_count_)--;

  if (*ref_count_ < 1) destroy_();
}

/* private internal functions */

template <class T> void array2d<T>::initialize_(int m, int n) {
  T* p = new T[m * n];
  v_ = new T* [m];
  for (int i = 0; i < m; i++) {
    v_[i] = p;
    p += n;
  }
  m_ = m;
  n_ = n;
}

template <class T> void array2d<T>::set_(const T& a) {
  T* begin = &v_[0][0];
  T* end = begin + m_ * n_;

  for (T* p = begin; p < end; p++) *p = a;
}

template <class T> void array2d<T>::copy_(T* p, const T* q, int len) const {
  T* end = p + len;
  while (p < end) *p++ = *q++;
}

template <class T> void array2d<T>::destroy_() {
  if (v_ != 0) {
    delete[](v_[0]);
    delete[](v_);
  }

  if (ref_count_ != 0) delete ref_count_;
}

/**
        @returns location of first element, i.e. A[0][0] (mutable).
*/
template <class T> const T* array2d<T>::begin_() const { return &(v_[0][0]); }

/**
        @returns location of first element, i.e. A[0][0] (mutable).
*/
template <class T> T* array2d<T>::begin_() { return &(v_[0][0]); }

/**
        Create a null (0x0) array.
*/
template <class T> array2d<T>::array2d() : v_(0), m_(0), n_(0) {
  ref_count_ = new int;
  *ref_count_ = 1;
}
}  // namespace SPUC
#endif

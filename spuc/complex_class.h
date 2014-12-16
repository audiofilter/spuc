#ifndef SPUC_COMPLEX_CLASS
#define SPUC_COMPLEX_CLASS

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
namespace SPUC {
//! \file
//! \brief Spuc template complex class.
//
//! \brief Spuc template complex class.
//
//!	Basically the same as STL complex class but allows easier customization.
//! \ingroup base
template <typename T> class complex {
 public:
  T re;
  T im;

  complex() {
    re = (T)0;
    im = (T)0;
  }

  complex(T r, T i = 0) : re(r), im(i) {}

  //  inline T real() { return(re);}
  //  inline T imag() { return(im);}
  //  template <> complex(const complex<long>& y) : re(y.re), im(y.im) {;}

  inline friend T real(complex<T> y) { return (y.re); }
  inline friend T imag(complex<T> y) { return (y.im); }
  inline friend complex<T> operator-(complex<T> r) { return (complex<T>(-r.re, -r.im)); }

  inline complex operator=(T r) {
    re = r;
    im = (T)0;
    return *this;
  }
  template <typename T1> complex<T> operator=(complex<T1>& y) {
    re = static_cast<T1>(y.re);
    im = static_cast<T1>(y.im);
    return (*this);
  }
  inline complex operator=(const complex<T>& y) {
    re = y.re;
    im = y.im;
    return *this;
  }
  inline complex operator*=(const complex<T>& y) {
    ASP_C(cmult_count)
    T r = re * y.re - im * y.im;
    im = re * y.im + im * y.re;
    re = r;
    return *this;
  }
  template <typename T1> complex<T> operator/=(complex<T1> l) { return (complex<T>(*this / l)); }
  inline complex operator+=(const complex<T>& y) {
    ASP_C(cadd_count)
    re += y.re;
    im += y.im;
    return *this;
  }
  inline complex operator-=(const complex<T>& y) {
    ASP_C(cadd_count)
    re -= y.re;
    im -= y.im;
    return *this;
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  operator const complex<long>() const { return (complex<long>((long)re, (long)im)); }
  operator const complex<double>() const { return (complex<double>((double)re, (double)im)); }
  operator const complex<float>() const { return (complex<float>((float)re, (float)im)); }
  operator const complex<int>() const { return (complex<int>((int)re, (int)im)); }
  operator const complex<builtin<long> >() const { return (complex<builtin<long> >((long)re, (long)im)); }
  operator const complex<builtin<double> >() const { return (complex<builtin<double> >((double)re, (double)im)); }
  operator const complex<builtin<int> >() const { return (complex<builtin<int> >((int)re, (int)im)); }
  operator const complex<builtin<float> >() const { return (complex<builtin<float> >((float)re, (float)im)); }
#endif
};
}  // end namespace
#endif

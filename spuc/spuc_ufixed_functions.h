//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014. Author : Tony Kirke. All right reserverd.

//////////////////////////////////////////////////////////////////////////////
#ifndef SPUC_UFIXED_20140509_CLASS_FUNCTIONS_H_
#define SPUC_UFIXED_20140509_CLASS_FUNCTIONS_H_
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

/// Dont include in namespace
template <int NINT, int NFRC, SPUC::spuc_q_mode SPUC_Q_MODE, SPUC::spuc_o_mode SPUC_O_MODE>
std::ostream &operator<<(std::ostream &os, const SPUC::spuc_ufixed<NINT, NFRC, SPUC_Q_MODE, SPUC_O_MODE> &r) {
  return os << r.to_double();  // << " ";
};
template <int NINT, int NFRC, SPUC::spuc_q_mode SPUC_Q_MODE, SPUC::spuc_o_mode SPUC_O_MODE>
std::istream &operator>>(std::istream &os, const SPUC::spuc_ufixed<NINT, NFRC, SPUC_Q_MODE, SPUC_O_MODE> &r) {
  return os >> r;
};

namespace SPUC {

// TEMPLATE functions for +,-,*,/ (divide returns double)

// addition
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval + 1,
            Template_Max<INT_BITS_, INT_BITS_1>::maxval + 1, QMODE, OMODE>
operator+(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval + 1,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval + 1, QMODE, OMODE> tmp(a);
  tmp += b;  // no saturation needed since enough head space !
  return (tmp);
}

// subtraction
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval + 1,
            Template_Max<INT_BITS_, INT_BITS_1>::maxval + 1, QMODE, OMODE>
operator-(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval + 1,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval + 1, QMODE, OMODE> tmp(a);
  tmp -= b;  // no saturation needed since enough head space !
  return (tmp);
}

// multiplication
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_ufixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE> operator*(
    const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
    const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE> tmp;
  typedef typename spuc_ufixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>::val_type
      mult_val_type;
  // Dont need to saturate here!
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)(b.getVal());
  return tmp;
}

// division
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_ufixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE> operator/(
    const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
    const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  return ((double)a / (double)b);
}

// or
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
            Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE>
operator|(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  tmpa.val |= tmpb.val;
  return (tmpa);
}
// &
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
            Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE>
operator&(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  tmpa.val &= tmpb.val;
  return (tmpa);
}
// ^
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
            Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE>
operator^(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  tmpa.val ^= tmpb.val;
  return (tmpa);
}

// <<
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> operator<<(
    const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const spuc_uint<W> &shift) {
  spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> tmp(a);
  tmp <<= shift;
  return (tmp);
}
// <<
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> operator<<(
    const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const spuc_int<W> &shift) {
  spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> tmp(a);
  tmp <<= shift;
  return (tmp);
}

// >>
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> operator>>(
    const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const spuc_uint<W> &shift) {
  spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> tmp(a);
  tmp >>= shift;
  return (tmp);
}
// >>
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> operator>>(
    const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const spuc_int<W> &shift) {
  spuc_ufixed<TOTAL_BITS_ + W, INT_BITS_ + W, QMODE, OMODE> tmp(a);
  tmp >>= shift;
  return (tmp);
}
// >> with int
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> operator>>(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                                                             const int &shift) {
  spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> tmp(a);
  tmp >>= shift;
  return (tmp);
}
// << with int
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> operator<<(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                                                             const int &shift) {
  spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> tmp(a);
  tmp <<= shift;
  return (tmp);
}

// Operations to support mixing with ints & doubles, etc

// Comparison operators "==,!=,<,<=,>,>=" between this type and 'double'

// NEW
// template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode
// OMODE_>
//	bool operator ==(const uint_type& a, const
// spuc_ufixed<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_int() ==
//(int)a);	}

// ^
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
bool operator==(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  return (tmpa.val == tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
bool operator<(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
               const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  return (tmpa.val < tmpb.val);
}
// re-use previous operators
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
bool operator!=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  return !(tmpa.val == tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
bool operator>(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
               const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  return (tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
bool operator<=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  return !(tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
bool operator>=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpa(a);
  spuc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1, INT_BITS_1>::maxval,
              Template_Max<INT_BITS_, INT_BITS_1>::maxval, QMODE, OMODE> tmpb(b);
  return !(tmpa.val < tmpb.val);
}

// --------------------- BOOLEAN Comparisions "==,<=, <. >=, > , !="
// -------------------------------------------
// Compare with doubles
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() == a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() != a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() > a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() >= a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() < a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() <= a);
}

template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const double &a) {
  return (b.to_double() == a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const double &a) {
  return (b.to_double() != a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const double &a) {
  return (b.to_double() < a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const double &a) {
  return (b.to_double() <= a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const double &a) {
  return (b.to_double() > a);
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const double &a) {
  return (b.to_double() >= a);
}

// Compare with ints
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const spuc_uint<W> &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() == double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const spuc_uint<W> &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() != double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const spuc_uint<W> &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() > double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const spuc_uint<W> &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() >= double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const spuc_uint<W> &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() < double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const spuc_uint<W> &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() <= double(a));
}

template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const spuc_uint<W> &a) {
  return (b.to_double() == double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const spuc_uint<W> &a) {
  return (b.to_double() != double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const spuc_uint<W> &a) {
  return (b.to_double() < double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const spuc_uint<W> &a) {
  return (b.to_double() <= double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const spuc_uint<W> &a) {
  return (b.to_double() > double(a));
}
template <int W, int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const spuc_uint<W> &a) {
  return (b.to_double() >= double(a));
}

// compare with uint64
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() == double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() != double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() > double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() >= double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() < double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() <= double(a));
}

template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const uint64_t &a) {
  return (b.to_double() == double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const uint64_t &a) {
  return (b.to_double() != double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const uint64_t &a) {
  return (b.to_double() < double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const uint64_t &a) {
  return (b.to_double() <= double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const uint64_t &a) {
  return (b.to_double() > double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const uint64_t &a) {
  return (b.to_double() >= double(a));
}

// compare with int64
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() == double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() != double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() > double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() >= double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() < double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b) {
  return (b.to_double() <= double(a));
}

template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator==(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const int &a) {
  return (b.to_double() == double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator!=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const int &a) {
  return (b.to_double() != double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const int &a) {
  return (b.to_double() < double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator<=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const int &a) {
  return (b.to_double() <= double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const int &a) {
  return (b.to_double() > double(a));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE_, spuc_o_mode OMODE_>
bool operator>=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE_, OMODE_> &b, const int &a) {
  return (b.to_double() >= double(a));
}

/// Math Operations
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator+(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a + (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator+(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b, const double &a) {
  return (((double)a + (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator-(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a - (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator-(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const double &b) {
  return (((double)a - (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator*(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a * (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator*(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const double &b) {
  return (((double)a * (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator/(const double &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a / (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator/(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const double &b) {
  return (((double)a / (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator+(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a + (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator+(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b, const int &a) {
  return (((double)a + (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator-(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a - (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator-(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const int &b) {
  return (((double)a - (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator*(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a * (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator*(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const int &b) {
  return (((double)a * (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator/(const int &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a / (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator/(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const int &b) {
  return (((double)a / (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator+(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a + (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator+(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b, const uint64_t &a) {
  return (((double)a + (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator-(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a - (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator-(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const uint64_t &b) {
  return (((double)a - (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator*(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a * (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator*(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const uint64_t &b) {
  return (((double)a * (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator/(const uint64_t &a, const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &b) {
  return (((double)a / (double)b));
}
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode QMODE, spuc_o_mode OMODE>
double operator/(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a, const uint64_t &b) {
  return (((double)a / (double)b));
}

}  // end of namespace SPUC

#endif

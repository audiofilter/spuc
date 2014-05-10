//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014. Author : Tony Kirke. All right reserverd.

//////////////////////////////////////////////////////////////////////////////
#ifndef SPUC_FIXED_20140509_MIXED_FUNCTIONS_H_
#define SPUC_FIXED_20140509_MIXED_FUNCTIONS_H_
namespace SPUC {

// +
template <int T1, int I1, int T2, int I2, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
           Template_Max<I1, I2>::maxval + 2, QMODE, OMODE>
operator+(const spuc_fixed<T1, I1, QMODE, OMODE> &a,
          const spuc_ufixed<T2, I2, QMODE1, OMODE1> &b) {

  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpb(b);
  tmpa.val += tmpb.getVal();
  return tmpa;
}
// +
template <int T1, int I1, int T2, int I2, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
           Template_Max<I1, I2>::maxval + 2, QMODE, OMODE>
operator+(const spuc_ufixed<T1, I1, QMODE, OMODE> &a,
          const spuc_fixed<T2, I2, QMODE1, OMODE1> &b) {

  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpb(b);
  tmpa.val += tmpb.getVal();
  return tmpa;
}
// -
template <int T1, int I1, int T2, int I2, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
           Template_Max<I1, I2>::maxval + 2, QMODE, OMODE>
operator-(const spuc_fixed<T1, I1, QMODE, OMODE> &a,
          const spuc_ufixed<T2, I2, QMODE1, OMODE1> &b) {

  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpb(b);

  tmpa.val -= tmpb.getVal();
  return tmpa;
}
// -
template <int T1, int I1, int T2, int I2, spuc_q_mode QMODE, spuc_q_mode QMODE1,
          spuc_o_mode OMODE, spuc_o_mode OMODE1>
spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
           Template_Max<I1, I2>::maxval + 2, QMODE, OMODE>
operator-(const spuc_ufixed<T1, I1, QMODE, OMODE> &a,
          const spuc_fixed<T2, I2, QMODE1, OMODE1> &b) {

  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<T1, I1, T2, I2>::maxval + 2,
             Template_Max<I1, I2>::maxval + 2, QMODE, OMODE> tmpb(b);

  tmpa.val -= tmpb.getVal();
  return tmpa;
}

// multiplication
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {

  spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE,
             OMODE> tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  // Don't need to saturate here!
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)(b.getVal());
  return tmp;
}
// multiplication
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {

  spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE,
             OMODE> tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  // Don't need to saturate here!
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)(b.getVal());
  return tmp;
}

// division
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator/(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {

  spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE,
             OMODE> tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  // Don't need to saturate here!
  tmp.val = (mult_val_type)(a.getVal()) / (mult_val_type)(b.getVal());
  return tmp;
}

template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_int<INT_BITS_1> &b) {

  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)b.to_int();
  return tmp;
}
template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_int<INT_BITS_1> &b,
          const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a) {
  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)b.to_int();
  return tmp;
}

template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_int<INT_BITS_1> &b,
          const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a) {

  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = b * a.getVal();
  return tmp;
}

template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_int<INT_BITS_1> &b) {

  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = b * a.getVal();
  return tmp;
}

///
template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_uint<INT_BITS_1> &b) {

  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)b.to_int();
  return tmp;
}
template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_uint<INT_BITS_1> &b,
          const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a) {
  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = (mult_val_type)(a.getVal()) * (mult_val_type)b.to_int();
  return tmp;
}

template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_uint<INT_BITS_1> &b,
          const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a) {

  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = b * a.getVal();
  return tmp;
}

template <int TOTAL_BITS_, int INT_BITS_, int INT_BITS_1, spuc_q_mode QMODE,
          spuc_o_mode OMODE>
spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
operator*(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
          const spuc_uint<INT_BITS_1> &b) {

  spuc_fixed<(TOTAL_BITS_ + INT_BITS_1), (INT_BITS_ + INT_BITS_1), QMODE, OMODE>
  tmp;
  typedef typename spuc_fixed<(TOTAL_BITS_ + INT_BITS_1),
                              (INT_BITS_ + INT_BITS_1), QMODE,
                              OMODE>::val_type mult_val_type;
  tmp.val = b * a.getVal();
  return tmp;
}

// ^
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool
operator==(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
           const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return (tmpa.val == tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator==(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b,
                const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return (tmpa.val == tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator<(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
               const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return (tmpa.val < tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator<(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
               const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return (tmpa.val < tmpb.val);
}
// re-use previous operators
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool
operator!=(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
           const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return !(tmpa.val == tmpb.val);
}
// re-use previous operators
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator!=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return !(tmpa.val == tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator>(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
               const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return (tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator>(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
               const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return (tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool
operator<=(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
           const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return !(tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator<=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return !(tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool
operator>=(const spuc_fixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
           const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return !(tmpa.val < tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1,
          spuc_q_mode QMODE, spuc_q_mode QMODE1, spuc_o_mode OMODE,
          spuc_o_mode OMODE1>
bool operator>=(const spuc_ufixed<TOTAL_BITS_, INT_BITS_, QMODE, OMODE> &a,
                const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, QMODE1, OMODE1> &b) {
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpa(a);
  spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                     INT_BITS_1>::maxval +
                 2,
             Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, QMODE,
             OMODE> tmpb(b);
  return !(tmpa.val < tmpb.val);
}

} // end namespace SPUC

#endif

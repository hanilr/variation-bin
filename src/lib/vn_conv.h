/* VARIATION BINARY (CONVERSION) */
#ifndef _VN_CONV_H
#define _VN_CONV_H

/* INTEGER TO BINARY CONVERSION */
struct Bin_T vn_int_to_bin(enum Bin_S Bin_Size, int input);

/* BINARY TO INTEGER CONVERSION */
int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin);

/* DOUBLE TO BINARY CONVERSION */
struct Bin_T vn_double_to_bin(enum Bin_S Bin_Size, double input);

/* BINARY TO DOUBLE CONVERSION */
double vn_bin_to_double(enum Bin_S Bin_Size, struct Bin_T Bin);

#endif /* MADE BY @hanilr */
/* VARIATION BINARY (UTILITY) */
#ifndef _VN_UTIL_H
#define _VN_UTIL_H

/* MERGE TWO BINARY TO NEW ONE */
struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond);

/* INTEGER TO BINARY CONVERSION */
struct Bin_T vn_int_to_bin(enum Bin_S Bin_Size, int input);

/* BINARY TO INTEGER CONVERSION */
int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin);

/* DOUBLE TO BINARY CONVERSION */
struct Bin_T vn_double_to_bin(enum Bin_S Bin_Size, double input);

#endif /* MADE BY @hanilr */
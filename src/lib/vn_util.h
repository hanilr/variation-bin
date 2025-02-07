/* VARIATION BINARY (UTILITY) */
#ifndef _VN_UTIL_H
#define _VN_UTIL_H

/* MERGE TWO BINARY TO NEW ONE */
struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond);

/* SEPARATE ONE BINARY TO NEW TWO */
struct Bin_T vn_split_bin(enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part);

#endif /* MADE BY @hanilr */
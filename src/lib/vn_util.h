/* VARIATION BINARY (UTILITY) */
#ifndef _VN_UTIL_H
#define _VN_UTIL_H

/* SET BIT SIGN TO HIGH OR LOW */
void vn_set_sign_bin(struct Bin_T *Bin, enum Bin_E State);

/* SET BIT DOT TO HIGH OR LOW */
void vn_set_dot_bin(struct Bin_T *Bin, enum Bin_E State);

/* MERGE TWO BINARY TO NEW ONE */
struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond);

/* SEPARATE ONE BINARY TO NEW TWO */
struct Bin_T vn_split_bin(enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part);

/* MAKE REVERSE OF THE BINARY */
struct Bin_T vn_reverse_bin(enum Bin_S Bin_Size, struct Bin_T BinInput);

/* PRINT BINARY */
void bin_print(enum Bin_S Bin_Size, struct Bin_T Bin);

#endif /* MADE BY @hanilr */
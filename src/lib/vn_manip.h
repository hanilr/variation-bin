/* VARIATION BINARY (MANIPULATION) */
#ifndef _VN_MANIP_H
#define _VN_MANIP_H

/* SET SPECIFIC BIT TO HIGH OR LOW */
void vn_bit_set(enum Bin_E *Bit, enum Bin_E State);

/* GET THE STATE OF BIT */
enum Bin_E vn_bit_get(enum Bin_E Bit);

/* TOGGLE SPECIFIC BIT TO REVERSE */
void vn_bit_toggle(enum Bin_E *Bit);

/* CLEAN BITS IN A RANGE */
void vn_bit_clean_range(enum Bin_S Bin_Size, struct Bin_T *Bin, int start_pos, int end_pos);

/* CLEAR ALL BITS IN BINARY */
void vn_bit_clear(enum Bin_S Bin_Size, struct Bin_T *Bin);

/* GET THE STATES OF BITS IN A RANGE */
struct Bin_T vn_bit_get_range(enum Bin_S Bin_Size, enum Bin_S Range_Size, struct Bin_T InputBin, int start_pos, int end_pos);

/* SHIFT THE BIT TO LEFT */
void vn_bit_shift_left(enum Bin_S Bin_Size, struct Bin_T *Bin);

/* SHIFT THE BIT TO RIGHT */
void vn_bit_shift_right(enum Bin_S Bin_Size, struct Bin_T *Bin);

#endif /* MADE BY @hanilr */
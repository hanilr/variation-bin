/* VARIATION BINARY (LOGIC) */
#ifndef _VN_LOGIC_H
#define _VN_LOGIC_H

/* AND GATE FOR BINARY */
struct Bin_T vn_and(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

/* OR GATE FOR BINARY */
struct Bin_T vn_or(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

/* NOT GATE FOR BINARY */
struct Bin_T vn_not(enum Bin_S Bin_Size, struct Bin_T FirstBin);

/* NAND GATE FOR BINARY */
struct Bin_T vn_nand(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

/* NOR GATE FOR BINARY */
struct Bin_T vn_nor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

/* XOR GATE FOR BINARY */
struct Bin_T vn_xor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

/* XNOR GATE FOR BINARY */
struct Bin_T vn_xnor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

#endif /* MADE BY @hanilr */
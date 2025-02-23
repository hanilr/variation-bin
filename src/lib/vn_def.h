/* VARIATION BINARY (DEFINATION) */
#include "vn_base.h"

#ifndef _VN_DEF_H
#define _VN_DEF_H

union Define_T { // Multi return type
    struct Bin_T Bin;   // Binary
    int Integer;        // Integer
    double Decimal;     // Double
    char *Char;         // Character
    enum Bin_E Bit;     // Bit
    struct Bin_M Math;  // Math
};

/* Variation Binizer: Binary process linker. */
union Define_T vn_binizer(char *com, ...);

/* Variation Bitizer: Bit manipulation process linker. */
union Define_T vn_bitizer(char *com, ...);

/* Variation Logicizer: Logic gate linker. */
struct Bin_T vn_logicizer(char *com, ...);

/* Variation Mathizer: Mathematical operations linker. */
union Define_T vn_mathizer(char *com, ...);

/* Variation Bin: Binary process. */
/* ------------------------------ */
/* [set_sign] Set binary sign. (struct Bin_T *Bin, enum Bin_E State) */
/* [set_dot] Set binary dot. (struct Bin_T *Bin, enum Bin_E State) */
/* [merge] Merge two binary to one. enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond) */
/* [split] Separate one binary to two. (enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part) */
/* [reverse] Reverse a binary. (enum Bin_S Bin_Size, struct Bin_T BinInput) */
/* [int_to_bin] Integer to binary conversion. (enum Bin_S Bin_Size, int input) */
/* [bin_to_int] Binary to integer conversion. (enum Bin_S Bin_Size, struct Bin_T Bin) */
/* [double_to_bin] Double to binary conversion. (enum Bin_S Bin_Size, double input) */
/* [bin_to_double] Binary to double conversion. (enum Bin_S Bin_Size, struct Bin_T Bin) */
/* [hex_to_bin] Hexadecimal to binary conversion. (enum Hex_S Hex_Size, char *input) */
/* [bin_to_hex] Binary to hexadecimal conversion. (enum Bin_S Bin_Size, struct Bin_T InputBin) */
#define vn_bin(com, ...) (vn_binizer(com, ...))

/* Variation Bit: Bit manipulation process. */
/* ---------------------------------------- */
/* [set] Set a bit. (enum Bin_E *Bit, enum Bin_E State) */
/* [get] Get a bit. (enum Bin_E Bit) */
/* [toggle] Toggle a bit. (enum Bin_E *Bit) */
/* [clear] Clear bits in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin) */
/* [clean_range] Clear bits in range in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin, int start_pos, int end_pos) */
/* [get_range] Get bits in range in a binary. (enum Bin_S Bin_Size, enum Bin_S Range_Size, struct Bin_T InputBin, int start_pos, int end_pos) */
/* [shift_left] Shift left bits in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin) */
/* [shift_right] Shift right bits in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin) */
#define vn_bit(com, ...) (vn_bitizer(com, ...))

/* Variation Logic: Logic gate. */
/* ---------------------------- */
/* [and] AND gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
/* [or] OR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
/* [not] NOT gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin) */
/* [nand] NAND gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
/* [nor] NOR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
/* [xor] XOR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
/* [xnor] XNOR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
#define vn_logic(com, ...) (vn_logicizer(com, ...))

/* Variation Math: Mathematical operations. */
/* ---------------------------------------- */
/* [half_adder] Half adder operation. (enum Bin_E A, enum Bin_E B) */
/* [full_adder] Full adder operation. (enum Bin_E A, enum Bin_E B, enum Bin_E Cin) */
/* [half_subtractor] Half subtractor operation. (enum Bin_E A, enum Bin_E B) */
/* [full_subtractor] Full subtractor operation. (enum Bin_E A, enum Bin_E B, enum Bin_E Bin) */
/* [add] Addition operation. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
/* [sub] Subtraction operation. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
#define vn_math(com, ...) (vn_mathizer(com, ...))

#endif /* MADE BY @hanilr */
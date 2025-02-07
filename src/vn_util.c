/* VARIATION BINARY (UTILITY) */

/*  STANDARD LIBRARY */
#include <stdio.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_util.h"

struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond) {
    struct Bin_T NewBin;
    enum Bin_S NewBinSize;
    int i = 0;
    
    // Dot check
    if (BinFirst.bit_dot == HIGH || BinSecond.bit_dot == HIGH) NewBin.bit_dot = HIGH;
    else NewBin.bit_dot = LOW;
    // Sign check
    if (BinFirst.bit_sign == HIGH || BinSecond.bit_sign == HIGH) NewBin.bit_sign = HIGH;
    else NewBin.bit_sign = LOW;

    // Binary type size increase process
    if (Bin_Size == 4) NewBinSize = 8;
    else if (Bin_Size == 8) NewBinSize = 16;
    else if (Bin_Size == 16) NewBinSize = 32;
    else if (Bin_Size == 32) NewBinSize = 64;
    else if (Bin_Size == 64) NewBinSize = 128;

    while (1) { // Assignment
        if (NewBinSize == 8) {
            NewBin.bit_type.Bit8_T[i] = BinFirst.bit_type.Bit4_T[i];
            NewBin.bit_type.Bit8_T[i + Bin_Size] = BinSecond.bit_type.Bit4_T[i];
        } else if (NewBinSize == 16) {
            NewBin.bit_type.Bit16_T[i] = BinFirst.bit_type.Bit8_T[i];
            NewBin.bit_type.Bit16_T[i + Bin_Size] = BinSecond.bit_type.Bit8_T[i];
        } else if (NewBinSize == 32) {
            NewBin.bit_type.Bit32_T[i] = BinFirst.bit_type.Bit16_T[i];
            NewBin.bit_type.Bit32_T[i + Bin_Size] = BinSecond.bit_type.Bit16_T[i];
        } else if (NewBinSize == 64) {
            NewBin.bit_type.Bit64_T[i] = BinFirst.bit_type.Bit32_T[i];
            NewBin.bit_type.Bit64_T[i + Bin_Size] = BinSecond.bit_type.Bit32_T[i];
        } else if (NewBinSize == 128) {
            NewBin.bit_type.Bit128_T[i] = BinFirst.bit_type.Bit64_T[i];
            NewBin.bit_type.Bit128_T[i + Bin_Size] = BinSecond.bit_type.Bit64_T[i];
        }

        i += 1;
        if (i == Bin_Size) break;
    }

    return NewBin;
} // Max supported bit 64 for merge

struct Bin_T vn_split_bin(enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part) {
    struct Bin_T BinFirst;
    struct Bin_T BinSecond;
    enum Bin_S NewBinSize;
    int i = 0;

    // Binary type size decrease process
    if (Bin_Size == 8) NewBinSize = 4;
    else if (Bin_Size == 16) NewBinSize = 8;
    else if (Bin_Size == 32) NewBinSize = 16;
    else if (Bin_Size == 64) NewBinSize = 32;
    else if (Bin_Size == 128) NewBinSize = 64;

    while (1) {
        if (NewBinSize == 4) {
            BinFirst.bit_type.Bit4_T[i] = BinInput.bit_type.Bit8_T[i];
            BinSecond.bit_type.Bit4_T[i] = BinInput.bit_type.Bit8_T[NewBinSize + i];
        } else if (NewBinSize == 8) {
            BinFirst.bit_type.Bit8_T[i] = BinInput.bit_type.Bit16_T[i];
            BinSecond.bit_type.Bit8_T[i] = BinInput.bit_type.Bit16_T[NewBinSize + i];
        } else if (NewBinSize == 16) {
            BinFirst.bit_type.Bit16_T[i] = BinInput.bit_type.Bit32_T[i];
            BinSecond.bit_type.Bit16_T[i] = BinInput.bit_type.Bit32_T[NewBinSize + i];
        } else if (NewBinSize == 32) {
            BinFirst.bit_type.Bit32_T[i] = BinInput.bit_type.Bit64_T[i];
            BinSecond.bit_type.Bit32_T[i] = BinInput.bit_type.Bit64_T[NewBinSize + i];
        } else if (NewBinSize == 64) {
            BinFirst.bit_type.Bit64_T[i] = BinInput.bit_type.Bit128_T[i];
            BinSecond.bit_type.Bit64_T[i] = BinInput.bit_type.Bit128_T[NewBinSize + i];
        }

        i += 1;
        if (i == NewBinSize) break;
    }

    // Bit sign and bit dot assignment
    BinFirst.bit_sign = BinInput.bit_sign;
    BinSecond.bit_sign = BinInput.bit_sign;
    BinFirst.bit_dot = BinInput.bit_dot;
    BinSecond.bit_dot = BinInput.bit_dot;

    if (which_part == 'f') return BinFirst;
    else if (which_part == 's') return BinSecond;
} // Min supported bit 8 for split

/* MADE BY @hanilr */
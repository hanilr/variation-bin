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

struct Bin_T vn_int_to_bin(enum Bin_S Bin_Size, int input) {
    struct Bin_T Bin;
    int cInt[128] = {0}, i = 0, n = Bin_Size-1;

    if (input < 0) Bin.bit_sign = HIGH; // Sign bit process
    else Bin.bit_sign = LOW;

    while (1) { // Conversion
        if (input % 2 != 0) cInt[i] = 1;
        input /= 2;
        i += 1;
        if (i == 128) break;
    }

    i = 0;
    while (1) { // Assignment
        if (Bin_Size == 4) Bin.bit_type.Bit4_T[i] = cInt[n];
        else if (Bin_Size == 8) Bin.bit_type.Bit8_T[i] = cInt[n];
        else if (Bin_Size == 16) Bin.bit_type.Bit16_T[i] = cInt[n];
        else if (Bin_Size == 32) Bin.bit_type.Bit32_T[i] = cInt[n];
        else if (Bin_Size == 64) Bin.bit_type.Bit64_T[i] = cInt[n];
        else if (Bin_Size == 128) Bin.bit_type.Bit128_T[i] = cInt[n];

        i += 1;
        n -= 1;
        if (i == Bin_Size || n < 0) break;
    }

    return Bin;
}

int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int result = 0, cInt[128] = {0}, i = 0, n = Bin_Size-1;

    while (1) { // Assignment
        if (Bin_Size == 4) cInt[n] = Bin.bit_type.Bit4_T[i];
        else if (Bin_Size == 8) cInt[n] = Bin.bit_type.Bit8_T[i];
        else if (Bin_Size == 16) cInt[n] = Bin.bit_type.Bit16_T[i];
        else if (Bin_Size == 32) cInt[n] = Bin.bit_type.Bit32_T[i];
        else if (Bin_Size == 64) cInt[n] = Bin.bit_type.Bit64_T[i];
        else if (Bin_Size == 128) cInt[n] = Bin.bit_type.Bit128_T[i];

        i += 1;
        n -= 1;
        if (i == Bin_Size || n < 0) break;
    }

    i = 0;
    n = 1;
    while (1) { // Solution
        result += cInt[i] * n;
        i += 1;
        n *= 2;
        if (i == Bin_Size) break;
    }

    if (Bin.bit_sign == HIGH) result *= -1;
    return result;
}

/* MADE BY @hanilr */
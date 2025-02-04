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

struct Bin_T vn_double_to_bin(enum Bin_S Bin_Size, double input) {
    struct Bin_T Bin;
    enum Bin_S NewBinSize;

    if (input < 0) { // Sign bit process
        Bin.bit_sign = HIGH;
    }
    else Bin.bit_sign = LOW;

    int part_int = (int)input; // Integer part
    double dec = input - part_int;
    int part_dec = (int)(dec * 1000000);
    
    int i = 0;
    while (1) {
        if (part_dec % 10 == 0) part_dec /= 10;
        else break;

        i += 1;
        if (i == 6) break;
    } 

    struct Bin_T BinInteger = vn_int_to_bin(Bin_Size, part_int);
    struct Bin_T BinDecimal = vn_int_to_bin(Bin_Size, part_dec);

    Bin = vn_merge_bin(Bin_Size, BinInteger, BinDecimal);
    Bin.bit_dot = HIGH; // Set the bit is double

    return Bin;
} // Double type limited to max 64 bit because of merge function

/* MADE BY @hanilr */
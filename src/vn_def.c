/* VARIATION BINARY (DEFINATION) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <math.h>

/* DIY LIBRARY */
#include "lib/vn_def.h"

struct Bin_T vn_int_to_bin(enum Bin_S Bin_Size, int input) {
    struct Bin_T Bin;
    int cInt[64] = {0}, i = 0, n = Bin_Size-1;

    if (input < 0) Bin.bit_sign = HIGH; // Sign bit process
    else Bin.bit_sign = LOW;

    while (1) { // Conversion
        if (input % 2 != 0) cInt[i] = 1;
        input /= 2;
        i += 1;
        if (i == 64) break;
    }

    i = 0;
    while (1) { // Assignment
        if (Bin_Size == 8) Bin.bit_type.Bit8_T[i] = cInt[n];
        else if (Bin_Size == 16) Bin.bit_type.Bit16_T[i] = cInt[n];
        else if (Bin_Size == 32) Bin.bit_type.Bit32_T[i] = cInt[n];
        else if (Bin_Size == 64) Bin.bit_type.Bit64_T[i] = cInt[n];

        i += 1;
        n -= 1;
        if (i == Bin_Size || n < 0) break;
    }

    return Bin;
}

int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int result = 0, cInt[64] = {0}, i = 0, n = Bin_Size-1;

    while (1) { // Assignment
        if (Bin_Size == 8) cInt[n] = Bin.bit_type.Bit8_T[i];
        else if (Bin_Size == 16) cInt[n] = Bin.bit_type.Bit16_T[i];
        else if (Bin_Size == 32) cInt[n] = Bin.bit_type.Bit32_T[i];
        else if (Bin_Size == 64) cInt[n] = Bin.bit_type.Bit64_T[i];

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
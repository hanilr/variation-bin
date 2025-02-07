/* VARIATION BINARY (CONVERSION) */

/*  STANDARD LIBRARY */
#include <stdio.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_util.h"

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

    if (input < 0) { // Sign bit process
        Bin.bit_sign = HIGH;
    }
    else Bin.bit_sign = LOW;

    return Bin;
} // Double type limited to max 64 bit because of merge function

double vn_bin_to_double(enum Bin_S Bin_Size, struct Bin_T Bin) {
    enum Bin_E B_Sign = Bin.bit_sign;
    Bin.bit_sign = LOW;

    struct Bin_T BinInt = vn_split_bin(Bin_Size, Bin, 'f');
    struct Bin_T BinDec = vn_split_bin(Bin_Size, Bin, 's');

    int part_int = vn_bin_to_int(Bin_Size/2, BinInt);
    int part_dec = vn_bin_to_int(Bin_Size/2, BinDec);
    if (part_dec == 0) return part_int;
    double dec = (double)part_dec, result;

    int i = 0;
    while (part_dec > 0) {
        part_dec /= 10;
        i += 1;
    } // Find digit

    while (i > 0) {
        dec /= 10;
        i -= 1;
    } // Find decimal part
    result = part_int + dec;

    if (B_Sign == HIGH) result *= -1;
    return result;
}

/* MADE BY @hanilr */
/* VARIATION BINARY (CONVERSION) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_util.h"
#include "lib/vn_conv.h"

struct Bin_T vn_int_to_bin(enum Bin_S Bin_Size, int input) {
    int cInt[128] = {0}, i = 0, n = Bin_Size-1;
    struct Bin_T Bin;

    while (1) { // Conversion
        if (input % 2 != 0) cInt[i] = 1;
        input /= 2;
        i += 1;
        if (i == 128) break;
    } i = 0;

    while (i != Bin_Size || n >= 0) { // Assignment
        if (Bin_Size == 4) Bin.bit_type.Bit4_T[i] = cInt[n];
        else if (Bin_Size == 8) Bin.bit_type.Bit8_T[i] = cInt[n];
        else if (Bin_Size == 16) Bin.bit_type.Bit16_T[i] = cInt[n];
        else if (Bin_Size == 32) Bin.bit_type.Bit32_T[i] = cInt[n];
        else if (Bin_Size == 64) Bin.bit_type.Bit64_T[i] = cInt[n];
        else if (Bin_Size == 128) Bin.bit_type.Bit128_T[i] = cInt[n];
        i += 1;
        n -= 1;
    }
    // Sign bit process
    if (input < 0) Bin.bit_sign = HIGH; 
    else Bin.bit_sign = LOW;
    Bin.bit_dot = LOW; // Set 'LOW' as default

    return Bin;
}

int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int result = 0, cInt[128] = {0}, i = 0, n = Bin_Size-1;

    while (i != Bin_Size || n >= 0) { // Assignment
        if (Bin_Size == 4) cInt[n] = Bin.bit_type.Bit4_T[i];
        else if (Bin_Size == 8) cInt[n] = Bin.bit_type.Bit8_T[i];
        else if (Bin_Size == 16) cInt[n] = Bin.bit_type.Bit16_T[i];
        else if (Bin_Size == 32) cInt[n] = Bin.bit_type.Bit32_T[i];
        else if (Bin_Size == 64) cInt[n] = Bin.bit_type.Bit64_T[i];
        else if (Bin_Size == 128) cInt[n] = Bin.bit_type.Bit128_T[i];
        i += 1;
        n -= 1;
    }

    i = 0;
    n = 1;
    while (i != Bin_Size) { // Solution
        result += cInt[i] * n;
        i += 1;
        n *= 2;
    }

    if (Bin.bit_sign == HIGH) result *= -1;
    return result;
}

struct Bin_T vn_double_to_bin(enum Bin_S Bin_Size, double input) {
    struct Bin_T Bin[2];
    struct Bin_T Result;

    int part_int = (int)input; // Integer part
    double dec = input - part_int;
    int part_dec = (int)(dec * 1000000);

    int i = 0;
    while (i != 6) {
        if (part_dec % 10 == 0) part_dec /= 10;
        else break;
        i += 1;
    } 

    Bin[0] = vn_int_to_bin(Bin_Size, part_int);
    Bin[1] = vn_int_to_bin(Bin_Size, part_dec);

    Result = vn_merge_bin(Bin_Size, Bin[0], Bin[1]);
    Result.bit_dot = HIGH; // Set the bit is double
    // Sign bit process
    if (input < 0) Result.bit_sign = HIGH;
    else Result.bit_sign = LOW;

    return Result;
} // Double type limited to max 64 bit because of merge function

double vn_bin_to_double(enum Bin_S Bin_Size, struct Bin_T Bin) {
    enum Bin_E B_Sign = Bin.bit_sign;
    Bin.bit_sign = LOW;

    // Seperation
    struct Bin_T BinInt = vn_split_bin(Bin_Size, Bin, 'f');
    struct Bin_T BinDec = vn_split_bin(Bin_Size, Bin, 's');
    // Specification
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

struct Bin_T vn_hex_to_bin(enum Hex_S Hex_Size, char *input) {
    int input_len = strlen(input);
    enum Bin_S Bin_Size;
    struct Bin_T Bin[input_len];
    struct Bin_T Result;
    int i = 0, cInt[input_len];

    if (Hex_Size == 2) Bin_Size = 8;
    else if (Hex_Size == 4) Bin_Size = 16;
    else if (Hex_Size == 8) Bin_Size = 32;
    else if (Hex_Size == 16) Bin_Size = 64;

    while (i != input_len) { // Data conversion
        if (input[i] >= '0' && input[i] <= '9') cInt[i] = input[i] - '0';
        else if (input[i] >= 'a' && input[i] <= 'f') cInt[i] = 10 + (input[i] - 'a');
        i += 1;
    } i = 0;

    while (i != input_len) { // Type conversion
        Bin[i] = vn_int_to_bin(4, cInt[i]);
        i += 1;
    }

    if (Bin_Size == 8) {
        Result = vn_merge_bin(4, Bin[0], Bin[1]);
    } else if (Bin_Size == 16) {
        Result = vn_merge_bin(8, vn_merge_bin(4, Bin[0], Bin[1]), vn_merge_bin(4, Bin[2], Bin[3]));
    } else if (Bin_Size == 32) {
        Bin[0] = vn_merge_bin(8, vn_merge_bin(4, Bin[0], Bin[1]), vn_merge_bin(4, Bin[2], Bin[3]));
        Bin[1] = vn_merge_bin(8, vn_merge_bin(4, Bin[4], Bin[5]), vn_merge_bin(4, Bin[6], Bin[7]));
        Result = vn_merge_bin(16, Bin[0], Bin[1]);
    } else if (Bin_Size == 64) {
        Bin[0] = vn_merge_bin(8, vn_merge_bin(4, Bin[0], Bin[1]), vn_merge_bin(4, Bin[2], Bin[3]));
        Bin[1] = vn_merge_bin(8, vn_merge_bin(4, Bin[4], Bin[5]), vn_merge_bin(4, Bin[6], Bin[7]));
        Result = vn_merge_bin(16, Bin[0], Bin[1]);

        Bin[0] = vn_merge_bin(8, vn_merge_bin(4, Bin[8], Bin[9]), vn_merge_bin(4, Bin[10], Bin[11]));
        Bin[1] = vn_merge_bin(8, vn_merge_bin(4, Bin[12], Bin[13]), vn_merge_bin(4, Bin[14], Bin[15]));
        Bin[2] = vn_merge_bin(16, Bin[0], Bin[1]);
        Result = vn_merge_bin(32, Result, Bin[2]);
    } 
    
    Result.bit_dot = HIGH;
    return Result;
}

char* vn_bin_to_hex(enum Bin_S Bin_Size, struct Bin_T InputBin) {
    int Hex_Size;

    if (Bin_Size == 8) Hex_Size = 2;
    else if (Bin_Size == 16) Hex_Size = 4;
    else if (Bin_Size == 32) Hex_Size = 8;
    else if (Bin_Size == 64) Hex_Size = 16;
    
    struct Bin_T Bin[Hex_Size];
    char *result = (char*)malloc((Hex_Size) * sizeof(char));

    char check[16][4] = {
        {'f', 'f', 'f', 'f'}, {'f', 'f', 'f', 's'}, {'f', 'f', 's', 'f'}, {'f', 'f', 's', 's'},
        {'f', 's', 'f', 'f'}, {'f', 's', 'f', 's'}, {'f', 's', 's', 'f'}, {'f', 's', 's', 's'},
        {'s', 'f', 'f', 'f'}, {'s', 'f', 'f', 's'}, {'s', 'f', 's', 'f'}, {'s', 'f', 's', 's'}, 
        {'s', 's', 'f', 'f'}, {'s', 's', 'f', 's'}, {'s', 's', 's', 'f'}, {'s', 's', 's', 's'}
    };

    int i = 0, n = 0, temp_size = 8, cInt[Hex_Size]; 
    while (i != Hex_Size) { // Seperation
        if (Hex_Size == 2) {
            Bin[i] = vn_split_bin(8, InputBin, check[i][3]);
        } else if (Hex_Size == 4) {
            Bin[i] = vn_split_bin(8, vn_split_bin(16, InputBin, check[i][2]), check[i][3]);
        } else if (Hex_Size == 8) {
            Bin[i] = vn_split_bin(8, vn_split_bin(16, vn_split_bin(32, InputBin, check[i][1]), check[i][2]), check[i][3]);
        } else if (Hex_Size == 16) {
            Bin[i] = vn_split_bin(8, vn_split_bin(16, vn_split_bin(32, vn_split_bin(64, InputBin, check[i][0]), check[i][1]), check[i][2]), check[i][3]);
        } 
        i += 1;
    } i = 0;
    
    while (i != Hex_Size) { // Type conversion
        cInt[i] = vn_bin_to_int(4, Bin[i]);
        i += 1;
    } i = 0;

    while (i != Hex_Size) { // Data conversion
        if (cInt[i] >= 0 && cInt[i] <= 9) result[i] = cInt[i] + '0';
        else if (cInt[i] >= 10 && cInt[i] <= 15) result[i] = (cInt[i] - 10 ) + 'a';
        i += 1;
    }

    result[Hex_Size] = '\0';
    return result;
}

/* MADE BY @hanilr */
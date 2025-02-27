/* STANDARD LIBRARY */
#include <stdio.h> /* Standard Input/Output Library */

/* VARIATION BINARY LIBRARY */
#define VN_BIN_IMPLEMENTATION /* Unlock the library */
#include "../vn_bin.h" /* Location the library */

/* MACROS */
#define com_set_sign        "set_sign"
#define com_set_dot         "set_dot"
#define com_merge           "merge"
#define com_split           "split"
#define com_reverse         "reverse"
#define com_int_to_bin      "int_to_bin"
#define com_bin_to_int      "bin_to_int"
#define com_double_to_bin   "double_to_bin"
#define com_bin_to_double   "bin_to_double"
#define com_hex_to_bin      "hex_to_bin"
#define com_bin_to_hex      "bin_to_hex"

#define com_set_bit         "set"
#define com_get_bit         "get"
#define com_toggle_bit      "toggle"
#define com_clear_bit       "clear"
#define com_clean_range     "clean_range"
#define com_get_range       "get_range"
#define com_shift_left      "shift_left"
#define com_shift_right     "shift_right"

#define com_and             "and"
#define com_or              "or"
#define com_not             "not"
#define com_nand            "nand"
#define com_nor             "nor"
#define com_xor             "xor"
#define com_xnor            "xnor"

#define com_half_add        "half_adder"
#define com_full_add        "full_adder"
#define com_half_sub        "half_subtractor"
#define com_full_sub        "full_subtractor"
#define com_add             "add"
#define com_sub             "sub"

/* BINARY PRINT */
void bin_print(enum Bin_S Bin_Size, struct Bin_T Bin, char *expectation) {
    printf("\nBit Size: %d, Bit Sign: %d, Bit Dot: %d\n > |", Bin_Size, Bin.bit_sign, Bin.bit_dot);
    
    int i = 0;
    while ((i != Bin_Size)) { 
        if (Bin_Size == 4) printf("%d|", Bin.bit_type.Bit4_T[i]);
        else if (Bin_Size == 8) printf("%d|", Bin.bit_type.Bit8_T[i]);
        else if (Bin_Size == 16) printf("%d|", Bin.bit_type.Bit16_T[i]);
        else if (Bin_Size == 32) printf("%d|", Bin.bit_type.Bit32_T[i]);
        else if (Bin_Size == 64) printf("%d|", Bin.bit_type.Bit64_T[i]);
        else if (Bin_Size == 128) printf("%d|", Bin.bit_type.Bit128_T[i]);
        i += 1;
    }
    printf("\nExpect: %s\n", expectation);
}

int main(void) { /* Demo main */
    /* BINARY SIZE TYPES */
    enum Bin_S S_4 = 4;
    enum Bin_S S_8 = 8;
    enum Bin_S S_16 = 16;
    enum Bin_S S_32 = 32;
    enum Bin_S S_64 = 64;
    enum Bin_S S_128 = 128;

    /* HEXADECIMAL SIZE TYPES */
    enum Hex_S H_2 = 2;
    enum Hex_S H_4 = 4;
    enum Hex_S H_8 = 8;
    enum Hex_S H_16 = 16;

    struct Bin_T Bin0 = {0}; /* Initialize and fill with 0 */
    struct Bin_T Bin1 = {1}; /* Initialize with 1 */
    union Define_T Def[2] = {0}; /* To get returns from functions */

    printf("\n[======= Binary Functions =======]");
    printf("\n= Initialition =\n");

    bin_print(S_4, Bin0, "Initial Binary '0'"); /* Every bits are '0' */
    bin_print(S_4, Bin1, "Initial Binary '1'"); /* Every bits are '0' */
    
    printf("\n================");
    printf("\n= Sign and Dot =\n");

    vn_bin(com_set_sign, &Bin0, HIGH); /* Sign bit HIGH */
    bin_print(S_4, Bin0, "Sign bit should turn '0' to '1'.");
    vn_bin(com_set_sign, &Bin0, LOW); /* Sign bit LOW */
    bin_print(S_4, Bin0, "Sign bit should turn '1' to '0'.");

    vn_bin(com_set_dot, &Bin0, HIGH); /* Dot bit HIGH */
    bin_print(S_4, Bin0, "Dot bit should turn '0' to '1'.");
    vn_bin(com_set_dot, &Bin0, LOW); /* Dot bit LOW */
    bin_print(S_4, Bin0, "Dot bit should turn '1' to '0'.");

    printf("\n================");
    printf("\n=== Utilities ==\n");
    
    Def[0] = vn_bin(com_merge, S_4, Bin0, Bin1);
    bin_print(S_8, Def[0].Bin, "Should merge bins to double bin size. [0|0|0|0|1|0|0|0]");

    Def[1] = vn_bin(com_split, S_8, Def[0].Bin, 'f');
    bin_print(S_4, Def[1].Bin, "Should separate bins to half bin size. First half. [0|0|0|0]");

    Def[1] = vn_bin(com_split, S_8, Def[0].Bin, 's');
    bin_print(S_4, Def[1].Bin, "Should separate bins to half bin size. Second half. [1|0|0|0]");

    Def[1] = vn_bin(com_reverse, S_8, Def[0].Bin);
    bin_print(S_8, Def[1].Bin, "Binary should be reverse. [0|0|0|1|0|0|0|0]");

    printf("\n================");
    printf("\n== Conversion ==\n");

    Def[0] = vn_bin(com_int_to_bin, S_16, 31);
    bin_print(S_16, Def[0].Bin, "Integer should be converted to binary. [0|0|0|0|0|0|0|0|0|0|0|1|1|1|1|1]");

    Def[1] = vn_bin(com_bin_to_int, S_16, Def[0].Bin);
    printf("\n|%d|\nExpect: %s\n", Def[1].Integer, "Binary should be converted to integer. [31]");

    Def[0] = vn_bin(com_double_to_bin, S_4, 3.1);
    bin_print(S_8, Def[0].Bin, "Double should be converted to binary, also should dot bit turn to '1'. [0|0|1|1|1|1|1|0]");

    Def[1] = vn_bin(com_bin_to_double, S_8, Def[0].Bin);
    printf("\n|%lf|\nExpect: %s\n", Def[1].Decimal, "Binary should be converted to double. [3.1]");

    Def[0] = vn_bin(com_hex_to_bin, H_2, "a5");
    bin_print(S_8, Def[0].Bin, "Hexadecimal should be converted to binary. [1|0|1|0|0|1|0|1]");

    Def[1] = vn_bin(com_bin_to_hex, S_8, Def[0].Bin);
    printf("\n|%s|\nExpect: %s\n", Def[1].Char, "Binary should be converted to hexadecimal. [a5]");

    printf("\n================");
    printf("\n[================================]");
    printf("\n[========= Bit Functions ========]\n");
    printf("\n== Bit by Bit ==");

    vn_bit(com_set_bit, &Bin0.bit_type.Bit4_T[2], HIGH);
    bin_print(S_4, Bin0, "Third bit in the binary should be '1'. [0|0|1|0]");

    Def[0] = vn_bit(com_get_bit, Bin0.bit_type.Bit4_T[2]);
    printf("\nBit: %d\nExpect: %s\n", Def[0].Bit, "Bit should be '1'");

    vn_bit(com_set_bit, &Bin0.bit_type.Bit4_T[2], LOW);
    bin_print(S_4, Bin0, "Third bit in the binary should be '0'. [0|0|0|0]");

    Def[0] = vn_bit(com_get_bit, Bin0.bit_type.Bit4_T[2]);
    printf("\nBit: %d\nExpect: %s\n", Def[0].Bit, "Bit should be '0'");

    vn_bit(com_toggle_bit, &Bin0.bit_type.Bit4_T[1]);
    bin_print(S_4, Bin0, "Second bit in the binary should be '1'. [0|1|0|0]");
    
    vn_bit(com_toggle_bit, &Bin0.bit_type.Bit4_T[2]);
    bin_print(S_4, Bin0, "Second bit in the binary should be '1'. [0|1|1|0]");

    vn_bit(com_clear_bit, S_4, &Bin0);
    bin_print(S_4, Bin0, "All bits should be '0'. [0|0|0|0]");

    printf("\n================");
    printf("\n=== Bit Range ==");

    vn_bit(com_set_bit, &Bin0.bit_type.Bit4_T[0], HIGH);
    vn_bit(com_set_bit, &Bin0.bit_type.Bit4_T[1], HIGH);
    vn_bit(com_set_bit, &Bin0.bit_type.Bit4_T[2], HIGH);
    vn_bit(com_set_bit, &Bin0.bit_type.Bit4_T[3], HIGH);
    vn_bit(com_clean_range, S_4, &Bin0, 0, 1);
    bin_print(S_4, Bin0, "First and second bits should be '0'. [0|0|1|1]");

    Def[0] = vn_bit(com_get_range, S_4, S_4, Bin0, 1, 2);
    bin_print(S_4, Def[0].Bin, "First should be '0' and second should be '1'. [0|1|0|0]");

    printf("\n================");
    printf("\n== Bit Shifts ==");

    vn_bit(com_shift_left, S_4, &Def[0].Bin);
    bin_print(S_4, Def[0].Bin, "Second bit should be shifted to first bit. [1|0|0|0]");

    vn_bit(com_shift_right, S_4, &Def[0].Bin);
    bin_print(S_4, Def[0].Bin, "First bit should be shifted to second bit. [0|1|0|0]");

    printf("\n================");
    printf("\n[================================]");
    printf("\n[======= Logical Functions ======]\n");

    struct Bin_T A = {0};
    struct Bin_T B = {0};
    struct Bin_T Result;

    int i = 0;
    while (i != 16) {
        B.bit_type.Bit16_T[i] = HIGH;
        i += 1;
    }
    
    Result = vn_logic(com_and, S_16, A, B);
    bin_print(S_16, Result, "All bits should 0. [0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0]");

    Result = vn_logic(com_or, S_16, A, B);
    bin_print(S_16, Result, "All bits should 1. [1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1]");

    Result = vn_logic(com_not, S_16, A, B);
    bin_print(S_16, Result, "All bits should 1. [1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1]");

    Result = vn_logic(com_nand, S_16, A, B);
    bin_print(S_16, Result, "All bits should 1. [1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1]");

    Result = vn_logic(com_nor, S_16, A, B);
    bin_print(S_16, Result, "All bits should 0. [0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0]");

    Result = vn_logic(com_xor, S_16, A, B);
    bin_print(S_16, Result, "All bits should 1. [1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1]");

    Result = vn_logic(com_xnor, S_16, A, B);
    bin_print(S_16, Result, "All bits should 0. [0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0]");

    printf("\n[================================]\n");
    printf("\n[==== Mathematical Funcitons ====]\n");

    struct Bin_T X = {0};
    struct Bin_T Y = {0};

    enum Bin_E Bit1 = LOW;
    enum Bin_E Bit2 = HIGH;
    
    struct Bin_M Math;

    i = 0;
    while (i != 16) {
        if (i < 8) Y.bit_type.Bit16_T[i] = HIGH;
        else X.bit_type.Bit16_T[i] = HIGH;
        i += 1;
    }

    bin_print(S_16, X, "Initialize math first.");
    bin_print(S_16, Y, "Initialize math second.");
    
    Def[0] = vn_math(com_half_add, Bit1, Bit2);
    printf("\nSum: %d, Carry: %d\nExpect: 1, 0\n", Def[0].Math.math_type_first.Sum, Def[0].Math.math_type_second.Carry);

    Def[1] = vn_math(com_full_add, Def[0].Math.math_type_first.Sum, Bit2, Def[0].Math.math_type_second.Carry);
    printf("\nSum: %d, Carry: %d\nExpect: 0, 1\n", Def[1].Math.math_type_first.Sum, Def[1].Math.math_type_second.Carry);

    Def[0] = vn_math(com_half_sub, Bit1, Bit2);
    printf("\nSum: %d, Carry: %d\nExpect: 1, 1\n", Def[0].Math.math_type_first.Dif, Def[0].Math.math_type_second.Borrow);

    Def[1] = vn_math(com_full_sub, Def[0].Math.math_type_first.Dif, Bit2, Def[0].Math.math_type_second.Borrow);
    printf("\nSum: %d, Carry: %d\nExpect: 1, 1\n", Def[1].Math.math_type_first.Dif, Def[1].Math.math_type_second.Borrow);

    Def[1] = vn_math(com_add, S_16, X, Y);
    bin_print(S_16, Def[1].Bin, "|0|1|1|1|1|1|1|0|1|1|1|1|1|1|1|1|");

    Def[0] = vn_math(com_sub, S_16, Y, X);
    bin_print(S_16, Def[0].Bin, "|0|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|");

    printf("\n[================================]\n");

    return 0; /* Exit with successfully */
}

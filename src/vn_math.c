/* VARIATION BINARY (MATHEMATIC) */

/*  STANDARD LIBRARY */
#include <stdio.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_util.h"
#include "lib/vn_conv.h"
#include "lib/vn_manip.h"
#include "lib/vn_logic.h"
#include "lib/vn_math.h"

struct Bin_M vn_half_adder(enum Bin_E A, enum Bin_E B) {
    struct Bin_M Result;

    Result.math_type_first.Sum = A ^ B;
    Result.math_type_second.Carry = A & B;

    return Result;
}

struct Bin_M vn_full_adder(enum Bin_E A, enum Bin_E B, enum Bin_E Cin) {
    struct Bin_M Result;
    struct Bin_M Sum;
    struct Bin_M Carry;

    Carry = vn_half_adder(A, B);
    Sum = vn_half_adder(Carry.math_type_first.Sum, Cin);

    Result.math_type_first.Sum = Sum.math_type_first.Sum;
    Result.math_type_second.Carry = Carry.math_type_second.Carry | Sum.math_type_second.Carry;

    return Result;
}

struct Bin_M vn_half_subtractor(enum Bin_E A, enum Bin_E B) {
    struct Bin_M Result;
    int temp_not;

    if (A == HIGH) temp_not = 0;
    else temp_not = 1;

    Result.math_type_first.Dif = A ^ B;
    Result.math_type_second.Borrow = temp_not & B;

    return Result;
}

struct Bin_M vn_full_subtractor(enum Bin_E A, enum Bin_E B, enum Bin_E Bin) {
    struct Bin_M Result;
    struct Bin_M Dif;
    struct Bin_M Borrow;

    Borrow = vn_half_subtractor(A, B);
    Dif = vn_half_subtractor(Borrow.math_type_first.Dif, Bin);

    Result.math_type_first.Dif = Dif.math_type_first.Dif;
    Result.math_type_second.Borrow = Dif.math_type_second.Borrow | Borrow.math_type_second.Borrow;

    return Result;
}

struct Bin_T vn_math(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin, char math_op) {
    struct Bin_T Result = {0};
    struct Bin_M OP = {0};

    int i = Bin_Size - 1;
    while (1) { // Assignment
        if (Bin_Size == 4){
            if (math_op == '+') {
                OP = vn_full_adder(FirstBin.bit_type.Bit4_T[i], SecondBin.bit_type.Bit4_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit4_T[i] = LOW;
                else Result.bit_type.Bit4_T[i] = HIGH;
            }
            else if (math_op == '-') {
                OP = vn_full_subtractor(FirstBin.bit_type.Bit4_T[i], SecondBin.bit_type.Bit4_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit4_T[i] = LOW;
                else Result.bit_type.Bit4_T[i] = HIGH;
            }
        } else if (Bin_Size == 8) {
            if (math_op == '+') {
                OP = vn_full_adder(FirstBin.bit_type.Bit8_T[i], SecondBin.bit_type.Bit8_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit8_T[i] = LOW;
                else Result.bit_type.Bit8_T[i] = HIGH;
            }   
            else if (math_op == '-') {
                OP = vn_full_subtractor(FirstBin.bit_type.Bit8_T[i], SecondBin.bit_type.Bit8_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit8_T[i] = LOW;
                else Result.bit_type.Bit8_T[i] = HIGH;
            }
        } else if (Bin_Size == 16) {
            if (math_op == '+') {
                OP = vn_full_adder(FirstBin.bit_type.Bit16_T[i], SecondBin.bit_type.Bit16_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit16_T[i] = LOW;
                else Result.bit_type.Bit16_T[i] = HIGH;
            }
            else if (math_op == '-') {
                OP = vn_full_subtractor(FirstBin.bit_type.Bit16_T[i], SecondBin.bit_type.Bit16_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit16_T[i] = LOW;
                else Result.bit_type.Bit16_T[i] = HIGH;
            }
        } else if (Bin_Size == 32) {
            if (math_op == '+') {
                OP = vn_full_adder(FirstBin.bit_type.Bit32_T[i], SecondBin.bit_type.Bit32_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit32_T[i] = LOW;
                else Result.bit_type.Bit32_T[i] = HIGH;
            }
            else if (math_op == '-') {
                OP = vn_full_subtractor(FirstBin.bit_type.Bit32_T[i], SecondBin.bit_type.Bit32_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit32_T[i] = LOW;
                else Result.bit_type.Bit32_T[i] = HIGH;
            }
        } else if (Bin_Size == 64) {
            if (math_op == '+') {
                OP = vn_full_adder(FirstBin.bit_type.Bit64_T[i], SecondBin.bit_type.Bit64_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit64_T[i] = LOW;
                else Result.bit_type.Bit64_T[i] = HIGH;
            }
            else if (math_op == '-') {
                OP = vn_full_subtractor(FirstBin.bit_type.Bit64_T[i], SecondBin.bit_type.Bit64_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit64_T[i] = LOW;
                else Result.bit_type.Bit64_T[i] = HIGH;
            }
        } else if (Bin_Size == 128) {
            if (math_op == '+') {
                OP = vn_full_adder(FirstBin.bit_type.Bit128_T[i], SecondBin.bit_type.Bit128_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit128_T[i] = LOW;
                else Result.bit_type.Bit128_T[i] = HIGH;
            }
            else if (math_op == '-') {
                OP = vn_full_subtractor(FirstBin.bit_type.Bit128_T[i], SecondBin.bit_type.Bit128_T[i], OP.math_type_second.Carry);
                if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit128_T[i] = LOW;
                else Result.bit_type.Bit128_T[i] = HIGH;
            }
        }

        i -= 1;
        if (i == 0) break;
    }

    if (FirstBin.bit_sign == HIGH || SecondBin.bit_sign == HIGH) Result.bit_sign = HIGH;
    else Result.bit_sign = LOW;

    if (FirstBin.bit_dot == HIGH || SecondBin.bit_dot == HIGH) Result.bit_dot = HIGH;
    else Result.bit_dot = LOW;

    return Result;
}

struct Bin_T vn_add(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    return vn_math(Bin_Size, FirstBin, SecondBin, '+');
}

struct Bin_T vn_sub(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    return vn_math(Bin_Size, FirstBin, SecondBin, '-');
}

/* MADE BY @hanilr */
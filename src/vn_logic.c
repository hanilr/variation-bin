/* VARIATION BINARY (LOGIC) */

/*  STANDARD LIBRARY */
#include <stdio.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_util.h"
#include "lib/vn_conv.h"
#include "lib/vn_manip.h"
#include "lib/vn_logic.h"

struct Bin_T vn_logic_process(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin, char logic_op) {
    struct Bin_T ResultBin;
    int i = 0;

    while (1) { /* Assignment */
        if(logic_op == '&') {
            if (Bin_Size == 4) ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i] & SecondBin.bit_type.Bit4_T[i];
            else if (Bin_Size == 8) ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i] & SecondBin.bit_type.Bit8_T[i];
            else if (Bin_Size == 16) ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i] & SecondBin.bit_type.Bit16_T[i];
            else if (Bin_Size == 32) ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i] & SecondBin.bit_type.Bit32_T[i];
            else if (Bin_Size == 64) ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i] & SecondBin.bit_type.Bit64_T[i];
            else if (Bin_Size == 128) ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i] & SecondBin.bit_type.Bit128_T[i];
        } else if(logic_op == '|') {
            if (Bin_Size == 4) ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i] | SecondBin.bit_type.Bit4_T[i];
            else if (Bin_Size == 8) ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i] | SecondBin.bit_type.Bit8_T[i];
            else if (Bin_Size == 16) ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i] | SecondBin.bit_type.Bit16_T[i];
            else if (Bin_Size == 32) ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i] | SecondBin.bit_type.Bit32_T[i];
            else if (Bin_Size == 64) ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i] | SecondBin.bit_type.Bit64_T[i];
            else if (Bin_Size == 128) ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i] | SecondBin.bit_type.Bit128_T[i];
        } else if(logic_op == '~') {
            if (Bin_Size == 4) {
                vn_bit_toggle(&FirstBin.bit_type.Bit4_T[i]);
                ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i];
            } else if (Bin_Size == 8) {
                vn_bit_toggle(&FirstBin.bit_type.Bit8_T[i]);
                ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i];
            } else if (Bin_Size == 16) {
                vn_bit_toggle(&FirstBin.bit_type.Bit16_T[i]);
                ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i];
            } else if (Bin_Size == 32) {
                vn_bit_toggle(&FirstBin.bit_type.Bit32_T[i]);
                ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i];
            } else if (Bin_Size == 64) {
                vn_bit_toggle(&FirstBin.bit_type.Bit64_T[i]);
                ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i];
            } else if (Bin_Size == 128) {
                vn_bit_toggle(&FirstBin.bit_type.Bit128_T[i]);
                ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i];
            }
        } else if(logic_op == '^') {
            if (Bin_Size == 4) ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i] ^ SecondBin.bit_type.Bit4_T[i];
            else if (Bin_Size == 8) ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i] ^ SecondBin.bit_type.Bit8_T[i];
            else if (Bin_Size == 16) ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i] ^ SecondBin.bit_type.Bit16_T[i];
            else if (Bin_Size == 32) ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i] ^ SecondBin.bit_type.Bit32_T[i];
            else if (Bin_Size == 64) ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i] ^ SecondBin.bit_type.Bit64_T[i];
            else if (Bin_Size == 128) ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i] ^ SecondBin.bit_type.Bit128_T[i];
        }

        i += 1;
        if (i == Bin_Size) break;
    }

    ResultBin.bit_sign = LOW;
    ResultBin.bit_dot = LOW;    

    return ResultBin;
}

struct Bin_T vn_and(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    return vn_logic_process(Bin_Size, FirstBin, SecondBin, '&');
}

struct Bin_T vn_or(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    return vn_logic_process(Bin_Size, FirstBin, SecondBin, '|');
}

struct Bin_T vn_not(enum Bin_S Bin_Size, struct Bin_T FirstBin) {
    return vn_logic_process(Bin_Size, FirstBin, FirstBin, '~');
}

struct Bin_T vn_nand(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    struct Bin_T Bin = vn_and(Bin_Size, FirstBin, SecondBin);
    return vn_not(Bin_Size, Bin);
}

struct Bin_T vn_nor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    struct Bin_T Bin = vn_or(Bin_Size, FirstBin, SecondBin);
    return vn_not(Bin_Size, Bin);
}

struct Bin_T vn_xor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    return vn_logic_process(Bin_Size, FirstBin, SecondBin, '^');
}

struct Bin_T vn_xnor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
    struct Bin_T Bin = vn_xor(Bin_Size, FirstBin, SecondBin);
    return vn_not(Bin_Size, Bin);
}

/* MADE BY @hanilr */
/* VARIATION BINARY (UTILITY) */

/*  STANDARD LIBRARY */
#include <stdio.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_util.h"

void vn_set_sign_bin(struct Bin_T *Bin, enum Bin_E State) {
    Bin->bit_sign = State; // Set sign bit as 'State'
}

void vn_set_dot_bin(struct Bin_T *Bin, enum Bin_E State) {
    Bin->bit_dot = State; // Set dot bit as 'State'
}

struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond) {
    struct Bin_T Bin;
    enum Bin_S Size;
    // Binary type size increase process
    if (Bin_Size == 4) Size = 8;
    else if (Bin_Size == 8) Size = 16;
    else if (Bin_Size == 16) Size = 32;
    else if (Bin_Size == 32) Size = 64;
    else if (Bin_Size == 64) Size = 128;

    int i = 0;
    while (i != Bin_Size) { // Assignment
        if (Size == 8) {
            Bin.bit_type.Bit8_T[i] = BinFirst.bit_type.Bit4_T[i];
            Bin.bit_type.Bit8_T[i + Bin_Size] = BinSecond.bit_type.Bit4_T[i];
        } else if (Size == 16) {
            Bin.bit_type.Bit16_T[i] = BinFirst.bit_type.Bit8_T[i];
            Bin.bit_type.Bit16_T[i + Bin_Size] = BinSecond.bit_type.Bit8_T[i];
        } else if (Size == 32) {
            Bin.bit_type.Bit32_T[i] = BinFirst.bit_type.Bit16_T[i];
            Bin.bit_type.Bit32_T[i + Bin_Size] = BinSecond.bit_type.Bit16_T[i];
        } else if (Size == 64) {
            Bin.bit_type.Bit64_T[i] = BinFirst.bit_type.Bit32_T[i];
            Bin.bit_type.Bit64_T[i + Bin_Size] = BinSecond.bit_type.Bit32_T[i];
        } else if (Size == 128) {
            Bin.bit_type.Bit128_T[i] = BinFirst.bit_type.Bit64_T[i];
            Bin.bit_type.Bit128_T[i + Bin_Size] = BinSecond.bit_type.Bit64_T[i];
        }
        i += 1;
    }

    // Dot check
    if (BinFirst.bit_dot == HIGH || BinSecond.bit_dot == HIGH) Bin.bit_dot = HIGH;
    else Bin.bit_dot = LOW;

    // Sign check
    if (BinFirst.bit_sign == HIGH || BinSecond.bit_sign == HIGH) Bin.bit_sign = HIGH;
    else Bin.bit_sign = LOW;

    return Bin;
} // Max supported bit 64 for merge

struct Bin_T vn_split_bin(enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part) {
    struct Bin_T Bin[2];
    enum Bin_S Size;
    // Binary type size decrease process
    if (Bin_Size == 8) Size = 4;
    else if (Bin_Size == 16) Size = 8;
    else if (Bin_Size == 32) Size = 16;
    else if (Bin_Size == 64) Size = 32;
    else if (Bin_Size == 128) Size = 64;
    
    int part_sel, section_sel;
    if (which_part == 'f') {
        part_sel = 0;
        section_sel = 0;
    } else if (which_part == 's') {
        part_sel = 1;
        section_sel = Size;
    }
    
    int i = 0;
    while (i != Size) { // Assignment
        if (Size == 4) Bin[part_sel].bit_type.Bit4_T[i] = BinInput.bit_type.Bit8_T[section_sel + i];
        else if (Size == 8) Bin[part_sel].bit_type.Bit8_T[i] = BinInput.bit_type.Bit16_T[section_sel + i];
        else if (Size == 16) Bin[part_sel].bit_type.Bit16_T[i] = BinInput.bit_type.Bit32_T[section_sel + i];
        else if (Size == 32) Bin[part_sel].bit_type.Bit32_T[i] = BinInput.bit_type.Bit64_T[section_sel + i];
        else if (Size == 64) Bin[part_sel].bit_type.Bit64_T[i] = BinInput.bit_type.Bit128_T[section_sel + i];
        i += 1;
    }

    // Bit sign and bit dot assignment
    Bin[part_sel].bit_sign = BinInput.bit_sign;
    Bin[part_sel].bit_dot = BinInput.bit_dot;
    return Bin[part_sel];
} // Min supported bit 8 for split

struct Bin_T vn_reverse_bin(enum Bin_S Bin_Size, struct Bin_T BinInput) {
    struct Bin_T Bin;

    int i = 0;
    while (i != Bin_Size) {
        if (Bin_Size == 4) Bin.bit_type.Bit4_T[i] = BinInput.bit_type.Bit4_T[Bin_Size - 1 - i];
        else if (Bin_Size == 8) Bin.bit_type.Bit8_T[i] = BinInput.bit_type.Bit8_T[Bin_Size - 1 - i];
        else if (Bin_Size == 16) Bin.bit_type.Bit16_T[i] = BinInput.bit_type.Bit16_T[Bin_Size - 1 - i];
        else if (Bin_Size == 32) Bin.bit_type.Bit32_T[i] = BinInput.bit_type.Bit32_T[Bin_Size - 1 - i];
        else if (Bin_Size == 64) Bin.bit_type.Bit64_T[i] = BinInput.bit_type.Bit64_T[Bin_Size - 1 - i];
        else if (Bin_Size == 128) Bin.bit_type.Bit128_T[i] = BinInput.bit_type.Bit128_T[Bin_Size - 1 - i];
        i += 1;
    }

    Bin.bit_dot = BinInput.bit_dot;
    Bin.bit_sign = BinInput.bit_sign;

    return Bin;
}

/* MADE BY @hanilr */
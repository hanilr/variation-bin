/* VARIATION BINARY (MANIPULATION) */

/*  STANDARD LIBRARY */
#include <stdio.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_manip.h"

void vn_bit_set(enum Bin_E *Bit, enum Bin_E State) {
    *Bit = State; /* Set to 'State' */
}

enum Bin_E vn_bit_get(enum Bin_E Bit) {
    return Bit == 0 ? LOW : HIGH; /* Simple value return */
}

void vn_bit_toggle(enum Bin_E *Bit) {
    if (*Bit == 0) *Bit = HIGH;
    else *Bit = LOW;
}

void vn_bit_clean_range(enum Bin_S Bin_Size, struct Bin_T *Bin, int start_pos, int end_pos) {
    int i = start_pos;

    while (i != end_pos + 1) { /* Assignment */
        if (Bin_Size == 4) Bin->bit_type.Bit4_T[i] = LOW;
        else if (Bin_Size == 8) Bin->bit_type.Bit8_T[i] = LOW;
        else if (Bin_Size == 16) Bin->bit_type.Bit16_T[i] = LOW;
        else if (Bin_Size == 32) Bin->bit_type.Bit32_T[i] = LOW;
        else if (Bin_Size == 64) Bin->bit_type.Bit64_T[i] = LOW;
        else if (Bin_Size == 128) Bin->bit_type.Bit128_T[i] = LOW;
        i += 1;
    }
}

void vn_bit_clear(enum Bin_S Bin_Size, struct Bin_T *Bin) {
    vn_bit_clean_range(Bin_Size, Bin, 0, Bin_Size); /* Clear in range, start is '0' and end is its size */
}

struct Bin_T vn_bit_get_range(enum Bin_S Bin_Size, enum Bin_S Range_Size, struct Bin_T InputBin, int start_pos, int end_pos) {
    struct Bin_T Bin = {0};
    int i = 0;

    while (Bin_Size - 1 != start_pos + i) { /* Assignment */
        if (Bin_Size == 4) {
            if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit4_T[start_pos + i];
        } else if (Bin_Size == 8) {
            if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit8_T[start_pos + i];
            else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit8_T[start_pos + i];
        } else if (Bin_Size == 16) {
            if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit16_T[start_pos + i];
            else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit16_T[start_pos + i];
            else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit16_T[start_pos + i];
        } else if (Bin_Size == 32) {
            if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
            else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
            else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
            else if (Range_Size == 32) Bin.bit_type.Bit32_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
        } else if (Bin_Size == 64) {
            if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
            else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
            else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
            else if (Range_Size == 32) Bin.bit_type.Bit32_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
            else if (Range_Size == 64) Bin.bit_type.Bit64_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
        } else if (Bin_Size == 128) {
            if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
            else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
            else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
            else if (Range_Size == 32) Bin.bit_type.Bit32_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
            else if (Range_Size == 64) Bin.bit_type.Bit64_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
            else if (Range_Size == 128) Bin.bit_type.Bit128_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
        }
        i += 1;
    }

    Bin.bit_sign = InputBin.bit_sign;
    Bin.bit_dot = InputBin.bit_dot;

    return Bin;
}

void vn_bit_shift_left(enum Bin_S Bin_Size, struct Bin_T *Bin) {
    int i = 0;

    while (1) { /* Assignment */
        if (Bin_Size == 4) {
            Bin->bit_type.Bit4_T[i] = Bin->bit_type.Bit4_T[i + 1];
        } else if (Bin_Size == 8) {
            Bin->bit_type.Bit8_T[i] = Bin->bit_type.Bit8_T[i + 1];
        } else if (Bin_Size == 16) {
            Bin->bit_type.Bit16_T[i] = Bin->bit_type.Bit16_T[i + 1];
        } else if (Bin_Size == 32) {
            Bin->bit_type.Bit32_T[i] = Bin->bit_type.Bit32_T[i + 1];
        } else if (Bin_Size == 64) {
            Bin->bit_type.Bit64_T[i] = Bin->bit_type.Bit64_T[i + 1];
        } else if (Bin_Size == 128) {
            Bin->bit_type.Bit128_T[i] = Bin->bit_type.Bit128_T[i + 1];
        }

        i += 1;
        if (i == Bin_Size - 1) {
            if (Bin_Size == 4) Bin->bit_type.Bit4_T[i] = LOW;
            else if (Bin_Size == 8) Bin->bit_type.Bit8_T[i] = LOW;
            else if (Bin_Size == 16) Bin->bit_type.Bit16_T[i] = LOW;
            else if (Bin_Size == 32) Bin->bit_type.Bit32_T[i] = LOW;
            else if (Bin_Size == 64) Bin->bit_type.Bit64_T[i] = LOW;
            else if (Bin_Size == 128) Bin->bit_type.Bit128_T[i] = LOW;
            break;
        }
    }
}

void vn_bit_shift_right(enum Bin_S Bin_Size, struct Bin_T *Bin) {
    int i = Bin_Size - 1;

    while (1) { /* Assignment */
        if (Bin_Size == 4) {
            Bin->bit_type.Bit4_T[i] = Bin->bit_type.Bit4_T[i - 1];
        } else if (Bin_Size == 8) {
            Bin->bit_type.Bit8_T[i] = Bin->bit_type.Bit8_T[i - 1];
        } else if (Bin_Size == 16) {
            Bin->bit_type.Bit16_T[i] = Bin->bit_type.Bit16_T[i - 1];
        } else if (Bin_Size == 32) {
            Bin->bit_type.Bit32_T[i] = Bin->bit_type.Bit32_T[i - 1];
        } else if (Bin_Size == 64) {
            Bin->bit_type.Bit64_T[i] = Bin->bit_type.Bit64_T[i - 1];
        } else if (Bin_Size == 128) {
            Bin->bit_type.Bit128_T[i] = Bin->bit_type.Bit128_T[i - 1];
        }

        i -= 1;
        if (i == 0) {
            if (Bin_Size == 4) Bin->bit_type.Bit4_T[i] = LOW;
            else if (Bin_Size == 8) Bin->bit_type.Bit8_T[i] = LOW;
            else if (Bin_Size == 16) Bin->bit_type.Bit16_T[i] = LOW;
            else if (Bin_Size == 32) Bin->bit_type.Bit32_T[i] = LOW;
            else if (Bin_Size == 64) Bin->bit_type.Bit64_T[i] = LOW;
            else if (Bin_Size == 128) Bin->bit_type.Bit128_T[i] = LOW;
            break;
        }
    }
}

/* MADE BY @hanilr */
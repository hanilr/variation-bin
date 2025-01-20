/* VARIATION BINARY (DEFINATION) */

/*  STANDARD LIBRARY */
#include <stdio.h>

/* DIY LIBRARY */
#include "lib/vn_def.h"

/* INT TO 8 BIT BINARY */
struct sBin8_T vn_int_sbin8(int input) {
    struct sBin8_T Bin;
    int cInt[7] = {0}, i = 0;
 
    /* SIGN BIT PROCESS */
    if (input < 0) {
        Bin.bit_sign = HIGH; // If sign `-` then 1
        input *= -1;
    }
    else Bin.bit_sign = LOW; // If sign `+` then 0

    while (1) { // Mod to 2 and if not 0 then 1
        if (input % 2 != 0) cInt[i] = 1;
        input /= 2;
        i += 1;
        if (i == 7) break;
    }

    /* EQUATION FROM INTEGER TO BINARY */
    Bin.bit_6 = cInt[6];
    Bin.bit_5 = cInt[5];
    Bin.bit_4 = cInt[4];
    Bin.bit_3 = cInt[3];
    Bin.bit_2 = cInt[2];
    Bin.bit_1 = cInt[1];
    Bin.bit_0 = cInt[0];

    return Bin;
}

/* MADE BY @hanilr */
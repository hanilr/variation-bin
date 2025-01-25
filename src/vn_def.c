/* VARIATION BINARY (DEFINATION) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <math.h>

/* DIY LIBRARY */
#include "lib/vn_def.h"

/* SIGNED INT TO SIGNED 8 BIT BINARY [(-128)-(128)]*/
struct sBin8_T vn_int_sbin8(signed int input) {
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

/* SIGNED 8 BIT TO SIGNED INTEGER */
int vn_sbin8_int(struct sBin8_T Bin) {
    int result = (Bin.bit_0 * 1) + (Bin.bit_1 * 2) + (Bin.bit_2 * pow(2, 2))        \
    + (Bin.bit_3 * pow(2, 3)) + (Bin.bit_4 * pow(2, 4)) + (Bin.bit_5 * pow(2, 5))   \
    + (Bin.bit_6 * pow(2, 6));

    if (Bin.bit_sign == HIGH) result *= -1;
    return result; 
}

/* UNSIGNED INT TO UNSIGNED 8 BIT BINARY [(0)-(256)] */
struct usBin8_T vn_int_usbin8(unsigned int input) {
    struct usBin8_T Bin;
    int cInt[8] = {0}, i = 0;

    while (1) { // Mod to 2 and if not 0 then 1
        if (input % 2 != 0) cInt[i] = 1;
        input /= 2;
        i += 1;
        if (i == 8) break;
    }

    /* EQUATION FROM INTEGER TO BINARY */
    Bin.bit_7 = cInt[7];
    Bin.bit_6 = cInt[6];
    Bin.bit_5 = cInt[5];
    Bin.bit_4 = cInt[4];
    Bin.bit_3 = cInt[3];
    Bin.bit_2 = cInt[2];
    Bin.bit_1 = cInt[1];
    Bin.bit_0 = cInt[0];

    return Bin;
}

/* UNSIGNED 8 BIT TO SIGNED INTEGER */
int vn_usbin8_int(struct usBin8_T Bin) {
    return (Bin.bit_0 * 1) + (Bin.bit_1 * 2) + (Bin.bit_2 * pow(2, 2))              \
    + (Bin.bit_3 * pow(2, 3)) + (Bin.bit_4 * pow(2, 4)) + (Bin.bit_5 * pow(2, 5))   \
    + (Bin.bit_6 * pow(2, 6)) + (Bin.bit_7 * pow(2, 7));
}

/* MADE BY @hanilr */
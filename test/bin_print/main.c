#include <stdio.h>
#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"
#include "../../src/lib/vn_manip.h"
#include "../../src/lib/vn_logic.h"
#include "../../src/lib/vn_math.h"

int main(void) {
    enum Bin_S S_4 = 4;
    enum Bin_S S_8 = 8;
    enum Bin_S S_16 = 16;
    enum Bin_S S_32 = 32;
    enum Bin_S S_64 = 64;
    enum Bin_S S_128 = 128;

    struct Bin_T Bin[6];
    int num[6] = {3, 7, 15, 31, 63, 127};

    Bin[0] = vn_int_to_bin(S_4, num[0]);
    Bin[1] = vn_int_to_bin(S_8, num[1]);
    Bin[2] = vn_int_to_bin(S_16, num[2]);
    Bin[3] = vn_int_to_bin(S_32, num[3]);
    Bin[4] = vn_int_to_bin(S_64, num[4]);
    Bin[5] = vn_int_to_bin(S_128, num[5]);

    bin_print(S_4, Bin[0]);
    bin_print(S_8, Bin[1]);
    bin_print(S_16, Bin[2]);
    bin_print(S_32, Bin[3]);
    bin_print(S_64, Bin[4]);
    bin_print(S_128, Bin[5]);

    return 0;
}
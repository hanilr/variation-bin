#include <stdio.h>
#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"

void bin_printer(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int i = 0;
    printf("\nBit Sign: %d\nBit Dot: %d\n", Bin.bit_sign, Bin.bit_dot);
    while (1) { 
        if (Bin_Size == 8) printf("[%d] ", Bin.bit_type.Bit8_T[i]);
        else if (Bin_Size == 16) printf("[%d] ", Bin.bit_type.Bit16_T[i]);
        else if (Bin_Size == 32) printf("[%d] ", Bin.bit_type.Bit32_T[i]);
        else if (Bin_Size == 64) printf("[%d] ", Bin.bit_type.Bit64_T[i]);

        i += 1;
        if (i == Bin_Size) break;
    }
    printf("\n");
}

int main(void) {
    char *input[] = {"e9", "a3", "a7b8", "f4c3", "a1b2c3d4",    \
    "4d3c2b1a", "1a2b3c4da1b2c3d4", "4d3c2b1ad4c3b2a1"};

    struct Bin_T Bin0;
    struct Bin_T Bin1;
    struct Bin_T Bin2;
    struct Bin_T Bin3;
    struct Bin_T Bin4;
    struct Bin_T Bin5;
    struct Bin_T Bin6;
    struct Bin_T Bin7;

    Bin0 = vn_hex_to_bin(2, input[0]);
    Bin1 = vn_hex_to_bin(2, input[1]);
    Bin2 = vn_hex_to_bin(4, input[2]);
    Bin3 = vn_hex_to_bin(4, input[3]);
    Bin4 = vn_hex_to_bin(8, input[4]);
    Bin5 = vn_hex_to_bin(8, input[5]);
    Bin6 = vn_hex_to_bin(16, input[6]);
    Bin7 = vn_hex_to_bin(16, input[7]);

    bin_printer(8, Bin0);
    printf("\nHex result of Bin0: %s\n", vn_bin_to_hex(8, Bin0));
    bin_printer(8, Bin1);
    printf("\nHex result of Bin1: %s\n", vn_bin_to_hex(8, Bin1));
    bin_printer(16, Bin2);
    printf("\nHex result of Bin2: %s\n", vn_bin_to_hex(16, Bin2));
    bin_printer(16, Bin3);
    printf("\nHex result of Bin3: %s\n", vn_bin_to_hex(16, Bin3));
    bin_printer(32, Bin4);
    printf("\nHex result of Bin4: %s\n", vn_bin_to_hex(32, Bin4));
    bin_printer(32, Bin5);
    printf("\nHex result of Bin5: %s\n", vn_bin_to_hex(32, Bin5));
    bin_printer(64, Bin6);
    printf("\nHex result of Bin6: %s\n", vn_bin_to_hex(64, Bin6));
    bin_printer(64, Bin7);
    printf("\nHex result of Bin7: %s\n", vn_bin_to_hex(64, Bin7));

    return 0;
}

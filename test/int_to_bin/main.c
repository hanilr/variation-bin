#include <stdio.h>
#include "../../src/lib/vn_def.h"

void bin_printer(struct Bin_T Bin) {
    int i = 0;
    printf("\nBit Sign: %d\nBits: ", Bin.bit_sign);
    while (1) { 
        printf("%d ", Bin.bit_type.Bit8_T[i]);
        i += 1;
        if (i == 8) break;
    }
    printf("\n");
}

int main(void) {
    int Int0 = 0, Int1 = 1, Int2 = -1;
    int Int3 = 23, Int4 = 112, Int5 = 129;
    int Int6 = -112, Int7 = -129, Int8 = -244, Int9 = 244;

    enum Bin_S Bin_Selection;
    Bin_Selection = 8;

    struct Bin_T Bin0;
    struct Bin_T Bin1;
    struct Bin_T Bin2;
    struct Bin_T Bin3;
    struct Bin_T Bin4;
    struct Bin_T Bin5;
    struct Bin_T Bin6;
    struct Bin_T Bin7;
    struct Bin_T Bin8;
    struct Bin_T Bin9;

    Bin0 = vn_int_to_bin(Bin_Selection, Int0);
    Bin1 = vn_int_to_bin(Bin_Selection, Int1);
    Bin2 = vn_int_to_bin(Bin_Selection, Int2);
    Bin3 = vn_int_to_bin(Bin_Selection, Int3);
    Bin4 = vn_int_to_bin(Bin_Selection, Int4);
    Bin5 = vn_int_to_bin(Bin_Selection, Int5);
    Bin6 = vn_int_to_bin(Bin_Selection, Int6);
    Bin7 = vn_int_to_bin(Bin_Selection, Int7);
    Bin8 = vn_int_to_bin(Bin_Selection, Int8);
    Bin9 = vn_int_to_bin(Bin_Selection, Int9);

    bin_printer(Bin0);
    bin_printer(Bin1);
    bin_printer(Bin2);
    bin_printer(Bin3);
    bin_printer(Bin4);
    bin_printer(Bin5);
    bin_printer(Bin6);
    bin_printer(Bin7);
    bin_printer(Bin8);
    bin_printer(Bin9);

    return 0;
}
#include <stdio.h>

#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"
#include "../../src/lib/vn_manip.h"
#include "../../src/lib/vn_logic.h"

void bin_printer(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int i = 0;
    printf("\n[Bit Sign: %d]\n", Bin.bit_sign);
    printf("[Bit Dot: %d]\n", Bin.bit_dot);

    while (1) { 
        if (Bin_Size == 4) printf("[%d] ", Bin.bit_type.Bit4_T[i]);
        else if (Bin_Size == 8) printf("[%d] ", Bin.bit_type.Bit8_T[i]);
        else if (Bin_Size == 16) printf("[%d] ", Bin.bit_type.Bit16_T[i]);
        else if (Bin_Size == 32) printf("[%d] ", Bin.bit_type.Bit32_T[i]);
        else if (Bin_Size == 64) printf("[%d] ", Bin.bit_type.Bit64_T[i]);
        else if (Bin_Size == 128) printf("[%d] ", Bin.bit_type.Bit128_T[i]);

        i += 1;
        if (i == Bin_Size) break;
    }
    printf("\n");
}

int main(void) {
    enum Bin_S BinSize = 8;

    struct Bin_T FirstBin = vn_int_to_bin(BinSize, 170);
    bin_printer(BinSize, FirstBin);

    struct Bin_T SecondBin = vn_int_to_bin(BinSize, 85);
    bin_printer(BinSize, SecondBin);

    bin_printer(BinSize, vn_and(BinSize, FirstBin, SecondBin));

    struct Bin_T FirstBin1 = vn_int_to_bin(BinSize, 31);
    bin_printer(BinSize, FirstBin1);

    struct Bin_T SecondBin1 = vn_int_to_bin(BinSize, 63);
    bin_printer(BinSize, SecondBin1);

    bin_printer(BinSize, vn_and(BinSize, FirstBin1, SecondBin1));
    return 0;
}
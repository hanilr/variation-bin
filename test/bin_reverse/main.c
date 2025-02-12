#include <stdio.h>

#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"
#include "../../src/lib/vn_manip.h"

void bin_printer(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int i = 0;
    printf("\n[Bit Sign: %d]\n", Bin.bit_sign);
    printf("[Bit Dot: %d]\n", Bin.bit_dot);

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
    enum Bin_S BinSize = 8;
    struct Bin_T Bin = vn_int_to_bin(BinSize, 15);
    bin_printer(BinSize, Bin);

    struct Bin_T ReverseBin = vn_reverse_bin(BinSize, Bin);
    bin_printer(BinSize, ReverseBin);
    // ---
    struct Bin_T Bin1 = vn_int_to_bin(BinSize, 31);
    bin_printer(BinSize, Bin1);

    struct Bin_T ReverseBin1 = vn_reverse_bin(BinSize, Bin1);
    bin_printer(BinSize, ReverseBin1);
    // ---
    struct Bin_T Bin2 = vn_int_to_bin(BinSize, 63);
    bin_printer(BinSize, Bin2);

    struct Bin_T ReverseBin2 = vn_reverse_bin(BinSize, Bin2);
    bin_printer(BinSize, ReverseBin2);

    return 0;
}
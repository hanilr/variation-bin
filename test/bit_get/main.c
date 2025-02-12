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
    struct Bin_T Bin = vn_int_to_bin(BinSize, 170);
    
    bin_printer(BinSize, Bin);
    enum Bin_E isBit1 = vn_bit_get(Bin.bit_type.Bit8_T[0]);
    enum Bin_E isBit2 = vn_bit_get(Bin.bit_type.Bit8_T[1]);

    printf("\n\nFirst: %d, Second: %d\n", isBit1, isBit2);

    return 0;
}
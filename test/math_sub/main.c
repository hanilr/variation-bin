#include <stdio.h>
#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"
#include "../../src/lib/vn_manip.h"
#include "../../src/lib/vn_logic.h"
#include "../../src/lib/vn_math.h"

void bin_printer(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int i = 0;
    printf("\n[Bit Sign: %d]\n", Bin.bit_sign);
    printf("[Bit Dot: %d]\n", Bin.bit_dot);

    while (1) { 
        if (Bin_Size == 8) printf("[%d] ", Bin.bit_type.Bit8_T[i]);
        else if (Bin_Size == 16) printf("[%d] ", Bin.bit_type.Bit16_T[i]);

        i += 1;
        if (i == Bin_Size) break;
    }
    printf("\n");
}

int main(void) {
    enum Bin_S Bin_Size = 8;
    struct Bin_T FirstBin = vn_int_to_bin(Bin_Size, 45);
    struct Bin_T SecondBin = vn_int_to_bin(Bin_Size, 32);

    bin_printer(Bin_Size, FirstBin);
    bin_printer(Bin_Size, SecondBin);
    bin_printer(Bin_Size, vn_sub(Bin_Size, FirstBin, SecondBin));

    return 0;
}
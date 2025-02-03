#include <stdio.h>

#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"

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
    struct Bin_T Bin1;
    struct Bin_T Bin2;
    struct Bin_T Bin3;
    struct Bin_T Bin4;
    struct Bin_T Bin5;
    enum Bin_S Bin_Size1 = 8;
    enum Bin_S Bin_Size2 = 16;
    enum Bin_S Bin_Size3 = 32;
    enum Bin_S Bin_Size4 = 64;

    double D1 = 5.4;        // 8 bit
    double D2 = -3.2;       // 8 bit
    double D3 = 27.39;      // 8 bit
    double D4 = 139.469;    // 64 bit
    double D5 = 219.3456;   // 64 bit

    Bin1 = vn_double_to_bin(Bin_Size1, D1);
    Bin2 = vn_double_to_bin(Bin_Size1, D2);
    Bin3 = vn_double_to_bin(Bin_Size1, D3);
    Bin4 = vn_double_to_bin(Bin_Size3, D4);
    Bin5 = vn_double_to_bin(Bin_Size3, D5);

    bin_printer(Bin_Size2, Bin1);
    bin_printer(Bin_Size2, Bin2);
    bin_printer(Bin_Size2, Bin3);
    bin_printer(Bin_Size4, Bin4);
    bin_printer(Bin_Size4, Bin5);

    return 0;
}
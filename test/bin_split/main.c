#include <stdio.h>

#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"

void print_bin(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int i = 0;
    printf("\nSign: [%d]\n", Bin.bit_sign);
    printf("Dot: [%d]\n", Bin.bit_dot);
    while (1) {
        if ( Bin_Size == 4) printf("[%d]", Bin.bit_type.Bit4_T[i]);
        else if ( Bin_Size == 8) printf("[%d]", Bin.bit_type.Bit8_T[i]);
        else if ( Bin_Size == 16) printf("[%d]", Bin.bit_type.Bit16_T[i]);
        else if ( Bin_Size == 32) printf("[%d]", Bin.bit_type.Bit32_T[i]);
        else if ( Bin_Size == 64) printf("[%d]", Bin.bit_type.Bit64_T[i]);
        else if ( Bin_Size == 128) printf("[%d]", Bin.bit_type.Bit128_T[i]);

        i += 1;
        if (i == Bin_Size) break;
    }
    printf("\n");
}

int main(void) {
    int first = 45, second = 36;
    enum Bin_S Bin_Size = 8;
    enum Bin_S New_Bin_Size = 4;

    struct Bin_T BinFirst = vn_int_to_bin(Bin_Size, first);
    struct Bin_T BinSecond = vn_int_to_bin(Bin_Size, second);
    struct Bin_T BinResult1 = vn_split_bin(Bin_Size, BinFirst, 'f');
    struct Bin_T BinResult2 = vn_split_bin(Bin_Size, BinSecond, 's');

    print_bin(Bin_Size, BinFirst);
    print_bin(New_Bin_Size, BinResult1);

    print_bin(Bin_Size, BinSecond);
    print_bin(New_Bin_Size, BinResult2);

    return 0;
}
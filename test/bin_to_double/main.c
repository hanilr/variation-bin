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
    enum Bin_S Bin_Size = 16;
    double number = 34.5;
    struct Bin_T Bin = vn_double_to_bin(Bin_Size, number);
    double double_conversion = vn_bin_to_double(Bin_Size*2, Bin);

    enum Bin_S Bin_Size2 = 32;
    double number2 = -61.39;
    struct Bin_T Bin2 = vn_double_to_bin(Bin_Size2, number2);
    double double_conversion2 = vn_bin_to_double(Bin_Size2*2, Bin2);

    printf("\nNumber: %lf", number);
    bin_printer(Bin_Size*2, Bin);
    printf("Conversion Number: %lf\n\n", double_conversion);

    printf("\nNumber: %lf", number2);
    bin_printer(Bin_Size2*2, Bin2);
    printf("Conversion Number: %lf\n\n", double_conversion2);

    return 0;
}
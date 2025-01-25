#include <stdio.h>
#include "../../../src/lib/vn_def.h"

int main(void) {

    struct usBin8_T Bin1;
    struct usBin8_T Bin2;
    struct usBin8_T Bin3;
    struct usBin8_T Bin4;
    struct usBin8_T Bin5;
    int bit1 = 0, bit2 = 1, bit3 = 21, bit4 = 126, bit5 = 240;

    Bin1 = vn_int_usbin8(bit1);
    Bin2 = vn_int_usbin8(bit2);
    Bin3 = vn_int_usbin8(bit3);
    Bin4 = vn_int_usbin8(bit4);
    Bin5 = vn_int_usbin8(bit5);

    int Int1 = vn_usbin8_int(Bin1);
    int Int2 = vn_usbin8_int(Bin2);
    int Int3 = vn_usbin8_int(Bin3);
    int Int4 = vn_usbin8_int(Bin4);
    int Int5 = vn_usbin8_int(Bin5);

    printf("\n1. %d, %d, %d, %d, %d, %d, %d, %d: %d\n", Bin1.bit_7, Bin1.bit_6,       \
        Bin1.bit_5, Bin1.bit_4, Bin1.bit_3, Bin1.bit_2, Bin1.bit_1, Bin1.bit_0, Int1);

    printf("\n2. %d, %d, %d, %d, %d, %d, %d, %d: %d\n", Bin2.bit_7, Bin2.bit_6,      \
        Bin2.bit_5, Bin2.bit_4, Bin2.bit_3, Bin2.bit_2, Bin2.bit_1, Bin2.bit_0, Int2);

    printf("\n3. %d, %d, %d, %d, %d, %d, %d, %d: %d\n", Bin3.bit_7, Bin3.bit_6,       \
        Bin3.bit_5, Bin3.bit_4, Bin3.bit_3, Bin3.bit_2, Bin3.bit_1, Bin3.bit_0, Int3);

    printf("\n4. %d, %d, %d, %d, %d, %d, %d, %d: %d\n", Bin4.bit_7, Bin4.bit_6,      \
        Bin4.bit_5, Bin4.bit_4, Bin4.bit_3, Bin4.bit_2, Bin4.bit_1, Bin4.bit_0, Int4);

    printf("\n5. %d, %d, %d, %d, %d, %d, %d, %d: %d\n", Bin5.bit_7, Bin5.bit_6,     \
        Bin5.bit_5, Bin5.bit_4, Bin5.bit_3, Bin5.bit_2, Bin5.bit_1, Bin5.bit_0, Int5);

    return 0;
}
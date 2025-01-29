#include <stdio.h>
#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"

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

    int Inter0 = vn_bin_to_int(Bin_Selection, Bin0);
    int Inter1 = vn_bin_to_int(Bin_Selection, Bin1);
    int Inter2 = vn_bin_to_int(Bin_Selection, Bin2);
    int Inter3 = vn_bin_to_int(Bin_Selection, Bin3);
    int Inter4 = vn_bin_to_int(Bin_Selection, Bin4);
    int Inter5 = vn_bin_to_int(Bin_Selection, Bin5);
    int Inter6 = vn_bin_to_int(Bin_Selection, Bin6);
    int Inter7 = vn_bin_to_int(Bin_Selection, Bin7);
    int Inter8 = vn_bin_to_int(Bin_Selection, Bin8);
    int Inter9 = vn_bin_to_int(Bin_Selection, Bin9);

    printf("Int: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", \
Inter0, Inter1, Inter2, Inter3, Inter4, Inter5, Inter6,     \
Inter7, Inter8, Inter9);

    return 0;
}
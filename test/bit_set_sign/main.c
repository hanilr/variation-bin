#include <stdio.h>

#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"
#include "../../src/lib/vn_manip.h"

void bin_printer(enum Bin_S Bin_Size, struct Bin_T Bin) {
    int i = 0;
    printf("\n[Bit Sign: %d]\n", Bin.bit_sign);
    printf("[Bit Dot: %d]\n", Bin.bit_dot);
}

int main(void) {

    struct Bin_T Bin = {0};
    vn_set_sign_bin(&Bin, LOW);

    bin_printer(4, Bin);
    vn_set_sign_bin(&Bin, HIGH);
    bin_printer(4, Bin);

    return 0;
}
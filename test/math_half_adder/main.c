#include <stdio.h>
#include "../../src/lib/vn_base.h"
#include "../../src/lib/vn_util.h"
#include "../../src/lib/vn_conv.h"
#include "../../src/lib/vn_manip.h"
#include "../../src/lib/vn_logic.h"
#include "../../src/lib/vn_math.h"

void math_printer(struct Bin_M Math) {
    printf("\n[Sum: %d], [Carry: %d]\n\n", Math.math_type_first.Sum, Math.math_type_second.Carry);
}

int main(void) {
    math_printer(vn_half_adder(0, 0));
    math_printer(vn_half_adder(0, 1));
    math_printer(vn_half_adder(1, 0));
    math_printer(vn_half_adder(1, 1));

    return 0;
}
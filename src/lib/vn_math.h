/* VARIATION BINARY (MATHEMATIC) */
#ifndef _VN_MATH_H
#define _VN_MATH_H

/* HALF ADDER WITH LOGIC GATES */
struct Bin_M vn_half_adder(enum Bin_E A, enum Bin_E B);

/* FULL ADDER WITH LOGIC GATES */
struct Bin_M vn_full_adder(enum Bin_E A, enum Bin_E B, enum Bin_E Cin);

/* HALF SUBTRACTOR WITH LOGIC GATES */
struct Bin_M vn_half_subtractor(enum Bin_E A, enum Bin_E B);

/* FULL SUBTRACTOR WITH LOGIC GATES */
struct Bin_M vn_full_subtractor(enum Bin_E A, enum Bin_E B, enum Bin_E Bin);

/* ADDITION OPERATOR WITH LOGIC GATES */
struct Bin_T vn_add(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

/* SUBTRACT OPERATOR WITH LOGIC GATES */
struct Bin_T vn_sub(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

#endif /* MADE BY @hanilr */
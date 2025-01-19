/* VARIATION BINARY (DEFINATION) */
#ifndef _VN_DEF_H
#define _VN_DEF_H
    
/* BINARY TYPE DECLARATION */
enum Bin_E {
    LOW = 0,    // When bit is logical zero
    HIGH = 1    // When bit is logical one
};

/* SIGNED 8 BIT BINARY TYPE */
struct sBin8_T {
    enum Bin_E bit_sign;    // Singed type declaration for `-` or `+`
    enum Bin_E bit_6;
    enum Bin_E bit_5;
    enum Bin_E bit_4;
    enum Bin_E bit_3;
    enum Bin_E bit_2;
    enum Bin_E bit_1;
    enum Bin_E bit_0;
};

/* UNSIGNED 8 BIT BINARY TYPE */
struct usBin8_T {
    enum Bin_E bit_7;       // Reverse of signed version
    enum Bin_E bit_6;
    enum Bin_E bit_5;
    enum Bin_E bit_4;
    enum Bin_E bit_3;
    enum Bin_E bit_2;
    enum Bin_E bit_1;
    enum Bin_E bit_0;
};

/* CONVERSION OF INTEGER TYPE TO SIGNED 8 BIT BINARY TYPE */
struct sBin8_T vn_int_sbin8(int input);

#endif /* MADE BY @hanilr */
/* VARIATION BINARY (BASE) */
#ifndef _VN_BASE_H
#define _VN_BASE_H
    
enum Bin_E {    /* Binary type declaration  */
    LOW = 0,    /* When bit is logical zero */
    HIGH = 1    /* When bit is logical one  */
};

enum Bin_S {        /* Binary size selection type   */
    S_Bin4 = 4,     /* 4 bit                        */
    S_Bin8 = 8,     /* 8 bit                        */
    S_Bin16 = 16,   /* 16 bit                       */
    S_Bin32 = 32,   /* 32 bit                       */
    S_Bin64 = 64,   /* 64 bit                       */
    S_Bin128 = 128  /* 128 bit                      */
};

enum Hex_S {        /* Hexadecimal size selection type  */
    S_Hex2 = 2,     /* 8 bit                            */
    S_Hex4 = 4,     /* 16 bit                           */
    S_Hex8 = 8,     /* 32 bit                           */
    S_Hex16 = 16    /* 64 bit                           */
};

union Bin_U {                   /* Data size selection part */
    enum Bin_E Bit4_T[3];       /* 8 bit (1 byte)           */
    enum Bin_E Bit8_T[7];       /* 8 bit (1 byte)           */
    enum Bin_E Bit16_T[15];     /* 16 bit (2 byte)          */
    enum Bin_E Bit32_T[31];     /* 32 bit (4 byte)          */
    enum Bin_E Bit64_T[63];     /* 64 bit (8 byte)          */
    enum Bin_E Bit128_T[127];   /* 128 bit (16 byte)        */
};

struct Bin_T {              /* Binary type                                              */
    union Bin_U bit_type;   /* Bit type for 8, 16, 32 and 64                            */
    enum Bin_E bit_sign;    /* Singed type declaration for `-` or `+`                   */
    enum Bin_E bit_dot;     /* If high then split bits to half and last half is decimal */
};

union Bin_Math {        /* Binary math declaration  */
    enum Bin_E Sum;     /* Addition result          */
    enum Bin_E Carry;   /* Addition mod             */
    enum Bin_E Dif;     /* Subtraction result       */
    enum Bin_E Borrow;  /* Subtraction mod          */
};

struct Bin_M {                          /* Math type                    */
    union Bin_Math math_type_first;     /* If this sum or dif           */
    union Bin_Math math_type_second;    /* Than this carry or borrow    */
}; /* Because of union type need to make two variable                   */

#endif /* MADE BY @hanilr */
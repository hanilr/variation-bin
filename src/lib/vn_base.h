/* VARIATION BINARY (BASE) */
#ifndef _VN_BASE_H
#define _VN_BASE_H
    
enum Bin_E { // Binary type declaration
    LOW = 0,    // When bit is logical zero
    HIGH = 1    // When bit is logical one
};

enum Bin_S { // Binary size selection type
    S_Bin8 = 8,     // 8 bit      
    S_Bin16 = 16,   // 16 bit 
    S_Bin32 = 32,   // 32 bit 
    S_Bin64 = 64    // 64 bit 
};

union Bin_U { // Data size selection part
    enum Bin_E Bit8_T[7];   // 8 bit (1 byte)
    enum Bin_E Bit16_T[15]; // 16 bit (2 byte)
    enum Bin_E Bit32_T[31]; // 32 bit (4 byte)
    enum Bin_E Bit64_T[63]; // 64 bit (8 byte)
};

struct Bin_T { // Binary type
    union Bin_U bit_type;   // Bit type for 8, 16, 32 and 64
    enum Bin_E bit_sign;    // Singed type declaration for `-` or `+`
};

#endif /* MADE BY @hanilr */
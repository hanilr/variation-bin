/* VARIATION BINARY (LIBRARY) */
/*     MADE BY @hanilr     */
#ifndef _VN_BIN_H
#define _VN_BIN_H
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

    union Define_T {        /* Multi return type    */
        struct Bin_T Bin;   /* Binary               */
        int Integer;        /* Integer              */
        double Decimal;     /* Double               */
        char *Char;         /* Character            */
        enum Bin_E Bit;     /* Bit                  */
        struct Bin_M Math;  /* Math                 */
    };
    
    /* Variation Binizer: Binary process linker. */
    union Define_T vn_binizer(char *com, ...);
    
    /* Variation Bitizer: Bit manipulation process linker. */
    union Define_T vn_bitizer(char *com, ...);
    
    /* Variation Logicizer: Logic gate linker. */
    struct Bin_T vn_logicizer(char *com, ...);
    
    /* Variation Mathizer: Mathematical operations linker. */
    union Define_T vn_mathizer(char *com, ...);
    
    /* Variation Bin: Binary process. */
    /* ------------------------------ */
    /* [set_sign] Set binary sign. (struct Bin_T *Bin, enum Bin_E State) */
    /* [set_dot] Set binary dot. (struct Bin_T *Bin, enum Bin_E State) */
    /* [merge] Merge two binary to one. (enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond) */
    /* [split] Separate one binary to two. (enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part) */
    /* [reverse] Reverse a binary. (enum Bin_S Bin_Size, struct Bin_T BinInput) */
    /* [int_to_bin] Integer to binary conversion. (enum Bin_S Bin_Size, int input) */
    /* [bin_to_int] Binary to integer conversion. (enum Bin_S Bin_Size, struct Bin_T Bin) */
    /* [double_to_bin] Double to binary conversion. (enum Bin_S Bin_Size, double input) */
    /* [bin_to_double] Binary to double conversion. (enum Bin_S Bin_Size, struct Bin_T Bin) */
    /* [hex_to_bin] Hexadecimal to binary conversion. (enum Hex_S Hex_Size, char *input) */
    /* [bin_to_hex] Binary to hexadecimal conversion. (enum Bin_S Bin_Size, struct Bin_T InputBin) */
    #define vn_bin(com, ...) (vn_binizer(com, __VA_ARGS__))
    
    /* Variation Bit: Bit manipulation process. */
    /* ---------------------------------------- */
    /* [set] Set a bit. (enum Bin_E *Bit, enum Bin_E State) */
    /* [get] Get a bit. (enum Bin_E Bit) */
    /* [toggle] Toggle a bit. (enum Bin_E *Bit) */
    /* [clear] Clear all bits in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin) */
    /* [clean_range] Clear bits in range in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin, int start_pos, int end_pos) */
    /* [get_range] Get bits in range in a binary. (enum Bin_S Bin_Size, enum Bin_S Range_Size, struct Bin_T InputBin, int start_pos, int end_pos) */
    /* [shift_left] Shift left bits in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin) */
    /* [shift_right] Shift right bits in a binary. (enum Bin_S Bin_Size, struct Bin_T *Bin) */
    #define vn_bit(com, ...) (vn_bitizer(com, __VA_ARGS__))
    
    /* Variation Logic: Logic gate. */
    /* ---------------------------- */
    /* [and] AND gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    /* [or] OR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    /* [not] NOT gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin) */
    /* [nand] NAND gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    /* [nor] NOR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    /* [xor] XOR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    /* [xnor] XNOR gate. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    #define vn_logic(com, ...) (vn_logicizer(com, __VA_ARGS__))
    
    /* Variation Math: Mathematical operations. */
    /* ---------------------------------------- */
    /* [half_adder] Half adder operation. (enum Bin_E A, enum Bin_E B) */
    /* [full_adder] Full adder operation. (enum Bin_E A, enum Bin_E B, enum Bin_E Cin) */
    /* [half_subtractor] Half subtractor operation. (enum Bin_E A, enum Bin_E B) */
    /* [full_subtractor] Full subtractor operation. (enum Bin_E A, enum Bin_E B, enum Bin_E Bin) */
    /* [add] Addition operation. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    /* [sub] Subtraction operation. (enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) */
    #define vn_math(com, ...) (vn_mathizer(com, __VA_ARGS__))
#endif /* SUMMARY SECTION */

#ifdef VN_BIN_IMPLEMENTATION
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>

    void vn_set_sign_bin(struct Bin_T *Bin, enum Bin_E State) {
        Bin->bit_sign = State; /* Set sign bit as 'State' */
    }

    void vn_set_dot_bin(struct Bin_T *Bin, enum Bin_E State) {
        Bin->bit_dot = State; /* Set dot bit as 'State' */
    }

    struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond) {
        struct Bin_T Bin;
        enum Bin_S Size;
        /* Binary type size increase process */
        if (Bin_Size == 4) Size = 8;
        else if (Bin_Size == 8) Size = 16;
        else if (Bin_Size == 16) Size = 32;
        else if (Bin_Size == 32) Size = 64;
        else if (Bin_Size == 64) Size = 128;

        int i = 0;
        while (i != Bin_Size) { /* Assignment */
            if (Size == 8) {
                Bin.bit_type.Bit8_T[i] = BinFirst.bit_type.Bit4_T[i];
                Bin.bit_type.Bit8_T[i + Bin_Size] = BinSecond.bit_type.Bit4_T[i];
            } else if (Size == 16) {
                Bin.bit_type.Bit16_T[i] = BinFirst.bit_type.Bit8_T[i];
                Bin.bit_type.Bit16_T[i + Bin_Size] = BinSecond.bit_type.Bit8_T[i];
            } else if (Size == 32) {
                Bin.bit_type.Bit32_T[i] = BinFirst.bit_type.Bit16_T[i];
                Bin.bit_type.Bit32_T[i + Bin_Size] = BinSecond.bit_type.Bit16_T[i];
            } else if (Size == 64) {
                Bin.bit_type.Bit64_T[i] = BinFirst.bit_type.Bit32_T[i];
                Bin.bit_type.Bit64_T[i + Bin_Size] = BinSecond.bit_type.Bit32_T[i];
            } else if (Size == 128) {
                Bin.bit_type.Bit128_T[i] = BinFirst.bit_type.Bit64_T[i];
                Bin.bit_type.Bit128_T[i + Bin_Size] = BinSecond.bit_type.Bit64_T[i];
            }
            i += 1;
        }

        /* Dot check */
        if (BinFirst.bit_dot == HIGH || BinSecond.bit_dot == HIGH) Bin.bit_dot = HIGH;
        else Bin.bit_dot = LOW;

        /* Sign check */
        if (BinFirst.bit_sign == HIGH || BinSecond.bit_sign == HIGH) Bin.bit_sign = HIGH;
        else Bin.bit_sign = LOW;

        return Bin;
    } /* Max supported bit 64 for merge */

    struct Bin_T vn_split_bin(enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part) {
        struct Bin_T Bin[2];
        enum Bin_S Size;
        /* Binary type size decrease process */
        if (Bin_Size == 8) Size = 4;
        else if (Bin_Size == 16) Size = 8;
        else if (Bin_Size == 32) Size = 16;
        else if (Bin_Size == 64) Size = 32;
        else if (Bin_Size == 128) Size = 64;

        int part_sel, section_sel;
        if (which_part == 'f') {
            part_sel = 0;
            section_sel = 0;
        }
        else if (which_part == 's') {
            part_sel = 1;
            section_sel = Size;
        }

        int i = 0;
        while (i != Size) { /* Assignment */
            if (Size == 4) Bin[part_sel].bit_type.Bit4_T[i] = BinInput.bit_type.Bit8_T[section_sel + i];
            else if (Size == 8) Bin[part_sel].bit_type.Bit8_T[i] = BinInput.bit_type.Bit16_T[section_sel + i];
            else if (Size == 16) Bin[part_sel].bit_type.Bit16_T[i] = BinInput.bit_type.Bit32_T[section_sel + i];
            else if (Size == 32) Bin[part_sel].bit_type.Bit32_T[i] = BinInput.bit_type.Bit64_T[section_sel + i];
            else if (Size == 64) Bin[part_sel].bit_type.Bit64_T[i] = BinInput.bit_type.Bit128_T[section_sel + i];
            i += 1;
        }

        /* Bit sign and bit dot assignment */
        Bin[part_sel].bit_sign = BinInput.bit_sign;
        Bin[part_sel].bit_dot = BinInput.bit_dot;
        return Bin[part_sel];
    } /* Min supported bit 8 for split */

    struct Bin_T vn_reverse_bin(enum Bin_S Bin_Size, struct Bin_T BinInput) {
        struct Bin_T Bin;

        int i = 0;
        while (i != Bin_Size) {
            if (Bin_Size == 4) Bin.bit_type.Bit4_T[i] = BinInput.bit_type.Bit4_T[Bin_Size - 1 - i];
            else if (Bin_Size == 8) Bin.bit_type.Bit8_T[i] = BinInput.bit_type.Bit8_T[Bin_Size - 1 - i];
            else if (Bin_Size == 16) Bin.bit_type.Bit16_T[i] = BinInput.bit_type.Bit16_T[Bin_Size - 1 - i];
            else if (Bin_Size == 32) Bin.bit_type.Bit32_T[i] = BinInput.bit_type.Bit32_T[Bin_Size - 1 - i];
            else if (Bin_Size == 64) Bin.bit_type.Bit64_T[i] = BinInput.bit_type.Bit64_T[Bin_Size - 1 - i];
            else if (Bin_Size == 128) Bin.bit_type.Bit128_T[i] = BinInput.bit_type.Bit128_T[Bin_Size - 1 - i];
            i += 1;
        }

        Bin.bit_dot = BinInput.bit_dot;
        Bin.bit_sign = BinInput.bit_sign;

        return Bin;
    }

    struct Bin_T vn_int_to_bin(enum Bin_S Bin_Size, int input) {
        int cInt[128] = {0}, i = 0, n = Bin_Size-1;
        struct Bin_T Bin;

        while (1) { /* Conversion */
            if (input % 2 != 0) cInt[i] = 1;
            input /= 2;
            i += 1;
            if (i == 128) break;
        } i = 0;

        while (i != Bin_Size || n >= 0) { /* Assignment */
            if (Bin_Size == 4) Bin.bit_type.Bit4_T[i] = cInt[n];
            else if (Bin_Size == 8) Bin.bit_type.Bit8_T[i] = cInt[n];
            else if (Bin_Size == 16) Bin.bit_type.Bit16_T[i] = cInt[n];
            else if (Bin_Size == 32) Bin.bit_type.Bit32_T[i] = cInt[n];
            else if (Bin_Size == 64) Bin.bit_type.Bit64_T[i] = cInt[n];
            else if (Bin_Size == 128) Bin.bit_type.Bit128_T[i] = cInt[n];
            i += 1;
            n -= 1;
        }
        /* Sign bit process */
        if (input < 0) Bin.bit_sign = HIGH; 
        else Bin.bit_sign = LOW;
        Bin.bit_dot = LOW; /* Set 'LOW' as default */

        return Bin;
    }

    int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin) {
        int result = 0, cInt[128] = {0}, i = 0, n = Bin_Size-1;

        while (i != Bin_Size || n >= 0) { /* Assignment */
            if (Bin_Size == 4) cInt[n] = Bin.bit_type.Bit4_T[i];
            else if (Bin_Size == 8) cInt[n] = Bin.bit_type.Bit8_T[i];
            else if (Bin_Size == 16) cInt[n] = Bin.bit_type.Bit16_T[i];
            else if (Bin_Size == 32) cInt[n] = Bin.bit_type.Bit32_T[i];
            else if (Bin_Size == 64) cInt[n] = Bin.bit_type.Bit64_T[i];
            else if (Bin_Size == 128) cInt[n] = Bin.bit_type.Bit128_T[i];
            i += 1;
            n -= 1;
        }

        i = 0;
        n = 1;
        while (i != Bin_Size) { /* Solution*/
            result += cInt[i] * n;
            i += 1;
            n *= 2;
        }

        if (Bin.bit_sign == HIGH) result *= -1;
        return result;
    }

    struct Bin_T vn_double_to_bin(enum Bin_S Bin_Size, double input) {
        struct Bin_T Bin[2];
        struct Bin_T Result;

        int part_int = (int)input; /* Integer part */
        double dec = input - part_int;
        int part_dec = (int)(dec * 1000000);

        int i = 0;
        while (i != 6) {
            if (part_dec % 10 == 0) part_dec /= 10;
            else break;
            i += 1;
        } 

        Bin[0] = vn_int_to_bin(Bin_Size, part_int);
        Bin[1] = vn_int_to_bin(Bin_Size, part_dec);

        Result = vn_merge_bin(Bin_Size, Bin[0], Bin[1]);
        Result.bit_dot = HIGH; /* Set the bit is double */
        /* Sign bit process */
        if (input < 0) Result.bit_sign = HIGH;
        else Result.bit_sign = LOW;

        return Result;
    } /* Double type limited to max 64 bit because of merge function */

    double vn_bin_to_double(enum Bin_S Bin_Size, struct Bin_T Bin) {
        enum Bin_E B_Sign = Bin.bit_sign;
        Bin.bit_sign = LOW;

        /* Solution */
        struct Bin_T BinInt = vn_split_bin(Bin_Size, Bin, 'f');
        struct Bin_T BinDec = vn_split_bin(Bin_Size, Bin, 's');
        /* Specification */
        int part_int = vn_bin_to_int(Bin_Size/2, BinInt);
        int part_dec = vn_bin_to_int(Bin_Size/2, BinDec);

        if (part_dec == 0) return part_int;
        double dec = (double)part_dec, result;

        int i = 0;
        while (part_dec > 0) {
            part_dec /= 10;
            i += 1;
        } /* Find digit */

        while (i > 0) {
            dec /= 10;
            i -= 1;
        } /* Find decimal part */
        result = part_int + dec;

        if (B_Sign == HIGH) result *= -1;
        return result;
    }

    struct Bin_T vn_hex_to_bin(enum Hex_S Hex_Size, char *input) {
        int input_len = strlen(input);
        enum Bin_S Bin_Size;
        struct Bin_T Bin[input_len];
        struct Bin_T Result;
        int i = 0, cInt[input_len];

        if (Hex_Size == 2) Bin_Size = 8;
        else if (Hex_Size == 4) Bin_Size = 16;
        else if (Hex_Size == 8) Bin_Size = 32;
        else if (Hex_Size == 16) Bin_Size = 64;

        while (i != input_len) { /* Data conversion */
            if (input[i] >= '0' && input[i] <= '9') cInt[i] = input[i] - '0';
            else if (input[i] >= 'a' && input[i] <= 'f') cInt[i] = 10 + (input[i] - 'a');
            i += 1;
        } i = 0;

        while (i != input_len) { /* Type conversion */
            Bin[i] = vn_int_to_bin(4, cInt[i]);
            i += 1;
        }

        if (Bin_Size == 8) {
            Result = vn_merge_bin(4, Bin[0], Bin[1]);
        } else if (Bin_Size == 16) {
            Result = vn_merge_bin(8, vn_merge_bin(4, Bin[0], Bin[1]), vn_merge_bin(4, Bin[2], Bin[3]));
        } else if (Bin_Size == 32) {
            Bin[0] = vn_merge_bin(8, vn_merge_bin(4, Bin[0], Bin[1]), vn_merge_bin(4, Bin[2], Bin[3]));
            Bin[1] = vn_merge_bin(8, vn_merge_bin(4, Bin[4], Bin[5]), vn_merge_bin(4, Bin[6], Bin[7]));
            Result = vn_merge_bin(16, Bin[0], Bin[1]);
        } else if (Bin_Size == 64) {
            Bin[0] = vn_merge_bin(8, vn_merge_bin(4, Bin[0], Bin[1]), vn_merge_bin(4, Bin[2], Bin[3]));
            Bin[1] = vn_merge_bin(8, vn_merge_bin(4, Bin[4], Bin[5]), vn_merge_bin(4, Bin[6], Bin[7]));
            Result = vn_merge_bin(16, Bin[0], Bin[1]);

            Bin[0] = vn_merge_bin(8, vn_merge_bin(4, Bin[8], Bin[9]), vn_merge_bin(4, Bin[10], Bin[11]));
            Bin[1] = vn_merge_bin(8, vn_merge_bin(4, Bin[12], Bin[13]), vn_merge_bin(4, Bin[14], Bin[15]));
            Bin[2] = vn_merge_bin(16, Bin[0], Bin[1]);
            Result = vn_merge_bin(32, Result, Bin[2]);
        } 

        Result.bit_dot = HIGH;
        return Result;
    }

    char* vn_bin_to_hex(enum Bin_S Bin_Size, struct Bin_T InputBin) {
        int Hex_Size;

        if (Bin_Size == 8) Hex_Size = 2;
        else if (Bin_Size == 16) Hex_Size = 4;
        else if (Bin_Size == 32) Hex_Size = 8;
        else if (Bin_Size == 64) Hex_Size = 16;

        struct Bin_T Bin[Hex_Size];
        char *result = (char*)malloc((Hex_Size) * sizeof(char));

        char check[16][4] = {
            {'f', 'f', 'f', 'f'}, {'f', 'f', 'f', 's'}, {'f', 'f', 's', 'f'}, {'f', 'f', 's', 's'},
            {'f', 's', 'f', 'f'}, {'f', 's', 'f', 's'}, {'f', 's', 's', 'f'}, {'f', 's', 's', 's'},
            {'s', 'f', 'f', 'f'}, {'s', 'f', 'f', 's'}, {'s', 'f', 's', 'f'}, {'s', 'f', 's', 's'}, 
            {'s', 's', 'f', 'f'}, {'s', 's', 'f', 's'}, {'s', 's', 's', 'f'}, {'s', 's', 's', 's'}
        };

        int i = 0, n = 0, temp_size = 8, cInt[Hex_Size]; 
        while (i != Hex_Size) { /* Solution */
            if (Hex_Size == 2) {
                Bin[i] = vn_split_bin(8, InputBin, check[i][3]);
            } else if (Hex_Size == 4) {
                Bin[i] = vn_split_bin(8, vn_split_bin(16, InputBin, check[i][2]), check[i][3]);
            } else if (Hex_Size == 8) {
                Bin[i] = vn_split_bin(8, vn_split_bin(16, vn_split_bin(32, InputBin, check[i][1]), check[i][2]), check[i][3]);
            } else if (Hex_Size == 16) {
                Bin[i] = vn_split_bin(8, vn_split_bin(16, vn_split_bin(32, vn_split_bin(64, InputBin, check[i][0]), check[i][1]), check[i][2]), check[i][3]);
            } 
            i += 1;
        } i = 0;

        while (i != Hex_Size) { /* Type conversion */
            cInt[i] = vn_bin_to_int(4, Bin[i]);
            i += 1;
        } i = 0;

        while (i != Hex_Size) { /* Data conversion */
            if (cInt[i] >= 0 && cInt[i] <= 9) result[i] = cInt[i] + '0';
            else if (cInt[i] >= 10 && cInt[i] <= 15) result[i] = (cInt[i] - 10 ) + 'a';
            i += 1;
        }

        result[Hex_Size] = '\0';
        return result;
    }

    void vn_bit_set(enum Bin_E *Bit, enum Bin_E State) {
        *Bit = State; /* Set to 'State' */
    }

    enum Bin_E vn_bit_get(enum Bin_E Bit) {
        return Bit == 0 ? LOW : HIGH; /* Simple value return */
    }

    void vn_bit_toggle(enum Bin_E *Bit) {
        if (*Bit == 0) *Bit = HIGH;
        else *Bit = LOW;
    }

    void vn_bit_clean_range(enum Bin_S Bin_Size, struct Bin_T *Bin, int start_pos, int end_pos) {
        int i = start_pos;

        while (i != end_pos + 1) { /* Assignment */
            if (Bin_Size == 4) Bin->bit_type.Bit4_T[i] = LOW;
            else if (Bin_Size == 8) Bin->bit_type.Bit8_T[i] = LOW;
            else if (Bin_Size == 16) Bin->bit_type.Bit16_T[i] = LOW;
            else if (Bin_Size == 32) Bin->bit_type.Bit32_T[i] = LOW;
            else if (Bin_Size == 64) Bin->bit_type.Bit64_T[i] = LOW;
            else if (Bin_Size == 128) Bin->bit_type.Bit128_T[i] = LOW;
            i += 1;
        }
    }

    void vn_bit_clear(enum Bin_S Bin_Size, struct Bin_T *Bin) {
        vn_bit_clean_range(Bin_Size, Bin, 0, Bin_Size); /* Clear in range, start is '0' and end is its size */
    }

    struct Bin_T vn_bit_get_range(enum Bin_S Bin_Size, enum Bin_S Range_Size, struct Bin_T InputBin, int start_pos, int end_pos) {
        struct Bin_T Bin = {0};
        int i = 0;

        while (Bin_Size - 1 != start_pos + i) { /* Assignment */
            if (Bin_Size == 4) {
                if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit4_T[start_pos + i];
            } else if (Bin_Size == 8) {
                if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit8_T[start_pos + i];
                else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit8_T[start_pos + i];
            } else if (Bin_Size == 16) {
                if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit16_T[start_pos + i];
                else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit16_T[start_pos + i];
                else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit16_T[start_pos + i];
            } else if (Bin_Size == 32) {
                if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
                else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
                else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
                else if (Range_Size == 32) Bin.bit_type.Bit32_T[i] = InputBin.bit_type.Bit32_T[start_pos + i];
            } else if (Bin_Size == 64) {
                if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
                else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
                else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
                else if (Range_Size == 32) Bin.bit_type.Bit32_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
                else if (Range_Size == 64) Bin.bit_type.Bit64_T[i] = InputBin.bit_type.Bit64_T[start_pos + i];
            } else if (Bin_Size == 128) {
                if (Range_Size == 4) Bin.bit_type.Bit4_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
                else if (Range_Size == 8) Bin.bit_type.Bit8_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
                else if (Range_Size == 16) Bin.bit_type.Bit16_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
                else if (Range_Size == 32) Bin.bit_type.Bit32_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
                else if (Range_Size == 64) Bin.bit_type.Bit64_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
                else if (Range_Size == 128) Bin.bit_type.Bit128_T[i] = InputBin.bit_type.Bit128_T[start_pos + i];
            }
            i += 1;
        }

        Bin.bit_sign = InputBin.bit_sign;
        Bin.bit_dot = InputBin.bit_dot;

        return Bin;
    }

    void vn_bit_shift_left(enum Bin_S Bin_Size, struct Bin_T *Bin) {
        int i = 0;

        while (1) { /* Assignment */
            if (Bin_Size == 4) {
                Bin->bit_type.Bit4_T[i] = Bin->bit_type.Bit4_T[i + 1];
            } else if (Bin_Size == 8) {
                Bin->bit_type.Bit8_T[i] = Bin->bit_type.Bit8_T[i + 1];
            } else if (Bin_Size == 16) {
                Bin->bit_type.Bit16_T[i] = Bin->bit_type.Bit16_T[i + 1];
            } else if (Bin_Size == 32) {
                Bin->bit_type.Bit32_T[i] = Bin->bit_type.Bit32_T[i + 1];
            } else if (Bin_Size == 64) {
                Bin->bit_type.Bit64_T[i] = Bin->bit_type.Bit64_T[i + 1];
            } else if (Bin_Size == 128) {
                Bin->bit_type.Bit128_T[i] = Bin->bit_type.Bit128_T[i + 1];
            }

            i += 1;
            if (i == Bin_Size - 1) {
                if (Bin_Size == 4) Bin->bit_type.Bit4_T[i] = LOW;
                else if (Bin_Size == 8) Bin->bit_type.Bit8_T[i] = LOW;
                else if (Bin_Size == 16) Bin->bit_type.Bit16_T[i] = LOW;
                else if (Bin_Size == 32) Bin->bit_type.Bit32_T[i] = LOW;
                else if (Bin_Size == 64) Bin->bit_type.Bit64_T[i] = LOW;
                else if (Bin_Size == 128) Bin->bit_type.Bit128_T[i] = LOW;
                break;
            }
        }
    }

    void vn_bit_shift_right(enum Bin_S Bin_Size, struct Bin_T *Bin) {
        int i = Bin_Size - 1;

        while (1) { /* Assignment */
            if (Bin_Size == 4) {
                Bin->bit_type.Bit4_T[i] = Bin->bit_type.Bit4_T[i - 1];
            } else if (Bin_Size == 8) {
                Bin->bit_type.Bit8_T[i] = Bin->bit_type.Bit8_T[i - 1];
            } else if (Bin_Size == 16) {
                Bin->bit_type.Bit16_T[i] = Bin->bit_type.Bit16_T[i - 1];
            } else if (Bin_Size == 32) {
                Bin->bit_type.Bit32_T[i] = Bin->bit_type.Bit32_T[i - 1];
            } else if (Bin_Size == 64) {
                Bin->bit_type.Bit64_T[i] = Bin->bit_type.Bit64_T[i - 1];
            } else if (Bin_Size == 128) {
                Bin->bit_type.Bit128_T[i] = Bin->bit_type.Bit128_T[i - 1];
            }

            i -= 1;
            if (i == 0) {
                if (Bin_Size == 4) Bin->bit_type.Bit4_T[i] = LOW;
                else if (Bin_Size == 8) Bin->bit_type.Bit8_T[i] = LOW;
                else if (Bin_Size == 16) Bin->bit_type.Bit16_T[i] = LOW;
                else if (Bin_Size == 32) Bin->bit_type.Bit32_T[i] = LOW;
                else if (Bin_Size == 64) Bin->bit_type.Bit64_T[i] = LOW;
                else if (Bin_Size == 128) Bin->bit_type.Bit128_T[i] = LOW;
                break;
            }
        }
    }

    struct Bin_T vn_logic_process(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin, char logic_op) {
        struct Bin_T ResultBin;
        int i = 0;

        while (1) { /* Assignment */
            if(logic_op == '&') {
                if (Bin_Size == 4) ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i] & SecondBin.bit_type.Bit4_T[i];
                else if (Bin_Size == 8) ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i] & SecondBin.bit_type.Bit8_T[i];
                else if (Bin_Size == 16) ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i] & SecondBin.bit_type.Bit16_T[i];
                else if (Bin_Size == 32) ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i] & SecondBin.bit_type.Bit32_T[i];
                else if (Bin_Size == 64) ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i] & SecondBin.bit_type.Bit64_T[i];
                else if (Bin_Size == 128) ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i] & SecondBin.bit_type.Bit128_T[i];
            } else if(logic_op == '|') {
                if (Bin_Size == 4) ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i] | SecondBin.bit_type.Bit4_T[i];
                else if (Bin_Size == 8) ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i] | SecondBin.bit_type.Bit8_T[i];
                else if (Bin_Size == 16) ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i] | SecondBin.bit_type.Bit16_T[i];
                else if (Bin_Size == 32) ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i] | SecondBin.bit_type.Bit32_T[i];
                else if (Bin_Size == 64) ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i] | SecondBin.bit_type.Bit64_T[i];
                else if (Bin_Size == 128) ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i] | SecondBin.bit_type.Bit128_T[i];
            } else if(logic_op == '~') {
                if (Bin_Size == 4) {
                    vn_bit_toggle(&FirstBin.bit_type.Bit4_T[i]);
                    ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i];
                } else if (Bin_Size == 8) {
                    vn_bit_toggle(&FirstBin.bit_type.Bit8_T[i]);
                    ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i];
                } else if (Bin_Size == 16) {
                    vn_bit_toggle(&FirstBin.bit_type.Bit16_T[i]);
                    ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i];
                } else if (Bin_Size == 32) {
                    vn_bit_toggle(&FirstBin.bit_type.Bit32_T[i]);
                    ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i];
                } else if (Bin_Size == 64) {
                    vn_bit_toggle(&FirstBin.bit_type.Bit64_T[i]);
                    ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i];
                } else if (Bin_Size == 128) {
                    vn_bit_toggle(&FirstBin.bit_type.Bit128_T[i]);
                    ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i];
                }
            } else if(logic_op == '^') {
                if (Bin_Size == 4) ResultBin.bit_type.Bit4_T[i] = FirstBin.bit_type.Bit4_T[i] ^ SecondBin.bit_type.Bit4_T[i];
                else if (Bin_Size == 8) ResultBin.bit_type.Bit8_T[i] = FirstBin.bit_type.Bit8_T[i] ^ SecondBin.bit_type.Bit8_T[i];
                else if (Bin_Size == 16) ResultBin.bit_type.Bit16_T[i] = FirstBin.bit_type.Bit16_T[i] ^ SecondBin.bit_type.Bit16_T[i];
                else if (Bin_Size == 32) ResultBin.bit_type.Bit32_T[i] = FirstBin.bit_type.Bit32_T[i] ^ SecondBin.bit_type.Bit32_T[i];
                else if (Bin_Size == 64) ResultBin.bit_type.Bit64_T[i] = FirstBin.bit_type.Bit64_T[i] ^ SecondBin.bit_type.Bit64_T[i];
                else if (Bin_Size == 128) ResultBin.bit_type.Bit128_T[i] = FirstBin.bit_type.Bit128_T[i] ^ SecondBin.bit_type.Bit128_T[i];
            }

            i += 1;
            if (i == Bin_Size) break;
        }

        ResultBin.bit_sign = LOW;
        ResultBin.bit_dot = LOW;    

        return ResultBin;
    }

    struct Bin_T vn_and(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        return vn_logic_process(Bin_Size, FirstBin, SecondBin, '&');
    }

    struct Bin_T vn_or(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        return vn_logic_process(Bin_Size, FirstBin, SecondBin, '|');
    }

    struct Bin_T vn_not(enum Bin_S Bin_Size, struct Bin_T FirstBin) {
        return vn_logic_process(Bin_Size, FirstBin, FirstBin, '~');
    }

    struct Bin_T vn_nand(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        struct Bin_T Bin = vn_and(Bin_Size, FirstBin, SecondBin);
        return vn_not(Bin_Size, Bin);
    }

    struct Bin_T vn_nor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        struct Bin_T Bin = vn_or(Bin_Size, FirstBin, SecondBin);
        return vn_not(Bin_Size, Bin);
    }

    struct Bin_T vn_xor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        return vn_logic_process(Bin_Size, FirstBin, SecondBin, '^');
    }

    struct Bin_T vn_xnor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        struct Bin_T Bin = vn_xor(Bin_Size, FirstBin, SecondBin);
        return vn_not(Bin_Size, Bin);
    }
    
    struct Bin_M vn_half_adder(enum Bin_E A, enum Bin_E B) {
        struct Bin_M Result;

        Result.math_type_first.Sum = A ^ B;
        Result.math_type_second.Carry = A & B;

        return Result;
    }

    struct Bin_M vn_full_adder(enum Bin_E A, enum Bin_E B, enum Bin_E Cin) {
        struct Bin_M Result;
        struct Bin_M Sum;
        struct Bin_M Carry;

        Carry = vn_half_adder(A, B);
        Sum = vn_half_adder(Carry.math_type_first.Sum, Cin);

        Result.math_type_first.Sum = Sum.math_type_first.Sum;
        Result.math_type_second.Carry = Carry.math_type_second.Carry | Sum.math_type_second.Carry;

        return Result;
    }

    struct Bin_M vn_half_subtractor(enum Bin_E A, enum Bin_E B) {
        struct Bin_M Result;
        int temp_not;

        if (A == HIGH) temp_not = 0;
        else temp_not = 1;

        Result.math_type_first.Dif = A ^ B;
        Result.math_type_second.Borrow = temp_not & B;

        return Result;
    }

    struct Bin_M vn_full_subtractor(enum Bin_E A, enum Bin_E B, enum Bin_E Bin) {
        struct Bin_M Result;
        struct Bin_M Dif;
        struct Bin_M Borrow;

        Borrow = vn_half_subtractor(A, B);
        Dif = vn_half_subtractor(Borrow.math_type_first.Dif, Bin);

        Result.math_type_first.Dif = Dif.math_type_first.Dif;
        Result.math_type_second.Borrow = Dif.math_type_second.Borrow | Borrow.math_type_second.Borrow;

        return Result;
    }

    struct Bin_T vn_math_process(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin, char math_op) {
        struct Bin_T Result = {0};
        struct Bin_M OP = {0};

        int i = Bin_Size - 1;
        while (1) { /* Assignment */
            if (Bin_Size == 4){
                if (math_op == '+') {
                    OP = vn_full_adder(FirstBin.bit_type.Bit4_T[i], SecondBin.bit_type.Bit4_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit4_T[i] = LOW;
                    else Result.bit_type.Bit4_T[i] = HIGH;
                }
                else if (math_op == '-') {
                    OP = vn_full_subtractor(FirstBin.bit_type.Bit4_T[i], SecondBin.bit_type.Bit4_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit4_T[i] = LOW;
                    else Result.bit_type.Bit4_T[i] = HIGH;
                }
            } else if (Bin_Size == 8) {
                if (math_op == '+') {
                    OP = vn_full_adder(FirstBin.bit_type.Bit8_T[i], SecondBin.bit_type.Bit8_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit8_T[i] = LOW;
                    else Result.bit_type.Bit8_T[i] = HIGH;
                }   
                else if (math_op == '-') {
                    OP = vn_full_subtractor(FirstBin.bit_type.Bit8_T[i], SecondBin.bit_type.Bit8_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit8_T[i] = LOW;
                    else Result.bit_type.Bit8_T[i] = HIGH;
                }
            } else if (Bin_Size == 16) {
                if (math_op == '+') {
                    OP = vn_full_adder(FirstBin.bit_type.Bit16_T[i], SecondBin.bit_type.Bit16_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit16_T[i] = LOW;
                    else Result.bit_type.Bit16_T[i] = HIGH;
                }
                else if (math_op == '-') {
                    OP = vn_full_subtractor(FirstBin.bit_type.Bit16_T[i], SecondBin.bit_type.Bit16_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit16_T[i] = LOW;
                    else Result.bit_type.Bit16_T[i] = HIGH;
                }
            } else if (Bin_Size == 32) {
                if (math_op == '+') {
                    OP = vn_full_adder(FirstBin.bit_type.Bit32_T[i], SecondBin.bit_type.Bit32_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit32_T[i] = LOW;
                    else Result.bit_type.Bit32_T[i] = HIGH;
                }
                else if (math_op == '-') {
                    OP = vn_full_subtractor(FirstBin.bit_type.Bit32_T[i], SecondBin.bit_type.Bit32_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit32_T[i] = LOW;
                    else Result.bit_type.Bit32_T[i] = HIGH;
                }
            } else if (Bin_Size == 64) {
                if (math_op == '+') {
                    OP = vn_full_adder(FirstBin.bit_type.Bit64_T[i], SecondBin.bit_type.Bit64_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit64_T[i] = LOW;
                    else Result.bit_type.Bit64_T[i] = HIGH;
                }
                else if (math_op == '-') {
                    OP = vn_full_subtractor(FirstBin.bit_type.Bit64_T[i], SecondBin.bit_type.Bit64_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit64_T[i] = LOW;
                    else Result.bit_type.Bit64_T[i] = HIGH;
                }
            } else if (Bin_Size == 128) {
                if (math_op == '+') {
                    OP = vn_full_adder(FirstBin.bit_type.Bit128_T[i], SecondBin.bit_type.Bit128_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit128_T[i] = LOW;
                    else Result.bit_type.Bit128_T[i] = HIGH;
                }
                else if (math_op == '-') {
                    OP = vn_full_subtractor(FirstBin.bit_type.Bit128_T[i], SecondBin.bit_type.Bit128_T[i], OP.math_type_second.Carry);
                    if (OP.math_type_first.Sum == LOW && OP.math_type_second.Carry == LOW) Result.bit_type.Bit128_T[i] = LOW;
                    else Result.bit_type.Bit128_T[i] = HIGH;
                }
            }

            i -= 1;
            if (i == 0) break;
        }

        if (FirstBin.bit_sign == HIGH || SecondBin.bit_sign == HIGH) Result.bit_sign = HIGH;
        else Result.bit_sign = LOW;

        if (FirstBin.bit_dot == HIGH || SecondBin.bit_dot == HIGH) Result.bit_dot = HIGH;
        else Result.bit_dot = LOW;

        return Result;
    }

    struct Bin_T vn_add(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        return vn_math_process(Bin_Size, FirstBin, SecondBin, '+');
    }

    struct Bin_T vn_sub(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        return vn_math_process(Bin_Size, FirstBin, SecondBin, '-');
    }

    /* Variation Binizer: Binary process linker. */
    union Define_T vn_binizer(char *com, ...) {
        union Define_T Return;
        va_list args;

        if (!strcmp(com, "merge") || !strcmp(com, "split")) {
            va_start(args, com); /* Start arg */
            if (!strcmp(com, "merge")) { /* Merge two binary */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                struct Bin_T BinFirst = va_arg(args, struct Bin_T);
                struct Bin_T BinSecond = va_arg(args, struct Bin_T);

                Return.Bin = vn_merge_bin(Bin_Size, BinFirst, BinSecond);
                va_end(args); /* End arg */
                return Return; 
            } else if (!strcmp(com, "split")) { /* Separate a binary to two */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                struct Bin_T Bin = va_arg(args, struct Bin_T);
                char part = va_arg(args, int);

                Return.Bin = vn_split_bin(Bin_Size, Bin, part);
                va_end(args); /* End arg */
                return Return;
            }
        } else {
            va_start(args, com); /* Start arg */
            if (!strcmp(com, "set_sign") || !strcmp(com, "set_dot")) { /* Set bin sign and dot */
                struct Bin_T *Bin = va_arg(args, struct Bin_T*);
                enum Bin_E State = va_arg(args, enum Bin_E);

                if (!strcmp(com, "set_sign")) vn_set_sign_bin(Bin, State);
                if (!strcmp(com, "set_dot")) vn_set_dot_bin(Bin, State);
                va_end(args); /* End arg */
            } else if (!strcmp(com, "reverse")) { /* Reverse a binary */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                struct Bin_T Bin = va_arg(args, struct Bin_T);

                Return.Bin = vn_reverse_bin(Bin_Size, Bin);
                va_end(args); /* End arg */
                return Return;
            } else if (!strcmp(com, "int_to_bin")) { /* Integer to binary */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                int var = va_arg(args, int);

                Return.Bin = vn_int_to_bin(Bin_Size, var);
                va_end(args); /* End arg */
                return Return;
            } else if (!strcmp(com, "bin_to_int")) { /* Binary to integer */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                struct Bin_T Bin = va_arg(args, struct Bin_T);

                Return.Integer = vn_bin_to_int(Bin_Size, Bin);
                va_end(args); /* End arg */
                return Return;
            } else if (!strcmp(com, "double_to_bin")) { /* Double to binary */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                double var = va_arg(args, double);

                Return.Bin = vn_double_to_bin(Bin_Size, var);
                va_end(args); /* End arg */
                return Return;
            } else if (!strcmp(com, "bin_to_double")) { /* Binary to double */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                struct Bin_T Bin = va_arg(args, struct Bin_T);

                Return.Decimal = vn_bin_to_double(Bin_Size, Bin);
                va_end(args); /* End arg */
                return Return;
            } else if (!strcmp(com, "hex_to_bin")) { /* Hexadecimal to binary */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                char *var = va_arg(args, char*);

                Return.Bin = vn_hex_to_bin(Bin_Size, var);
                va_end(args); /* End arg */
                return Return;
            } else if (!strcmp(com, "bin_to_hex")) { /* Binary to hexadecimal */
                enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
                struct Bin_T Bin = va_arg(args, struct Bin_T);

                Return.Char = vn_bin_to_hex(Bin_Size, Bin);
                va_end(args); /* End arg */
                return Return;
            }
        }
    }

    /* Variation Bitizer: Bit manipulation process linker. */
    union Define_T vn_bitizer(char *com, ...) {
        union Define_T Return;
        va_list args;

        if (!strcmp(com, "get") || !strcmp(com, "toggle")) {
            va_start(args, com); /* Start arg */
            if (!strcmp(com, "get")) { /* Get bit */
                enum Bin_E State = va_arg(args, enum Bin_E);
                Return.Bit = vn_bit_get(State);

                va_end(args);  /* End arg */
                return Return;
            } else { /* Toggle bit */
                enum Bin_E *State = va_arg(args, enum Bin_E*);
                vn_bit_toggle(State);
                va_end(args);  /* End arg */
            }
        } else if (!strcmp(com, "set") || !strcmp(com, "clear") || !strcmp(com, "shift_left") || !strcmp(com, "shift_right")) {
            va_start(args, com);
            if (!strcmp(com, "set")) { /* Set bit */
                enum Bin_E *Bit = va_arg(args, enum Bin_E*);
                enum Bin_E State = va_arg(args, enum Bin_E);

                vn_bit_set(Bit, State);
                va_end(args);  /* End arg */
            } else { /* Clear, shift_left and shift_right bit */
                enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
                struct Bin_T *Bin = va_arg(args, struct Bin_T*);

                if (!strcmp(com, "clear")) vn_bit_clear(Bin_Size, Bin);
                else if (!strcmp(com, "shift_left")) vn_bit_shift_left(Bin_Size, Bin);
                else if (!strcmp(com, "shift_right")) vn_bit_shift_right(Bin_Size, Bin);
                va_end(args); /* End arg */
            }
        } else if (!strcmp(com, "clean_range")) { /* Clear bits in range */
            va_start(args, com); /* Start arg */
            enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
            struct Bin_T *Bin = va_arg(args, struct Bin_T*);

            int start_pos = va_arg(args, int);
            int end_pos = va_arg(args, int);

            vn_bit_clean_range(Bin_Size, Bin, start_pos, end_pos);
            va_end(args); /* End arg */
        } else if (!strcmp(com, "get_range")) { /* Get bits in a range */
            va_start(args, com); /* Start arg */
            enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
            enum Bin_S Range_Size = va_arg(args, enum Bin_S);
            struct Bin_T Bin = va_arg(args, struct Bin_T);

            int start_pos = va_arg(args, int);
            int end_pos = va_arg(args, int);

            Return.Bin = vn_bit_get_range(Bin_Size, Range_Size, Bin, start_pos, end_pos);
            va_end(args); /* End arg */
            return Return;
        }
    }

    /* Variation Logicizer: Logic gate linker. */
    struct Bin_T vn_logicizer(char *com, ...) {
        struct Bin_T Bin;
        va_list args;

        if (!strcmp(com, "not")) { /* Not gate */
            va_start(args, com); /* Start arg */
            enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
            struct Bin_T Bin = va_arg(args, struct Bin_T);
            Bin = vn_not(Bin_Size, Bin);
        
            va_end(args); /* End arg */
            return Bin;
        } else { /* And, or, nand, nor, xor and xnor gates */
            va_start(args, com); /* Start arg */
            enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
            struct Bin_T FirstBin = va_arg(args, struct Bin_T);
            struct Bin_T SecondBin = va_arg(args, struct Bin_T);

            if (!strcmp(com, "and")) Bin = vn_and(Bin_Size, FirstBin, SecondBin);
            else if (!strcmp(com, "or")) Bin = vn_or(Bin_Size, FirstBin, SecondBin);
            else if (!strcmp(com, "nand")) Bin = vn_nand(Bin_Size, FirstBin, SecondBin);
            else if (!strcmp(com, "nor")) Bin = vn_nor(Bin_Size, FirstBin, SecondBin);
            else if (!strcmp(com, "xor")) Bin =  vn_xor(Bin_Size, FirstBin, SecondBin);
            else if (!strcmp(com, "xnor")) Bin = vn_xnor(Bin_Size, FirstBin, SecondBin);

            va_end(args); /* End arg */
            return Bin;
        }
    }

    /* Variation Mathizer: Mathematical operations linker. */
    union Define_T vn_mathizer(char *com, ...) {
        union Define_T Return;
        va_list args;

        if (!strcmp(com, "half_adder") || !strcmp(com, "half_subtractor")) { /* Half math */
            va_start(args, com); /* Start arg */
            enum Bin_S A = va_arg(args, enum Bin_S);
            enum Bin_S B = va_arg(args, enum Bin_S);

            if (!strcmp(com, "half_adder")) Return.Math = vn_half_adder(A, B);
            else if (!strcmp(com, "half_subtractor")) Return.Math = vn_half_subtractor(A, B);

            va_end(args); /* End arg */
            return Return;
        } else {
            va_start(args, com); /* Start arg */
            if (!strcmp(com, "full_adder") || !strcmp(com, "full_subtractor")) { /* Full math */
                enum Bin_S A = va_arg(args, enum Bin_S);
                enum Bin_S B = va_arg(args, enum Bin_S);
                enum Bin_S C = va_arg(args, enum Bin_S);

                if (!strcmp(com, "full_adder")) Return.Math = vn_full_adder(A, B, C);
                else if (!strcmp(com, "full_subtractor")) Return.Math = vn_full_subtractor(A, B, C);

                va_end(args); /* End arg */
                return Return;
            } else if (!strcmp(com, "add") || !strcmp(com, "sub")) { /* Addition and subtraction math */
                enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
                struct Bin_T FirstBin = va_arg(args, struct Bin_T);
                struct Bin_T SecondBin = va_arg(args, struct Bin_T);
            
                if (!strcmp(com, "add")) Return.Bin = vn_add(Bin_Size, FirstBin, SecondBin);
                else if (!strcmp(com, "sub")) Return.Bin = vn_sub(Bin_Size, FirstBin, SecondBin);

                va_end(args); /* End arg */
                return Return;
            }
        }
    }
#endif /* VN_UI_IMPLEMENTATION */
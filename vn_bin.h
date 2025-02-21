/* VARIATION BINARY (LIBRARY) */
/*     MADE BY @hanilr     */
#ifndef _VN_BIN_H
#define _VN_BIN_H
    enum Bin_E { // Binary type declaration
        LOW = 0,    // When bit is logical zero
        HIGH = 1    // When bit is logical one
    };

    enum Bin_S { // Binary size selection type
        S_Bin4 = 4,     // 4 bit
        S_Bin8 = 8,     // 8 bit      
        S_Bin16 = 16,   // 16 bit 
        S_Bin32 = 32,   // 32 bit 
        S_Bin64 = 64,   // 64 bit
        S_Bin128 = 128  // 128 bit
    };

    enum Hex_S { // Hexadecimal size selection type
        S_Hex2 = 2, // 8 bit
        S_Hex4 = 4, // 16 bit
        S_Hex8 = 8, // 32 bit
        S_Hex16 = 16 // 64 bit
    };

    union Bin_U { // Data size selection part
        enum Bin_E Bit4_T[3];       // 8 bit (1 byte)
        enum Bin_E Bit8_T[7];       // 8 bit (1 byte)
        enum Bin_E Bit16_T[15];     // 16 bit (2 byte)
        enum Bin_E Bit32_T[31];     // 32 bit (4 byte)
        enum Bin_E Bit64_T[63];     // 64 bit (8 byte)
        enum Bin_E Bit128_T[127];   // 128 bit (16 byte)
    };

    struct Bin_T { // Binary type
        union Bin_U bit_type;   // Bit type for 8, 16, 32 and 64
        enum Bin_E bit_sign;    // Singed type declaration for `-` or `+`
        enum Bin_E bit_dot;     // If high then split bits to half and last half is decimal
    };

    union Bin_Math { // Binary math declaration
        enum Bin_E Sum;     // Addition result
        enum Bin_E Carry;   // Addition mod
        enum Bin_E Dif;     // Subtraction result
        enum Bin_E Borrow;  // Subtraction mod
    };

    struct Bin_M { // Math type
        union Bin_Math math_type_first;     // If this sum or dif
        union Bin_Math math_type_second;    // Than this carry or borrow
    }; // Because of union type need to make two variable

    /* SET BIT SIGN TO HIGH OR LOW */
    void vn_set_sign_bin(struct Bin_T *Bin, enum Bin_E State);

    /* SET BIT DOT TO HIGH OR LOW */
    void vn_set_dot_bin(struct Bin_T *Bin, enum Bin_E State);

    /* MERGE TWO BINARY TO NEW ONE */
    struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond);

    /* SEPARATE ONE BINARY TO NEW TWO */
    struct Bin_T vn_split_bin(enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part);

    /* MAKE REVERSE OF THE BINARY */
    struct Bin_T vn_reverse_bin(enum Bin_S Bin_Size, struct Bin_T BinInput);

    /* INTEGER TO BINARY CONVERSION */
    struct Bin_T vn_int_to_bin(enum Bin_S Bin_Size, int input);

    /* BINARY TO INTEGER CONVERSION */
    int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin);

    /* DOUBLE TO BINARY CONVERSION */
    struct Bin_T vn_double_to_bin(enum Bin_S Bin_Size, double input);

    /* BINARY TO DOUBLE CONVERSION */
    double vn_bin_to_double(enum Bin_S Bin_Size, struct Bin_T Bin);

    /* HEXADECIMAL TO BINARY CONVERSION */
    struct Bin_T vn_hex_to_bin(enum Hex_S Hex_Size, char *input);

    /* BINARY TO HEXADECIMAL CONVERSION*/
    char* vn_bin_to_hex(enum Bin_S Bin_Size, struct Bin_T InputBin);

    /* SET SPECIFIC BIT TO HIGH OR LOW */
    void vn_bit_set(enum Bin_E *Bit, enum Bin_E State);

    /* GET THE STATE OF BIT */
    enum Bin_E vn_bit_get(enum Bin_E Bit);

    /* TOGGLE SPECIFIC BIT TO REVERSE */
    void vn_bit_toggle(enum Bin_E *Bit);

    /* CLEAN BITS IN A RANGE */
    void vn_bit_clean_range(enum Bin_S Bin_Size, struct Bin_T *Bin, int start_pos, int end_pos);

    /* CLEAR ALL BITS IN BINARY */
    void vn_bit_clear(enum Bin_S Bin_Size, struct Bin_T *Bin);

    /* GET THE STATES OF BITS IN A RANGE */
    struct Bin_T vn_bit_get_range(enum Bin_S Bin_Size, enum Bin_S Range_Size, struct Bin_T InputBin, int start_pos, int end_pos);

    /* SHIFT THE BIT TO LEFT */
    void vn_bit_shift_left(enum Bin_S Bin_Size, struct Bin_T *Bin);

    /* SHIFT THE BIT TO RIGHT */
    void vn_bit_shift_right(enum Bin_S Bin_Size, struct Bin_T *Bin);

    /* AND GATE FOR BINARY */
    struct Bin_T vn_and(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

    /* OR GATE FOR BINARY */
    struct Bin_T vn_or(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

    /* NOT GATE FOR BINARY */
    struct Bin_T vn_not(enum Bin_S Bin_Size, struct Bin_T FirstBin);

    /* NAND GATE FOR BINARY */
    struct Bin_T vn_nand(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

    /* NOR GATE FOR BINARY */
    struct Bin_T vn_nor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

    /* XOR GATE FOR BINARY */
    struct Bin_T vn_xor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

    /* XNOR GATE FOR BINARY */
    struct Bin_T vn_xnor(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin);

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
#endif /* SUMMARY SECTION */

#ifdef VN_BIN_IMPLEMENTATION
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void vn_set_sign_bin(struct Bin_T *Bin, enum Bin_E State) {
        Bin->bit_sign = State; // Set sign bit as 'State'
    }
    
    void vn_set_dot_bin(struct Bin_T *Bin, enum Bin_E State) {
        Bin->bit_dot = State; // Set dot bit as 'State
    }
    
    struct Bin_T vn_merge_bin(enum Bin_S Bin_Size, struct Bin_T BinFirst, struct Bin_T BinSecond) {
        struct Bin_T Bin;
        enum Bin_S Size;
        // Binary type size increase process
        if (Bin_Size == 4) Size = 8;
        else if (Bin_Size == 8) Size = 16;
        else if (Bin_Size == 16) Size = 32;
        else if (Bin_Size == 32) Size = 64;
        else if (Bin_Size == 64) Size = 128;
    
        int i = 0;
        while (i != Bin_Size) { // Assignment
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
    
        // Dot check
        if (BinFirst.bit_dot == HIGH || BinSecond.bit_dot == HIGH) Bin.bit_dot = HIGH;
        else Bin.bit_dot = LOW;
    
        // Sign check
        if (BinFirst.bit_sign == HIGH || BinSecond.bit_sign == HIGH) Bin.bit_sign = HIGH;
        else Bin.bit_sign = LOW;
    
        return Bin;
    } // Max supported bit 64 for merge
    
    struct Bin_T vn_split_bin(enum Bin_S Bin_Size, struct Bin_T BinInput, char which_part) {
        struct Bin_T Bin[2];
        enum Bin_S Size;
        // Binary type size decrease process
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
        while (i != Size) { // Assignment
            if (Size == 4) Bin[part_sel].bit_type.Bit4_T[i] = BinInput.bit_type.Bit8_T[section_sel + i];
            else if (Size == 8) Bin[part_sel].bit_type.Bit8_T[i] = BinInput.bit_type.Bit16_T[section_sel + i];
            else if (Size == 16) Bin[part_sel].bit_type.Bit16_T[i] = BinInput.bit_type.Bit32_T[section_sel + i];
            else if (Size == 32) Bin[part_sel].bit_type.Bit32_T[i] = BinInput.bit_type.Bit64_T[section_sel + i];
            else if (Size == 64) Bin[part_sel].bit_type.Bit64_T[i] = BinInput.bit_type.Bit128_T[section_sel + i];
            i += 1;
        }
    
        // Bit sign and bit dot assignment
        Bin[part_sel].bit_sign = BinInput.bit_sign;
        Bin[part_sel].bit_dot = BinInput.bit_dot;
        return Bin[part_sel];
    } // Min supported bit 8 for split
    
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
    
        while (1) { // Conversion
            if (input % 2 != 0) cInt[i] = 1;
            input /= 2;
            i += 1;
            if (i == 128) break;
        } i = 0;
    
        while (i != Bin_Size || n >= 0) { // Assignment
            if (Bin_Size == 4) Bin.bit_type.Bit4_T[i] = cInt[n];
            else if (Bin_Size == 8) Bin.bit_type.Bit8_T[i] = cInt[n];
            else if (Bin_Size == 16) Bin.bit_type.Bit16_T[i] = cInt[n];
            else if (Bin_Size == 32) Bin.bit_type.Bit32_T[i] = cInt[n];
            else if (Bin_Size == 64) Bin.bit_type.Bit64_T[i] = cInt[n];
            else if (Bin_Size == 128) Bin.bit_type.Bit128_T[i] = cInt[n];
            i += 1;
            n -= 1;
        }
        // Sign bit process
        if (input < 0) Bin.bit_sign = HIGH; 
        else Bin.bit_sign = LOW;
        Bin.bit_dot = LOW; // Set 'LOW' as default
    
        return Bin;
    }
    
    int vn_bin_to_int(enum Bin_S Bin_Size, struct Bin_T Bin) {
        int result = 0, cInt[128] = {0}, i = 0, n = Bin_Size-1;
    
        while (i != Bin_Size || n >= 0) { // Assignment
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
        while (i != Bin_Size) { // Solution
            result += cInt[i] * n;
            i += 1;
            n *= 2;
        }
    
        if (Bin.bit_sign == HIGH) result *= -1;
        return result;
    }
    
    struct Bin_T vn_double_to_bin(enum Bin_S Bin_Size, double input) {
        struct Bin_T Bin[2];
    
        int part_int = (int)input; // Integer part
        double dec = input - part_int;
        int part_dec = (int)(dec * 1000000);
        
        int i = 0;
        while (i != 6) {
            if (part_dec % 10 == 0) part_dec /= 10;
            else break;
            i += 1;
        } 
    
        Bin[1] = vn_int_to_bin(Bin_Size, part_int);
        Bin[2] = vn_int_to_bin(Bin_Size, part_dec);
    
        Bin[0] = vn_merge_bin(Bin_Size, Bin[1], Bin[2]);
        Bin[0].bit_dot = HIGH; // Set the bit is double
        // Sign bit process
        if (input < 0) Bin[0].bit_sign = HIGH;
        else Bin[0].bit_sign = LOW;
    
        return Bin[0];
    } // Double type limited to max 64 bit because of merge function
    
    double vn_bin_to_double(enum Bin_S Bin_Size, struct Bin_T Bin) {
        enum Bin_E B_Sign = Bin.bit_sign;
        Bin.bit_sign = LOW;
    
        // Seperation
        struct Bin_T BinInt = vn_split_bin(Bin_Size, Bin, 'f');
        struct Bin_T BinDec = vn_split_bin(Bin_Size, Bin, 's');
        // Specification
        int part_int = vn_bin_to_int(Bin_Size/2, BinInt);
        int part_dec = vn_bin_to_int(Bin_Size/2, BinDec);
    
        if (part_dec == 0) return part_int;
        double dec = (double)part_dec, result;
    
        int i = 0;
        while (part_dec > 0) {
            part_dec /= 10;
            i += 1;
        } // Find digit
    
        while (i > 0) {
            dec /= 10;
            i -= 1;
        } // Find decimal part
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
    
        while (i != input_len) { // Data conversion
            if (input[i] >= '0' && input[i] <= '9') cInt[i] = input[i] - '0';
            else if (input[i] >= 'a' && input[i] <= 'f') cInt[i] = 10 + (input[i] - 'a');
            i += 1;
        } i = 0;
    
        while (i != input_len) { // Type conversion
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
        while (i != Hex_Size) { // Seperation
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
        
        while (i != Hex_Size) { // Type conversion
            cInt[i] = vn_bin_to_int(4, Bin[i]);
            i += 1;
        } i = 0;
    
        while (i != Hex_Size) { // Data conversion
            if (cInt[i] >= 0 && cInt[i] <= 9) result[i] = cInt[i] + '0';
            else if (cInt[i] >= 10 && cInt[i] <= 15) result[i] = (cInt[i] - 10 ) + 'a';
            i += 1;
        }
    
        result[Hex_Size] = '\0';
        return result;
    }

    void vn_bit_set(enum Bin_E *Bit, enum Bin_E State) {
        *Bit = State; // Set to 'State'
    }
    
    enum Bin_E vn_bit_get(enum Bin_E Bit) {
        return Bit == 0 ? LOW : HIGH; // Simple value return
    }
    
    void vn_bit_toggle(enum Bin_E *Bit) {
        if (*Bit == 0) *Bit = HIGH;
        else *Bit = LOW;
    }
    
    void vn_bit_clean_range(enum Bin_S Bin_Size, struct Bin_T *Bin, int start_pos, int end_pos) {
        int i = start_pos;
    
        while (i != end_pos + 1) { // Assignment
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
        vn_bit_clean_range(Bin_Size, Bin, 0, Bin_Size); // Clear in range, start is '0' and end is its size
    }
    
    struct Bin_T vn_bit_get_range(enum Bin_S Bin_Size, enum Bin_S Range_Size, struct Bin_T InputBin, int start_pos, int end_pos) {
        struct Bin_T Bin = {0};
        int i = 0;
    
        while (i != Range_Size || i != end_pos - start_pos) { // Assignment
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
    
        Bin.bit_dot = InputBin.bit_dot;
        Bin.bit_sign = InputBin.bit_sign;
    
        return Bin;
    }
    
    void vn_bit_shift_left(enum Bin_S Bin_Size, struct Bin_T *Bin) {
        int i = 0;
    
        while (1) { // Assignment
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
    
        while (1) { // Assignment
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

    struct Bin_T vn_logic(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin, char logic_op) {
        struct Bin_T ResultBin;
        int i = 0;

        while (1) { // Assignment
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
        return vn_logic(Bin_Size, FirstBin, SecondBin, '&');
    }

    struct Bin_T vn_or(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        return vn_logic(Bin_Size, FirstBin, SecondBin, '|');
    }

    struct Bin_T vn_not(enum Bin_S Bin_Size, struct Bin_T FirstBin) {
        return vn_logic(Bin_Size, FirstBin, FirstBin, '~');
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
        return vn_logic(Bin_Size, FirstBin, SecondBin, '^');
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
    
    struct Bin_T vn_math(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin, char math_op) {
        struct Bin_T Result = {0};
        struct Bin_M OP = {0};
    
        int i = Bin_Size - 1;
        while (1) { // Assignment
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
        return vn_math(Bin_Size, FirstBin, SecondBin, '+');
    }
    
    struct Bin_T vn_sub(enum Bin_S Bin_Size, struct Bin_T FirstBin, struct Bin_T SecondBin) {
        return vn_math(Bin_Size, FirstBin, SecondBin, '-');
    }
#endif /* VN_UI_IMPLEMENTATION */
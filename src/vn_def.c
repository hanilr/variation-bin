/* VARIATION BINARY (DEFINATION) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/* DIY LIBRARY */
#include "lib/vn_base.h"
#include "lib/vn_util.h"
#include "lib/vn_conv.h"
#include "lib/vn_manip.h"
#include "lib/vn_logic.h"
#include "lib/vn_math.h"
#include "lib/vn_def.h"

/* Variation Binizer: Binary process linker. */
union Define_T vn_binizer(char *com, ...) {
    union Define_T Return;
    va_list args;

    if (!strcmp(com, "merge") || !strcmp(com, "split")) {
        va_start(args, com); // Start arg
        if (!strcmp(com, "merge")) { // Merge two binary
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            struct Bin_T BinFirst = va_arg(args, struct Bin_T);
            struct Bin_T BinSecond = va_arg(args, struct Bin_T);

            Return.Bin = vn_merge_bin(Bin_Size, BinFirst, BinSecond);
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "split")) { // Separate a binary to two
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            struct Bin_T Bin = va_arg(args, struct Bin_T);
            char part = va_arg(args, int);

            Return.Bin = vn_split_bin(Bin_Size, Bin, part);
            va_end(args); // End arg
            return Return;
        }
    } else {
        va_start(args, com); // Start arg
        if (!strcmp(com, "set_sign") || !strcmp(com, "set_dot")) { // Set bin sign and dot
            struct Bin_T *Bin = va_arg(args, struct Bin_T*);
            enum Bin_E State = va_arg(args, enum Bin_E);

            if (!strcmp(com, "set_sign")) vn_set_sign_bin(Bin, State);
            if (!strcmp(com, "set_dot")) vn_set_dot_bin(Bin, State);
            va_end(args); // End arg
        } else if (!strcmp(com, "reverse")) { // Reverse a binary
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            struct Bin_T Bin = va_arg(args, struct Bin_T);

            Return.Bin = vn_reverse_bin(Bin_Size, Bin);
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "int_to_bin")) { // Integer to binary
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            int var = va_arg(args, int);

            Return.Bin = vn_int_to_bin(Bin_Size, var);
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "bin_to_int")) { // Binary to integer
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            struct Bin_T Bin = va_arg(args, struct Bin_T);

            Return.Integer = vn_bin_to_int(Bin_Size, Bin);
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "double_to_bin")) { // Double to binary
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            double var = va_arg(args, double);

            Return.Bin = vn_double_to_bin(Bin_Size, var);
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "bin_to_double")) { // Binary to double
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            struct Bin_T Bin = va_arg(args, struct Bin_T);

            Return.Decimal = vn_bin_to_double(Bin_Size, Bin);
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "hex_to_bin")) { // Hexadecimal to binary
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            char *var = va_arg(args, char*);

            Return.Bin = vn_hex_to_bin(Bin_Size, var);
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "bin_to_hex")) { // Binary to hexadecimal
            enum Bin_E Bin_Size = va_arg(args, enum Bin_E);
            struct Bin_T Bin = va_arg(args, struct Bin_T);

            Return.Char = vn_bin_to_hex(Bin_Size, Bin);
            va_end(args); // End arg
            return Return;
        }
    }
}

/* Variation Bitizer: Bit manipulation process linker. */
union Define_T vn_bitizer(char *com, ...) {
    union Define_T Return;
    va_list args;

    if (!strcmp(com, "get") || !strcmp(com, "toggle")) {
        va_start(args, com); // Start arg
        if (!strcmp(com, "get")) { // Get bit
            enum Bin_E State = va_arg(args, enum Bin_E);
            Return.Bit = vn_bit_get(State);

            va_end(args);  // End arg
            return Return;
        } else { // Toggle bit
            enum Bin_E *State = va_arg(args, enum Bin_E*);
            vn_bit_toggle(State);
            va_end(args);  // End arg
        }
    } else if (!strcmp(com, "set") || !strcmp(com, "clear") || !strcmp(com, "shift_left") || !strcmp(com, "shift_right")) {
        va_start(args, com);
        if (!strcmp(com, "set")) { // Set bit
            enum Bin_E *Bit = va_arg(args, enum Bin_E*);
            enum Bin_E State = va_arg(args, enum Bin_E);

            vn_bit_set(Bit, State);
            va_end(args);  // End arg
        } else { // Clear, shift_left and shift_right bit
            enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
            struct Bin_T *Bin = va_arg(args, struct Bin_T*);
            
            if (!strcmp(com, "clear")) vn_bit_clear(Bin_Size, Bin);
            else if (!strcmp(com, "shift_left")) vn_bit_shift_left(Bin_Size, Bin);
            else if (!strcmp(com, "shift_right")) vn_bit_shift_right(Bin_Size, Bin);
            va_end(args); // End arg
        }
    } else if (!strcmp(com, "clean_range")) { // Clear bits in range
        va_start(args, com); // Start arg
        enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
        struct Bin_T *Bin = va_arg(args, struct Bin_T*);

        int start_pos = va_arg(args, int);
        int end_pos = va_arg(args, int);

        vn_bit_clean_range(Bin_Size, Bin, start_pos, end_pos);
        va_end(args); // End arg
    } else if (!strcmp(com, "get_range")) { // Get bits in a range
        va_start(args, com); // Start arg
        enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
        enum Bin_S Range_Size = va_arg(args, enum Bin_S);
        struct Bin_T Bin = va_arg(args, struct Bin_T);

        int start_pos = va_arg(args, int);
        int end_pos = va_arg(args, int);

        Return.Bin = vn_bit_get_range(Bin_Size, Range_Size, Bin, start_pos, end_pos);
        va_end(args); // End arg
        return Return;
    }
}

/* Variation Logicizer: Logic gate linker. */
struct Bin_T vn_logicizer(char *com, ...) {
    struct Bin_T Bin;
    va_list args;
    
    if (!strcmp(com, "not")) { // Not gate
        va_start(args, com); // Start arg
        enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
        struct Bin_T Bin = va_arg(args, struct Bin_T);
        Bin = vn_not(Bin_Size, Bin);
    
        va_end(args); // End arg
        return Bin;
    } else { // And, or, nand, nor, xor and xnor gates
        va_start(args, com); // Start arg
        enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
        struct Bin_T FirstBin = va_arg(args, struct Bin_T);
        struct Bin_T SecondBin = va_arg(args, struct Bin_T);

        if (!strcmp(com, "and")) Bin = vn_and(Bin_Size, FirstBin, SecondBin);
        else if (!strcmp(com, "or")) Bin = vn_or(Bin_Size, FirstBin, SecondBin);
        else if (!strcmp(com, "nand")) Bin = vn_nand(Bin_Size, FirstBin, SecondBin);
        else if (!strcmp(com, "nor")) Bin = vn_nor(Bin_Size, FirstBin, SecondBin);
        else if (!strcmp(com, "xor")) Bin =  vn_xor(Bin_Size, FirstBin, SecondBin);
        else if (!strcmp(com, "xnor")) Bin = vn_xnor(Bin_Size, FirstBin, SecondBin);

        va_end(args); // End arg
        return Bin;
    }
}

/* Variation Mathizer: Mathematical operations linker. */
union Define_T vn_mathizer(char *com, ...) {
    union Define_T Return;
    va_list args;

    if (!strcmp(com, "half_adder") || !strcmp(com, "half_subtractor")) { // Half math
        va_start(args, com); // Start arg
        enum Bin_S A = va_arg(args, enum Bin_S);
        enum Bin_S B = va_arg(args, enum Bin_S);

        if (!strcmp(com, "half_adder")) Return.Math = vn_half_adder(A, B);
        else if (!strcmp(com, "half_subtractor")) Return.Math = vn_half_subtractor(A, B);

        va_end(args); // End arg
        return Return;
    } else {
        va_start(args, com); // Start arg
        if (!strcmp(com, "full_adder") || !strcmp(com, "full_subtractor")) { // Full math
            enum Bin_S A = va_arg(args, enum Bin_S);
            enum Bin_S B = va_arg(args, enum Bin_S);
            enum Bin_S C = va_arg(args, enum Bin_S);
            
            if (!strcmp(com, "full_adder")) Return.Math = vn_full_adder(A, B, C);
            else if (!strcmp(com, "full_subtractor")) Return.Math = vn_full_subtractor(A, B, C);
            
            va_end(args); // End arg
            return Return;
        } else if (!strcmp(com, "add") || !strcmp(com, "sub")) { // Addition and subtraction math
            enum Bin_S Bin_Size = va_arg(args, enum Bin_S);
            struct Bin_T FirstBin = va_arg(args, struct Bin_T);
            struct Bin_T SecondBin = va_arg(args, struct Bin_T);
        
            if (!strcmp(com, "add")) Return.Bin = vn_add(Bin_Size, FirstBin, SecondBin);
            else if (!strcmp(com, "sub")) Return.Bin = vn_sub(Bin_Size, FirstBin, SecondBin);

            va_end(args); // End arg
            return Return;
        }
    }
}

/* MADE BY @hanilr */
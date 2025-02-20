# General Variables #
CC = gcc
all_folder = all/

# Library and Source Code Destination #
util = ../src/vn_util.c
conv = ../src/vn_conv.c
manip = ../src/vn_manip.c
logic = ../src/vn_logic.c
math = ../src/vn_math.c
lib = $(util) $(conv) $(manip) $(logic) $(math)

# Input Names #
bin_merge_in = bin_merge/main.c
bin_split_in = bin_split/main.c
bin_to_double_in = bin_to_double/main.c
bin_to_int_in = bin_to_int/main.c
double_to_bin_in = double_to_bin/main.c
int_to_bin_in = int_to_bin/main.c
bit_set_in = bit_set/main.c
bit_get_in = bit_get/main.c
bit_toggle_in = bit_toggle/main.c
bit_clear_in = bit_clear/main.c
bit_get_range_in = bit_get_range/main.c
bit_clean_range_in = bit_clean_range/main.c
bit_shift_left_in = bit_shift_left/main.c
bit_shift_right_in = bit_shift_right/main.c
bin_reverse_in = bin_reverse/main.c
bit_set_sign_in = bit_set_sign/main.c
bit_set_dot_in = bit_set_dot/main.c
gate_and_in = gate_and/main.c
gate_or_in = gate_or/main.c
gate_not_in = gate_not/main.c
gate_nand_in = gate_nand/main.c
gate_nor_in = gate_nor/main.c
gate_xor_in = gate_xor/main.c
gate_xnor_in = gate_xnor/main.c
math_half_adder_in = math_half_adder/main.c
math_full_adder_in = math_full_adder/main.c
math_half_subtractor_in = math_half_subtractor/main.c
math_full_subtractor_in = math_full_subtractor/main.c
math_add_in = math_add/main.c
math_sub_in = math_sub/main.c
hex_to_bin_in = hex_to_bin/main.c
bin_to_hex_in = bin_to_hex/main.c

# Output Names #
bin_merge_out = bin_merge
bin_split_out = bin_split
bin_to_double_out = bin_to_double
bin_to_int_out = bin_to_int
double_to_bin_out = double_to_bin
int_to_bin_out = int_to_bin
bit_set_out = bit_set
bit_get_out = bit_get
bit_toggle_out = bit_toggle
bit_clear_out = bit_clear
bit_get_range_out = bit_get_range
bit_clean_range_out = bit_clean_range
bit_shift_left_out = bit_shift_left
bit_shift_right_out = bit_shift_right
bin_reverse_out = bin_reverse
bit_set_sign_out = bit_set_sign
bit_set_dot_out = bit_set_dot
gate_and_out = gate_and
gate_or_out = gate_or
gate_not_out = gate_not
gate_nand_out = gate_nand
gate_nor_out = gate_nor
gate_xor_out = gate_xor
gate_xnor_out = gate_xnor
math_half_adder_out = math_half_adder
math_full_adder_out = math_full_adder
math_half_subtractor_out = math_half_subtractor
math_full_subtractor_out = math_full_subtractor
math_add_out = math_add
math_sub_out = math_sub
hex_to_bin_out = hex_to_bin
bin_to_hex_out = bin_to_hex

# Executable Names #
bin_merge_exe = ./bin_merge/main
bin_split_exe = ./bin_split/main
bin_to_double_exe = ./bin_to_double/main
bin_to_int_exe = ./bin_to_int/main
double_to_bin_exe = ./double_to_bin/main
int_to_bin_exe = ./int_to_bin/main
bit_set_exe = ./bit_set/main
bit_get_exe = ./bit_get/main
bit_toggle_exe = ./bit_toggle/main
bit_clear_exe = ./bit_clear/main
bit_get_range_exe = ./bit_get_range/main
bit_clean_range_exe = ./bit_clean_range/main
bit_shift_left_exe = ./bit_shift_left/main
bit_shift_right_exe = ./bit_shift_right/main
bin_reverse_exe = ./bin_reverse/main
bit_set_sign_exe = ./bit_set_sign/main
bit_set_dot_exe = ./bit_set_dot/main
gate_and_exe = ./gate_and/main
gate_or_exe = ./gate_or/main
gate_not_exe = ./gate_not/main
gate_nand_exe = ./gate_nand/main
gate_nor_exe = ./gate_nor/main
gate_xor_exe = ./gate_xor/main
gate_xnor_exe = ./gate_xnor/main
math_half_adder_exe = ./math_half_adder/main
math_full_adder_exe = ./math_full_adder/main
math_half_subtractor_exe = ./math_half_subtractor/main
math_full_subtractor_exe = ./math_full_subtractor/main
math_add_exe = ./math_add/main
math_sub_exe = ./math_sub/main
hex_to_bin_exe = ./hex_to_bin/main
bin_to_hex_exe = ./bin_to_hex/main

.PHONY: run clean all clean_all bin_merge bin_split bin_to_double bin_to_int double_to_bin int_to_bin bit_set bit_get bit_toggle bit_clear bit_get_range bit_clean_range bit_shift_left bit_shift_right bin_reverse bit_set_sign bit_set_dot gate_and gate_or gate_not gate_nand gate_nor gate_xor gate_xnor math_half_adder math_full_adder math_half_subtractor math_full_subtractor math_add math_sub hex_to_bin bin_to_hex

run: $(lib)
	@echo -n "\nCompiling: ["
	@mkdir -p $(all_folder)
	@echo -n "*"
	@$(CC) $(lib) $(bin_merge_in) -o $(all_folder)$(bin_merge_out)
	@echo -n "*"
	@$(CC) $(lib) $(bin_split_in) -o $(all_folder)$(bin_split_out)
	@echo -n "*"
	@$(CC) $(lib) $(bin_to_double_in) -o $(all_folder)$(bin_to_double_out)
	@echo -n "*"
	@$(CC) $(lib) $(bin_to_int_in) -o $(all_folder)$(bin_to_int_out)
	@echo -n "*"
	@$(CC) $(lib) $(double_to_bin_in) -o $(all_folder)$(double_to_bin_out)
	@echo -n "*"
	@$(CC) $(lib) $(int_to_bin_in) -o $(all_folder)$(int_to_bin_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_set_in) -o $(all_folder)$(bit_set_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_get_in) -o $(all_folder)$(bit_get_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_toggle_in) -o $(all_folder)$(bit_toggle_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_clear_in) -o $(all_folder)$(bit_clear_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_get_range_in) -o $(all_folder)$(bit_get_range_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_clean_range_in) -o $(all_folder)$(bit_clean_range_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_shift_left_in) -o $(all_folder)$(bit_shift_left_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_shift_right_in) -o $(all_folder)$(bit_shift_right_out)
	@echo -n "*"
	@$(CC) $(lib) $(bin_reverse_in) -o $(all_folder)$(bin_reverse_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_set_sign_in) -o $(all_folder)$(bit_set_sign_out)
	@echo -n "*"
	@$(CC) $(lib) $(bit_set_dot_in) -o $(all_folder)$(bit_set_dot_out)
	@echo -n "*"
	@$(CC) $(lib) $(gate_and_in) -o $(all_folder)$(gate_and_out)
	@echo -n "*"
	@$(CC) $(lib) $(gate_or_in) -o $(all_folder)$(gate_or_out)
	@echo -n "*"
	@$(CC) $(lib) $(gate_not_in) -o $(all_folder)$(gate_not_out)
	@echo -n "*"
	@$(CC) $(lib) $(gate_nand_in) -o $(all_folder)$(gate_nand_out)
	@echo -n "*"
	@$(CC) $(lib) $(gate_nor_in) -o $(all_folder)$(gate_nor_out)
	@echo -n "*"
	@$(CC) $(lib) $(gate_xor_in) -o $(all_folder)$(gate_xor_out)
	@echo -n "*"
	@$(CC) $(lib) $(gate_xnor_in) -o $(all_folder)$(gate_xnor_out)
	@echo -n "*"
	@$(CC) $(lib) $(math_half_adder_in) -o $(all_folder)$(math_half_adder_out)
	@echo -n "*"
	@$(CC) $(lib) $(math_full_adder_in) -o $(all_folder)$(math_full_adder_out)
	@echo -n "*"
	@$(CC) $(lib) $(math_half_subtractor_in) -o $(all_folder)$(math_half_subtractor_out)
	@echo -n "*"
	@$(CC) $(lib) $(math_full_subtractor_in) -o $(all_folder)$(math_full_subtractor_out)
	@echo -n "*"
	@$(CC) $(lib) $(math_add_in) -o $(all_folder)$(math_add_out)
	@echo -n "*"
	@$(CC) $(lib) $(math_sub_in) -o $(all_folder)$(math_sub_out)
	@echo -n "*"
	@$(CC) $(lib) $(hex_to_bin_in) -o $(all_folder)$(hex_to_bin_out)
	@echo -n "*"
	@$(CC) $(lib) $(bin_to_hex_in) -o $(all_folder)$(bin_to_hex_out)
	@echo "]\n"

clean: $(all_folder)
	@rm -rf $(all_folder)

all: 
	@echo -n "\nCompiling: ["
	@$(CC) $(lib) $(bin_merge_in) -o $(bin_merge_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bin_split_in) -o $(bin_split_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bin_to_double_in) -o $(bin_to_double_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bin_to_int_in) -o $(bin_to_int_exe)
	@echo -n "*"
	@$(CC) $(lib) $(double_to_bin_in) -o $(double_to_bin_exe)
	@echo -n "*"
	@$(CC) $(lib) $(int_to_bin_in) -o $(int_to_bin_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_set_in) -o $(bit_set_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_get_in) -o $(bit_get_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_toggle_in) -o $(bit_toggle_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_clear_in) -o $(bit_clear_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_get_range_in) -o $(bit_get_range_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_clean_range_in) -o $(bit_clean_range_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_shift_left_in) -o $(bit_shift_left_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_shift_right_in) -o $(bit_shift_right_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bin_reverse_in) -o $(bin_reverse_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_set_sign_in) -o $(bit_set_sign_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bit_set_dot_in) -o $(bit_set_dot_exe)
	@echo -n "*"
	@$(CC) $(lib) $(gate_and_in) -o $(gate_and_exe)
	@echo -n "*"
	@$(CC) $(lib) $(gate_or_in) -o $(gate_or_exe)
	@echo -n "*"
	@$(CC) $(lib) $(gate_not_in) -o $(gate_not_exe)
	@echo -n "*"
	@$(CC) $(lib) $(gate_nand_in) -o $(gate_nand_exe)
	@echo -n "*"
	@$(CC) $(lib) $(gate_nor_in) -o $(gate_nor_exe)
	@echo -n "*"
	@$(CC) $(lib) $(gate_xor_in) -o $(gate_xor_exe)
	@echo -n "*"
	@$(CC) $(lib) $(gate_xnor_in) -o $(gate_xnor_exe)
	@echo -n "*"
	@$(CC) $(lib) $(math_half_adder_in) -o $(math_half_adder_exe)
	@echo -n "*"
	@$(CC) $(lib) $(math_full_adder_in) -o $(math_full_adder_exe)
	@echo -n "*"
	@$(CC) $(lib) $(math_half_subtractor_in) -o $(math_half_subtractor_exe)
	@echo -n "*"
	@$(CC) $(lib) $(math_full_subtractor_in) -o $(math_full_subtractor_exe)
	@echo -n "*"
	@$(CC) $(lib) $(math_add_in) -o $(math_add_exe)
	@echo -n "*"
	@$(CC) $(lib) $(math_sub_in) -o $(math_sub_exe)
	@echo -n "*"
	@$(CC) $(lib) $(hex_to_bin_in) -o $(hex_to_bin_exe)
	@echo -n "*"
	@$(CC) $(lib) $(bin_to_hex_in) -o $(bin_to_hex_exe)
	@echo "]\n"

clean_all:
	@rm -f $(bin_merge_exe)
	@rm -f $(bin_split_exe)
	@rm -f $(bin_to_double_exe)
	@rm -f $(bin_to_int_exe)
	@rm -f $(double_to_bin_exe)
	@rm -f $(int_to_bin_exe)
	@rm -f $(bit_set_exe)
	@rm -f $(bit_get_exe)
	@rm -f $(bit_toggle_exe)
	@rm -f $(bit_clear_exe)
	@rm -f $(bit_get_range_exe)
	@rm -f $(bit_clean_range_exe)
	@rm -f $(bit_shift_left_exe)
	@rm -f $(bit_shift_right_exe)
	@rm -f $(bin_reverse_exe)
	@rm -f $(bit_set_sign_exe)
	@rm -f $(bit_set_dot_exe)
	@rm -f $(gate_and_exe)
	@rm -f $(gate_or_exe)
	@rm -f $(gate_not_exe)
	@rm -f $(gate_nand_exe)
	@rm -f $(gate_nor_exe)
	@rm -f $(gate_xor_exe)
	@rm -f $(gate_xnor_exe)
	@rm -f $(math_half_adder_exe)
	@rm -f $(math_full_adder_exe)
	@rm -f $(math_half_subtractor_exe)
	@rm -f $(math_full_subtractor_exe)
	@rm -f $(math_add_exe)
	@rm -f $(math_sub_exe)
	@rm -f $(hex_to_bin_exe)
	@rm -f $(bin_to_hex_exe)

bin_merge: $(bin_merge_in)
	@$(CC) $(lib) $(bin_merge_in) -o $(bin_merge_exe)
	@$(bin_merge_exe)

bin_split: $(bin_split_in)
	@$(CC) $(lib) $(bin_split_in) -o $(bin_split_exe)
	@$(bin_split_exe)

bin_to_double: $(bin_to_double_in)
	@$(CC) $(lib) $(bin_to_double_in) -o $(bin_to_double_exe)
	@$(bin_to_double_exe)

bin_to_int: $(bin_to_int_in)
	@$(CC) $(lib) $(bin_to_int_in) -o $(bin_to_int_exe)
	@$(bin_to_int_exe)

double_to_bin: $(double_to_bin_in)
	@$(CC) $(lib) $(double_to_bin_in) -o $(double_to_bin_exe)
	@$(double_to_bin_exe)

int_to_bin: $(int_to_bin_in)
	@$(CC) $(lib) $(int_to_bin_in) -o $(int_to_bin_exe)
	@$(int_to_bin_exe)

bit_set: $(bit_set_in)
	@$(CC) $(lib) $(bit_set_in) -o $(bit_set_exe)
	@$(bit_set_exe)

bit_get: $(bit_get_in)
	@$(CC) $(lib) $(bit_get_in) -o $(bit_get_exe)
	@$(bit_get_exe)

bit_toggle: $(bit_toggle_in)
	@$(CC) $(lib) $(bit_toggle_in) -o $(bit_toggle_exe)
	@$(bit_toggle_exe)

bit_clear: $(bit_clear_in)
	@$(CC) $(lib) $(bit_clear_in) -o $(bit_clear_exe)
	@$(bit_clear_exe)

bit_get_range: $(bit_get_range_in)
	@$(CC) $(lib) $(bit_get_range_in) -o $(bit_get_range_exe)
	@$(bit_get_range_exe)

bit_clean_range: $(bit_clean_range_in)
	@$(CC) $(lib) $(bit_clean_range_in) -o $(bit_clean_range_exe)
	@$(bit_clean_range_exe)

bit_shift_left: $(bit_shift_left_in)
	@$(CC) $(lib) $(bit_shift_left_in) -o $(bit_shift_left_exe)
	@$(bit_shift_left_exe)

bit_shift_right: $(bit_shift_right_in)
	@$(CC) $(lib) $(bit_shift_right_in) -o $(bit_shift_right_exe)
	@$(bit_shift_right_exe)

bin_reverse: $(bin_reverse_in)
	@$(CC) $(lib) $(bin_reverse_in) -o $(bin_reverse_exe)
	@$(bin_reverse_exe)

bit_set_sign: $(bit_set_sign_in)
	@$(CC) $(lib) $(bit_set_sign_in) -o $(bit_set_sign_exe)
	@$(bit_set_sign_exe)

bit_set_dot: $(bit_set_dot_in)
	@$(CC) $(lib) $(bit_set_dot_in) -o $(bit_set_dot_exe)
	@$(bit_set_dot_exe)

gate_and: $(gate_and_in)
	@$(CC) $(lib) $(gate_and_in) -o $(gate_and_exe)
	@$(gate_and_exe)

gate_or: $(gate_or_in)
	@$(CC) $(lib) $(gate_or_in) -o $(gate_or_exe)
	@$(gate_or_exe)

gate_not: $(gate_not_in)
	@$(CC) $(lib) $(gate_not_in) -o $(gate_not_exe)
	@$(gate_not_exe)

gate_nand: $(gate_nand_in)
	@$(CC) $(lib) $(gate_nand_in) -o $(gate_nand_exe)
	@$(gate_nand_exe)

gate_nor: $(gate_nor_in)
	@$(CC) $(lib) $(gate_nor_in) -o $(gate_nor_exe)
	@$(gate_nor_exe)

gate_xor: $(gate_xor_in)
	@$(CC) $(lib) $(gate_xor_in) -o $(gate_xor_exe)
	@$(gate_xor_exe)

gate_xnor: $(gate_xnor_in)
	@$(CC) $(lib) $(gate_xnor_in) -o $(gate_xnor_exe)
	@$(gate_xnor_exe)

math_half_adder: $(math_half_adder_in)
	@$(CC) $(lib) $(math_half_adder_in) -o $(math_half_adder_exe)
	@$(math_half_adder_exe)

math_full_adder: $(math_full_adder_in)
	@$(CC) $(lib) $(math_full_adder_in) -o $(math_full_adder_exe)
	@$(math_full_adder_exe)

math_half_subtractor: $(math_half_subtractor_in)
	@$(CC) $(lib) $(math_half_subtractor_in) -o $(math_half_subtractor_exe)
	@$(math_half_subtractor_exe)

math_full_subtractor: $(math_full_subtractor_in)
	@$(CC) $(lib) $(math_full_subtractor_in) -o $(math_full_subtractor_exe)
	@$(math_full_subtractor_exe)

math_add: $(math_add_in)
	@$(CC) $(lib) $(math_add_in) -o $(math_add_exe)
	@$(math_add_exe)

math_sub: $(math_sub_in)
	@$(CC) $(lib) $(math_sub_in) -o $(math_sub_exe)
	@$(math_sub_exe)

hex_to_bin: $(hex_to_bin_in)
	@$(CC) $(lib) $(hex_to_bin_in) -o $(hex_to_bin_exe)
	@$(hex_to_bin_exe)

bin_to_hex: $(bin_to_hex_in)
	@$(CC) $(lib) $(bin_to_hex_in) -o $(bin_to_hex_exe)
	@$(bin_to_hex_exe)
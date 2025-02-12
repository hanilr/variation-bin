# General Variables #
CC = gcc
all_folder = all/

# Library and Source Code Destination #
util = ../src/vn_util.c
conv = ../src/vn_conv.c
manip = ../src/vn_manip.c
lib = $(util) $(conv) $(manip)

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

.PHONY: run clean all clean_all bin_merge bin_split bin_to_double bin_to_int double_to_bin int_to_bin bit_set bit_get bit_toggle bit_clear bit_get_range bit_clean_range bit_shift_left bit_shift_right bin_reverse bit_set_sign bit_set_dot

run: $(lib)
	@mkdir -p $(all_folder)
	@$(CC) $(lib) $(bin_merge_in) -o $(all_folder)$(bin_merge_out)
	@$(CC) $(lib) $(bin_split_in) -o $(all_folder)$(bin_split_out)
	@$(CC) $(lib) $(bin_to_double_in) -o $(all_folder)$(bin_to_double_out)
	@$(CC) $(lib) $(bin_to_int_in) -o $(all_folder)$(bin_to_int_out)
	@$(CC) $(lib) $(double_to_bin_in) -o $(all_folder)$(double_to_bin_out)
	@$(CC) $(lib) $(int_to_bin_in) -o $(all_folder)$(int_to_bin_out)
	@$(CC) $(lib) $(bit_set_in) -o $(all_folder)$(bit_set_out)
	@$(CC) $(lib) $(bit_get_in) -o $(all_folder)$(bit_get_out)
	@$(CC) $(lib) $(bit_toggle_in) -o $(all_folder)$(bit_toggle_out)
	@$(CC) $(lib) $(bit_clear_in) -o $(all_folder)$(bit_clear_out)
	@$(CC) $(lib) $(bit_get_range_in) -o $(all_folder)$(bit_get_range_out)
	@$(CC) $(lib) $(bit_clean_range_in) -o $(all_folder)$(bit_clean_range_out)
	@$(CC) $(lib) $(bit_shift_left_in) -o $(all_folder)$(bit_shift_left_out)
	@$(CC) $(lib) $(bit_shift_right_in) -o $(all_folder)$(bit_shift_right_out)
	@$(CC) $(lib) $(bin_reverse_in) -o $(all_folder)$(bin_reverse_out)
	@$(CC) $(lib) $(bit_set_sign_in) -o $(all_folder)$(bit_set_sign_out)
	@$(CC) $(lib) $(bit_set_dot_in) -o $(all_folder)$(bit_set_dot_out)

clean: $(all_folder)
	@rm -rf $(all_folder)

all: 
	@$(CC) $(lib) $(bin_merge_in) -o $(bin_merge_exe)
	@$(CC) $(lib) $(bin_split_in) -o $(bin_split_exe)
	@$(CC) $(lib) $(bin_to_double_in) -o $(bin_to_double_exe)
	@$(CC) $(lib) $(bin_to_int_in) -o $(bin_to_int_exe)
	@$(CC) $(lib) $(double_to_bin_in) -o $(double_to_bin_exe)
	@$(CC) $(lib) $(int_to_bin_in) -o $(int_to_bin_exe)
	@$(CC) $(lib) $(bit_set_in) -o $(bit_set_exe)
	@$(CC) $(lib) $(bit_get_in) -o $(bit_get_exe)
	@$(CC) $(lib) $(bit_toggle_in) -o $(bit_toggle_exe)
	@$(CC) $(lib) $(bit_clear_in) -o $(bit_clear_exe)
	@$(CC) $(lib) $(bit_get_range_in) -o $(bit_get_range_exe)
	@$(CC) $(lib) $(bit_clean_range_in) -o $(bit_clean_range_exe)
	@$(CC) $(lib) $(bit_shift_left_in) -o $(bit_shift_left_exe)
	@$(CC) $(lib) $(bit_shift_right_in) -o $(bit_shift_right_exe)
	@$(CC) $(lib) $(bin_reverse_in) -o $(bin_reverse_exe)
	@$(CC) $(lib) $(bit_set_sign_in) -o $(bit_set_sign_exe)
	@$(CC) $(lib) $(bit_set_dot_in) -o $(bit_set_dot_exe)

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
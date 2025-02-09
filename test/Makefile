# General Variables #
CC = gcc
all_folder = all/

# Library and Source Code Destination #
util = ../src/vn_util.c
conv = ../src/vn_conv.c
lib = $(util) $(conv)

# Input Names #
bin_merge_in = bin_merge/main.c
bin_split_in = bin_split/main.c
bin_to_double_in = bin_to_double/main.c
bin_to_int_in = bin_to_int/main.c
double_to_bin_in = double_to_bin/main.c
int_to_bin_in = int_to_bin/main.c

# Output Names #
bin_merge_out = bin_merge
bin_split_out = bin_split
bin_to_double_out = bin_to_double
bin_to_int_out = bin_to_int
double_to_bin_out = double_to_bin
int_to_bin_out = int_to_bin

# Executable Names #
bin_merge_exe = ./bin_merge/main
bin_split_exe = ./bin_split/main
bin_to_double_exe = ./bin_to_double/main
bin_to_int_exe = ./bin_to_int/main
double_to_bin_exe = ./double_to_bin/main
int_to_bin_exe = ./int_to_bin/main

.PHONY: run clean all clean_all bin_merge bin_split bin_to_double bin_to_int double_to_bin int_to_bin

run: $(lib)
	@mkdir -p $(all_folder)
	@$(CC) $(lib) $(bin_merge_in) -o $(all_folder)$(bin_merge_out)
	@$(CC) $(lib) $(bin_split_in) -o $(all_folder)$(bin_split_out)
	@$(CC) $(lib) $(bin_to_double_in) -o $(all_folder)$(bin_to_double_out)
	@$(CC) $(lib) $(bin_to_int_in) -o $(all_folder)$(bin_to_int_out)
	@$(CC) $(lib) $(double_to_bin_in) -o $(all_folder)$(double_to_bin_out)
	@$(CC) $(lib) $(int_to_bin_in) -o $(all_folder)$(int_to_bin_out)

clean: $(all_folder)
	@rm -rf $(all_folder)

all: 
	@$(CC) $(lib) $(bin_merge_in) -o $(bin_merge_exe)
	@$(CC) $(lib) $(bin_split_in) -o $(bin_split_exe)
	@$(CC) $(lib) $(bin_to_double_in) -o $(bin_to_double_exe)
	@$(CC) $(lib) $(bin_to_int_in) -o $(bin_to_int_exe)
	@$(CC) $(lib) $(double_to_bin_in) -o $(double_to_bin_exe)
	@$(CC) $(lib) $(int_to_bin_in) -o $(int_to_bin_exe)

clean_all:
	@rm -f $(bin_merge_exe)
	@rm -f $(bin_split_exe)
	@rm -f $(bin_to_double_exe)
	@rm -f $(bin_to_int_exe)
	@rm -f $(double_to_bin_exe)
	@rm -f $(int_to_bin_exe)

bin_merge: $(bin_merge_in)
	@$(CC) $(lib) $(bin_merge_in) -o $(bin_merge_exe)
	@$(bin_merge_exe)

bin_split: $(bin_split_in)
	@$(CC) $(lib) $(bin_split_in) -o $(bin_split_exe)
	@$(bin_split_exe)

bin_to_double: $(bin_to_double)
	@$(CC) $(lib) $(bin_to_double_in) -o $(bin_to_double_exe)
	@$(bin_to_double_exe)

bin_to_int: $(bin_to_int)
	@$(CC) $(lib) $(bin_to_int_in) -o $(bin_to_int_exe)
	@$(bin_to_int_exe)

double_to_bin: $(double_to_bin)
	@$(CC) $(lib) $(double_to_bin_in) -o $(double_to_bin_exe)
	@$(double_to_bin_exe)

int_to_bin: $(int_to_bin)
	@$(CC) $(lib) $(int_to_bin_in) -o $(int_to_bin_exe)
	@$(int_to_bin_exe)
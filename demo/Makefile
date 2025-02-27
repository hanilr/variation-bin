CC = gcc
STD = -std=c99
MAIN = demo.c
OUT = demo

.PHONY: run clean

run: $(MAIN)
	@$(CC) $(STD) $(MAIN) -o $(OUT)
	@./$(OUT)

clean: $(OUT)
	@rm -f $(OUT)
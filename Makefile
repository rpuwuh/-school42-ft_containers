CFLAGS = -Wall -Werror -Wextra -std=c++98

CC = c++

test: main.c Makefile
	$(CC) $(CFLAGS) main.c -o test

run:
	clear; make -s; ./test

.PHONY: run

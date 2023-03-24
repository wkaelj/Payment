UNAME = $(shell "uname -s")

CFLAGS := -std=c2x -Wall -Wextra -pedantic -fsanitize=address
LDFLAGS := -lm -fsanitize=address

SRC=$(wildcard src/*.c)
OBJ=$(SRC:%.c=%.o)

payment: $(OBJ)
	cc $^ $(CFLAGS) -o payment.out $(LDFLAGS)

%.o: %.c
	cc -c -o $@ $< $(CFLAGS)
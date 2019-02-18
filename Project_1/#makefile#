#makefile#

CC = gcc

CFLAGS = -Wall

source := main.c exit.c help.c

OBJ := $(source:.c=.o)

mem_util: $(OBJ)
	$(CC) -o mem_util $(OBJ) $(CFLAGS)

clean:
	rm -f *.o mem_util


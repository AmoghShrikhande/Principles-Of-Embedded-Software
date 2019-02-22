 #makefile#

CC = gcc

CFLAGS = -Wall

source := main.c exit.c help.c allocate_memory.c free_memory.c Allocated_memory_display.c Write_memory_words.c

OBJ := $(source:.c=.o)

mem_util: $(OBJ)
	$(CC) -o mem_util $(OBJ) $(CFLAGS)

clean:
	rm -f *.o mem_util

	
#makefile#

CC = gcc

CFLAGS = -Wall\
	 -Werror

source := main.c exit.c help.c allocate_memory.c free_memory.c Allocated_memory_display.c Write_memory_words.c Display_particular_address.c Write_particular_offset.c Invert_memory_block.c Write_pattern.c Verify_pattern.c

vpath %.h ../includes/

OBJ := $(source:.c=.o)

mem_util: $(OBJ)
	$(CC) -o mem_util $(OBJ) $(CFLAGS)

test: mem_util testfile
	./mem_util < testfile


clean:
	rm -f *.o mem_util

	

#makefile#

CC = gcc

CFLAGS = -Wall\
         -Werror

source := unittest.c circular_buffer.c

OBJ := $(source:.c=.o)

circular_buffer: $(OBJ)
	$(CC) -o circular_buffer $(OBJ) $(CFLAGS) -lcunit

clean:
	rm -f *.o circular_buffer


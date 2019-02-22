/*Allocated_memory_display*/

#include "Allocated_memory_display.h"

uint32_t no_of_bytes;
int *memory_start;
int j;

void allocated_memory_display (int a, int b)

{
       for (j=1; j<= no_of_bytes; j++)
{
printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
printf ("Data: 0x%x " , *(memory_start-1 +j));

}



}


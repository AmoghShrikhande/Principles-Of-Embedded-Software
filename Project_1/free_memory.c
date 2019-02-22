/* Free memory */

#include "free_memory.h"

//void *(memory_start);

int *memory_start;

void free_memory (int a, int b)
{
     free (memory_start);    
     printf("\n The allocated memory is now freed \n");   
     
}

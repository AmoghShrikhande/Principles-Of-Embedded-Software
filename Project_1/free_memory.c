/* Free memory */

#include "free_memory.h"
#include "allocate_memory.h"

//void *(memory_start);

int memory_allocation_flag;
int *memory_start;

void free_memory (int a, int b)
{


     if( memory_start != NULL )
{
     memory_allocation_flag = 1;
     free (memory_start);    
     printf("\n The allocated memory is now freed \n");   
}

else 
{
printf("\n You need to allocate memory before freeing it \n");
}
}

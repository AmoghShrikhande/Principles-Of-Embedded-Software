/* Free memory */

#include "../includes/free_memory.h"
#include "../includes/allocate_memory.h"

int memory_allocation_flag;
int *memory_start;

void free_memory (int a, int b)
 {
   if( memory_start != NULL && memory_allocation_flag == 0)
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

// Memory_alocate

    #include <malloc.h> 
    #include "allocate_memory.h"
int memory_allocation_flag;

//extern int memory_allocation_flag; 

//if(memory_allocation_flag == 1)
 
    void memory_allocate (int a, int b)
      { 
                //uint32_t no_of_bytes;
 extern uint32_t no_of_bytes;
                extern int *memory_start;
//int memory_allocation_flag;
               // memory_allocation_flag = 0;
if(memory_allocation_flag == 1)
{
                printf("\n Allocate the number of words required for your application: \n");
                
                printf("--> ");
                scanf("%d",&no_of_bytes);
              
               memory_start = (int*)malloc(no_of_bytes*sizeof(int));
               if ( memory_start == NULL )
                {
                  printf("\n Sorry failed to allocate memory \n");
                }
               else 
                {
                  printf("\n Success ! %d words of memory allocated successfully \n", no_of_bytes);
                }
memory_allocation_flag = 0;
}
else
{
printf("Warning! Please free the initial block of memory allocated");
}

      }




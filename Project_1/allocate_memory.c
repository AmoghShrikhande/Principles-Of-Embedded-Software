// Memory_alocate

#include <malloc.h> 
#include "allocate_memory.h"
int memory_allocation_flag;


void memory_allocate (int a, int b)
{ 
  int i;
  extern uint32_t no_of_bytes;
  extern int *memory_start;

     if(memory_allocation_flag == 1)
       {
          printf("\n Allocate the number of words required for your application: \n");
                
           for(i=0;i<=90;i++)               // To display organised GUI
            {
              printf("*");
            } 
           printf("\n");
           printf("\n ---> "); 
           scanf("%d",&no_of_bytes);
           for(i=0;i<=90;i++)               // To display organised GUI
            {
              printf("*");
            } 
                
           if(no_of_bytes>0)
            {
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
              printf("\nPlease enter the value between 1 and max memory limit\n");
            }

        }
     else
       {
          printf("\nWarning! Please free the initial block of memory allocated\n");
       }
}




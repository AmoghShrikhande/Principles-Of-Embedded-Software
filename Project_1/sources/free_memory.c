/*File Name & Description : free_memory.c, This file allows the user to free the allocated memory
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No code leveraged in this file
 Applicable Links: No links */

#include "../includes/free_memory.h"
#include "../includes/allocate_memory.h"

int memory_allocation_flag;
int *memory_start;

/*******************************************************************************
* Function Name: free_memory 
********************************************************************************
*
* Summary:
*  Frees the allocated memory for further memory allocation
*
* Parameters:
*  integer
*
* Return:
*  None.
*
*
*
* Reference: Self
*
*******************************************************************************/

void free_memory (int a, int b)
{
  if( memory_start != NULL && memory_allocation_flag == 0)     // free the memory only if there is some memory allocated for the application
  {
    memory_allocation_flag = 1;                              // indicate that the allocated memory is now freed
    free (memory_start);    
    printf("\n The allocated memory is now freed \n");   
  }
  else 
  {
    printf("\n You need to allocate memory before freeing it \n");
  }
}

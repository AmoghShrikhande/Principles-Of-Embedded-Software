
/*File Name & Description : Allocated_memory_display.c, This file allows the user to see all the addresses available to the user to work with and the corresponding data
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No code leveraged in this file
 Applicable Links: No links */


#include "../includes/Allocated_memory_display.h"

extern uint32_t no_of_bytes;          // this variable stores the no of bytes the user allocates for his application
int *memory_start;                    // this variable stores the first address allocated by the malloc function
int j;
int memory_allocation_flag;

/*******************************************************************************
* Function Name: allocated_memory_display
********************************************************************************
*
* Summary:
*  Displays the allocated memory and corresponding data
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


void allocated_memory_display (int a, int b)
  {
     if (memory_allocation_flag == 0)                            //  if memory is allocated then only display the address and the data
       {
          for (j=1; j<= no_of_bytes; j++)
            {
              printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));  // display all the allocated addresses and the corresponding data at evry addresses
              printf ("Data: 0x%x " , *(memory_start-1 +j));
            }
       }
     else
       {
           printf(" \n There is no allocated memory to display \n" );
       }
  }


/*File Name & Description : Write_memory_words.c This file allows the user to write data at the user mentioned address
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No leveraged code
 Applicable Links: None */

#include "../includes/Write_memory_words.h"


int user_write_value ;
unsigned int user_entered_data;
uint32_t no_of_bytes;
int *memory_start;
int j;
int *user_entered_address;
int *temporary_address;
int memory_allocation_flag;
uint32_t no_of_bytes;

/*******************************************************************************
* Function Name: Write_memory_words
********************************************************************************
*
* Summary:
*  This function is used to write data at user defined address
*
* Parameters:
*  integer
*
* Return:
*  None.
*
* Reference: Self
*
*******************************************************************************/  	

void Write_memory_words(int a, int b)
{
  int i;

  if (memory_allocation_flag == 0)
  {
    printf("\n The available address space is: \n");  // display the allocated memory 
    for (j=1; j<= no_of_bytes; j++)
    {
      printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
      printf ("Data: 0x%x " , *(memory_start-1 +j));
    }

    printf("\n Please enter the address location, where you want to modify the data\n");
    for(i=0;i<=90;i++)               // To display organised GUI
    {
      printf("*");
    } 
    printf("\n");
    printf("\n ---> "); 
    scanf("%p", &user_entered_address);
    for(i=0;i<=90;i++)               // To display organised GUI
    {
      printf("*");
    } 

    for (j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
    {
      temporary_address = (memory_start +j);
      if (user_entered_address == temporary_address )
      {
        user_write_value = 1;
      }
    }

    if (user_write_value == 1)
    {
      printf(" \n Please enter the required value to be entered at the mentioned address \n");
      for(i=0;i<=90;i++)               // To display organised GUI
      {
        printf("*");
      } 
      printf("\n");
      printf("\n ---> "); 
      scanf("%x", &user_entered_data);
      for(i=0;i<=90;i++)               // To display organised GUI
      {
       printf("*");
      } 
      *(user_entered_address) = user_entered_data; // enter the required hex data at the given address
    }

    else
    {
      printf("\n Please enter the valid address \n"); 
    }
  }

  else
  {
    printf(" \n There is no allocated memory, therefore data cannot be written\n" );
  }
}


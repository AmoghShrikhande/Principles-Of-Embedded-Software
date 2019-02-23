/*File Name & Description : Invert_Block.c, This file allows the user to invert the data at any allocated address 
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: The calculation of the time required by the block to get inverted is taken from Geeks for Geeks
 Applicable Links: https://www.geeksforgeeks.org/time-function-in-c/
                   https://www.geeksforgeeks.org/clock-function-in-c-c/ */

#include "../includes/Invert_memory_block.h"

int users_choice;
int j;
int *user_entered_address_invert;         // User entered address where the memory has to be inverted
int *memory_start;             
int memory_allocation_flag;
int user_write_value_invert;              // Flag to check if the user entered address is a valid address
int *temporary_address_invert;            // A temporary variable to store the addresses
int no_of_bytes; 
int user_entered_offset_address_invert;   // this variable hold the offset value of the address 
clock_t time_stamp;  


/*******************************************************************************
* Function Name: Invert_Block 
********************************************************************************
*
* Summary:
*  This function is used to invert a block of memory at user entered address
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


void Invert_Block (int a , int b)

{
  printf("\nPlease enter the address of the block whose memory has to be inverted Or Enter the offset address whose memory has to be inverted ");
  printf("\nPress '1' to give the address directly, '2' to give the offset\n");
  scanf("%d",&users_choice);

  if( users_choice>0 && users_choice<3 )

  {

    if(users_choice ==1)          // The address is directly given as address
    {
      if (memory_allocation_flag == 0)
      {
        printf("\n The available address space is: \n");      // Display all the address locations allocated and the corresponding data
        for (j=1; j<= no_of_bytes; j++)
        {
          printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
          printf ("Data: 0x%x " , *(memory_start-1 +j));
        }

        printf("\n Please enter the address location, whose data you have to invert\n");  
        scanf("%p", &user_entered_address_invert);
           
        for (j=0; j< no_of_bytes; j++)           // check if the user entered address is a valid address
        {
          temporary_address_invert = (memory_start +j);  
          if (user_entered_address_invert == temporary_address_invert )
          {
            user_write_value_invert = 1;
          }
        }

    	if(user_write_value_invert ==1)        // if the entered address is a valid address , invert the memory at that location
      { 
        time_stamp = clock();                // logic to count the time required to complete the function
  	    *(user_entered_address_invert) = ~(*(user_entered_address_invert)); // logic to invert the data
        time_stamp = clock()-time_stamp;
        double time_clk = ((double)(time_stamp))/CLOCKS_PER_SEC;

        printf("\n time: %f",time_clk);
      }
      else
        {
            printf("\n Enter appropriate address\n");
        }
      } 

      else 
        {
            printf("\n Please allocate the memory before inverting the data\n");
        } 
    }


    if(users_choice ==2)   // enter the address via offset

    {
      if (memory_allocation_flag == 0)
      {
        printf("\n The available address space is: \n"); // display the available address space
        for (j=1; j<= no_of_bytes; j++)
        {
          printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
          printf ("Data: 0x%x " , *(memory_start-1 +j));
        }

        printf("\n Please enter the offset of the address location, whose data you have to invert\n");
        scanf("%d", &user_entered_offset_address_invert);
        if((user_entered_offset_address_invert>= 0) && (user_entered_offset_address_invert<no_of_bytes))
          {
            time_stamp = clock();
            *(memory_start+user_entered_offset_address_invert) = ~(*(memory_start+user_entered_offset_address_invert)); // logic to invert the data
            time_stamp = clock()-time_stamp;
            double time_clk = ((double)(time_stamp))/CLOCKS_PER_SEC;
            printf("\n time: %f",time_clk);
          }
      }
    }

  }


  else
  {
     
    printf(" \nEnter a valid input, '1'  OR '2' \n ");
  }
}



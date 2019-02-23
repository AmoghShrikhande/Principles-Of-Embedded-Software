/* Invert_memory_block */

#include "../includes/Invert_memory_block.h"

int users_choice;
int j;
int *user_entered_address_invert;
int *memory_start;
int memory_allocation_flag;
int user_write_value_invert;
int *temporary_address_invert;
int no_of_bytes;
int user_entered_offset_address_invert;


void Invert_Block (int a , int b)

{
  printf("\nPlease enter the address of the block whose memory has to be inverted Or Enter the offset address whose memory has to be inverted ");
  printf("\nPress '1' to give the address directly, '2' to give the offset\n");
  scanf("%d",&users_choice);

  if( users_choice>0 && users_choice<3 )

  {

    if(users_choice ==1)
    {
      if (memory_allocation_flag == 0)
      {
        printf("\n The available address space is: \n");
        for (j=1; j<= no_of_bytes; j++)
        {
          printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
          printf ("Data: 0x%x " , *(memory_start-1 +j));
        }

        printf("\n Please enter the address location, whose data you have to invert\n");
        scanf("%p", &user_entered_address_invert);
           
        for (j=0; j< no_of_bytes; j++)
        {
          temporary_address_invert = (memory_start +j);
          if (user_entered_address_invert == temporary_address_invert )
          {
            user_write_value_invert = 1;
          }
        }

    	if(user_write_value_invert ==1)
      {
  	    *(user_entered_address_invert) = ~(*(user_entered_address_invert));
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


    if(users_choice ==2)

    {
      if (memory_allocation_flag == 0)
      {
        printf("\n The available address space is: \n");
        for (j=1; j<= no_of_bytes; j++)
        {
          printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
          printf ("Data: 0x%x " , *(memory_start-1 +j));
        }

        printf("\n Please enter the offset of the address location, whose data you have to invert\n");
        scanf("%d", &user_entered_offset_address_invert);
        if((user_entered_offset_address_invert>= 0) && (user_entered_offset_address_invert<no_of_bytes))
          {
            *(memory_start+user_entered_offset_address_invert) = ~(*(memory_start+user_entered_offset_address_invert));
          }
      }
    }

  }


  else
  {
     
    printf(" \nEnter a valid input, '1'  OR '2' \n ");
  }
}



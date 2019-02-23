/* Write_particular_offset */

#include "../includes/Write_particular_offset.h"


int memory_allocation_flag;
int no_of_bytes;
int *memory_start;
int j;
int user_entered_offset_address;
int user_entered_offset_data;

void Write_particular_offset (int a, int b)

{
   if (memory_allocation_flag == 0) 
    {
        printf("\n The available address space is: \n");
	    for (j=1; j<= no_of_bytes; j++)
	       {
		 printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
		 printf ("Data: 0x%x " , *(memory_start-1 +j));
	       }

	   printf("\n Please enter the offset, where you want to modify the data\n");  
	   scanf("%d", &user_entered_offset_address);

          if((user_entered_offset_address>= 0) && (user_entered_offset_address<no_of_bytes))
          {
             printf("\n Please enter the data to be entered at particular offset\n");
	     scanf("%x",&user_entered_offset_data);
	    *(memory_start+user_entered_offset_address) = user_entered_offset_data;
          }
          else
{
 printf("\n Please enter a valid offset address\n");
}
   }
}
  

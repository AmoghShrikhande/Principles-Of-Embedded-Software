/* Write_memory_words.c */

#include "Write_memory_words.h"

int user_write_value = 0;
unsigned int user_entered_data;
uint32_t no_of_bytes;
int *memory_start;
int j;
 int *user_entered_address;
int *temporary_address;
 	

void Write_memory_words(int a, int b)
{
 
printf("\n Please enter the address location, where you want to modify the data\n");
scanf("%p", &user_entered_address);

 for (j=0; j< no_of_bytes; j++)
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
  scanf("%x", &user_entered_data);
*(user_entered_address) = user_entered_data;

}

else
{
   printf("\n Please enter the valid address \n");
}




}

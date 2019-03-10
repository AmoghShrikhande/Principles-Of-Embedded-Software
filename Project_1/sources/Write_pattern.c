

#include "../includes/Write_pattern.h"

int user_write_value_verify_pattern;
uint32_t no_of_bytes;
uint32_t *memory_start;
int j;
uint32_t *user_entered_address_verify_pattern;
uint32_t *temporary_address_verify_pattern;
int memory_allocation_flag;
uint32_t seed_val, data_length;
int i;
uint32_t *temp_pattern;


void Write_pattern(int a, int b)

{
   
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
    scanf("%p", &user_entered_address_verify_pattern);
    for(i=0;i<=90;i++)               // To display organised GUI
    {
      printf("*");
    } 

    for (j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
    {
      temporary_address_verify_pattern = (memory_start +j);
      if (user_entered_address_verify_pattern == temporary_address_verify_pattern )
      {
        user_write_value_verify_pattern = 1;
      }
    }

    if (user_write_value_verify_pattern == 1)
    {
      printf("Please enter the seed value and the length of the data to be entered at this location\n");
      scanf("%d %d",&seed_val,&data_length);
    
      if ( (seed_val >=0) && (data_length >=0) && (data_length <= no_of_bytes) )
      {
         for(i=0;i<data_length;i++)
           {
               temp_pattern = user_entered_address_verify_pattern;
              *(temp_pattern + i) = (((uintptr_t)(temp_pattern + i)) ^ (seed_val));
               

              

               printf("%p ", (temp_pattern + i));
               
               printf("%x ",*(temp_pattern + i));
               printf("\n");
           } 
      }
     }
 }
}    

      






















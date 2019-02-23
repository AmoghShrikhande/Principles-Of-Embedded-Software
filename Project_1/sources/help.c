#include "../includes/help.h"
#include "../includes/allocate_memory.h"
#include "../includes/free_memory.h"
#include "../includes/Allocated_memory_display.h"
#include "../includes/Write_memory_words.h"
#include "../includes/exit.h"
#include "../includes/Display_particular_address.h"
#include "../includes/Write_particular_offset.h"
#include "../includes/Invert_memory_block.h"
void help_func(void)
{
        uint32_t ch;
        uint32_t a=0,b=0;
        int i;
	printf("\n ***************************************** HELP **************************************** ");
        printf("\n Please enter the number corresponding to the functionality that you want to implement:");
        printf("\n 0 --> Allocate memory"); 
        printf("\n 1 --> Free memory"); 
        printf("\n 2 --> Write memory words"); 
        printf("\n 3 --> Display particular address");   
        printf("\n 4 --> Invert Block"); 
        printf("\n 5 --> Write pattern");
        printf("\n 6 --> Verify pattern");
        printf("\n 7 --> Write_particular_offset");
        printf("\n 8 --> allocated_memory_display\n");
        printf("\n 9 --> Exit the Utility\n");

        for(i=0;i<=90;i++)               // To display organised GUI
         {
          printf("*");
         } 
        
        printf("\n ---> "); 
        scanf("%d",&ch);
        for(i=0;i<=90;i++)
         {
          printf("*");
         } 
        printf("\n");



void Exit_the_utility (int a, int b)
          {
                exit(0);
          }



          /*void Invert_Block (int a, int b)
          {
                printf("\n Oops! This function is currently unavailable to the user\n");
          }*/

          void Write_pattern (int a, int b)
          {
                printf("\n Oops! This function is currently unavailable to the user\n");
          }

          void Verify_pattern (int a, int b)
          {
                printf("\n Oops! This function is currently unavailable to the user\n");
          }

if (ch>=0 && ch<=8) // if user enters letter code breaks
{
 
          void (*fun_ptr_arr[])(int, int) = {memory_allocate, free_memory, Write_memory_words, Display_particular_address, Invert_Block, Write_pattern, Verify_pattern, Write_particular_offset,  allocated_memory_display, Exit_the_utility }; 

           (*fun_ptr_arr[ch])(a, b); 
}

else
{
     printf("\n Please enter a valid number as per the menu !\n");
     help_func();
}
        
}

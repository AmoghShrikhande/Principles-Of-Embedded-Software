/* Display a particular address */

#include "../includes/Display_particular_address.h"

int user_write_value=0;
int *memory_start;
int offset_address_start;
int offset_address_end;
int i,j,k;
int no_of_bytes;
int memory_allocation_flag;


void Display_particular_address(int a, int b)


{
 if (memory_allocation_flag == 0)
     {
        printf("\n Enter the offset of the address from where you want to display the values\n");
        for(i=0;i<=90;i++)               // To display organised GUI
         {
          printf("*");
         } 
        
        printf("\n ---> "); 
        scanf("%d", &offset_address_start);
        for(i=0;i<=90;i++)               // To display organised GUI
         {
          printf("*");
         } 
        printf(" \nEnter the offset of the last address till you want to read\n");
         printf("\n ---> "); 
        scanf("%d", &offset_address_end);
        for(i=0;i<=90;i++)               // To display organised GUI
         {
          printf("*");
         } 

       if ( (offset_address_end>= offset_address_start) && ((offset_address_start>=0) && (offset_address_start < no_of_bytes)) && ((offset_address_end>=0) && (offset_address_end < no_of_bytes)))
         {
            for (k=offset_address_start; k<= offset_address_end; k++)
              {
                printf ("\n The address of word %d\t: %p ", k+1, (memory_start+k));
                printf ("Data: 0x%x " , *(memory_start+k));
              }
        }
       else
        {
          printf("\n Please enter the offset value correctly \n");
        }
    }
 else
       {
           printf(" \n There is no allocated memory to display \n" );
       }
}







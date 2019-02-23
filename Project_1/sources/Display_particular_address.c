/*File Name & Description : Display_particular_address.c, This file allows the user to display a range of addresses by giving the address offset
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No code leveraged in this file
 Applicable Links: No links */

#include "../includes/Display_particular_address.h"

int user_write_value=0; 
int *memory_start;
int offset_address_start;  // the offset address from which the user wants to read the data
int offset_address_end;    // the end offset address till which the user wants to  read the data
int i,j,k;
int no_of_bytes;
int memory_allocation_flag;


/*******************************************************************************
* Function Name: Display_particular_address
********************************************************************************
*
* Summary:
*  Displays the allocated memory and corresponding data for a given range of addresses
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

        if ( (offset_address_end>= offset_address_start) && ((offset_address_start>=0) && (offset_address_start < no_of_bytes)) && ((offset_address_end>=0) && (offset_address_end < no_of_bytes))) // if the offset is valid, display the required addresses
         {
            for (k=offset_address_start; k<= offset_address_end; k++)  // display the data from start of the offset address to the end of the offset address
              {
                printf ("\n The address of word %d\t: %p ", k+1, (memory_start+k));
                printf ("Data: 0x%x " , *(memory_start+k));
              }
         }
        else
         {
          printf("\n Please enter the offset value correctly \n"); // The added offset number should be logical
         }
     }
 else
      {
           printf(" \n There is no allocated memory to display \n" );
      }
}







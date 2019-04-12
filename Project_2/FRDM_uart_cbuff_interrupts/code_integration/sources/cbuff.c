/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "../includes/c_buff.h"



extern c_buf *buffer; // Creating instance for the structure
extern int character_entred_flag;
extern uint8_t data_poll;



// Create a structure for buffer characteristics

void buffer_init()             // A function used for buffer initialization
{
   char* temporary;
   buffer = (c_buf*)malloc(1 * sizeof(c_buf) );

  ((buffer)->added_items) = 0;
  ((buffer)->num_of_items) = 0;
  ((buffer)->deleted_items) = 0;

 // ((buffer)-> buffer_number) = (char*)malloc((buffer+i)->size_of_buffer);
  ((buffer)-> buffer_number) = (char*)malloc(1);

  temporary = (buffer)-> buffer_number;
  (buffer) -> head = temporary;   // Set all the pointers: head and tail at the start address of the different allocated buffers
  (buffer) -> tail = temporary;
}


void add_elements( c_buf* add_buff, char item)   // A function to add elements to the user desired buffer
{
    //printf("\nThe address of the structure is %d\n",add_buff);
    //printf("\nThe address of the buffer is %s\n",add_buff->buffer_number);
    if(add_buff -> num_of_items <= add_buff -> size_of_buffer) // Check if the buffer is full before adding elements
    {
      *add_buff -> head = item;  // Add item at the head of c_buff
      if ((add_buff -> head) == ((add_buff -> buffer_number)+(add_buff -> size_of_buffer) - 1) ) // Wrap around
        {
           add_buff -> head = add_buff -> buffer_number; // Move the Head pointer to the start of the buffer
        }
      else
        {
           add_buff -> head ++; // Increment the head pointer to the next location
        }
    add_buff -> num_of_items++; // Increment the number of items variable on addition of character to the buffer
    add_buff -> added_items++;
    }
    
    else
	{
      printf("\nSorry the buffer is full\n");
	}
    
}


//void elements_in_buffer(c_buf* buffer_elemenets)
//{
//    printf("\nThe no of elements in the buffer is %ld\n",buffer_elemenets->num_of_items);
//}





void delete_buffer (c_buf* delete_buff)           // A function used to delete the elements of the buffer
{
  
    //printf("\nThe address of the structure is %d\n",delete_buff);
    
    if (delete_buff -> num_of_items ==0)           // If there is no valid element in the buffer, nothing to be deleted
    {
        printf("\nThere is no element to be deleted");
    }
    else
	{
        
        if ((delete_buff -> tail) == ((delete_buff -> buffer_number)+(delete_buff -> size_of_buffer) - 1) ) // delete in case of wrap around
         {
            delete_buff -> tail = delete_buff -> buffer_number;
         }
        else
		 {
            delete_buff -> tail++; // Delete in normal case
         }
   
        delete_buff -> num_of_items--; 
        delete_buff -> deleted_items++;
    }
    
}





/***************************************************************************************
 *                          HEADERS & MACROS                                           *
 ***************************************************************************************/
#include "../includes/c_buff.h"

/***************************************************************************************
 *                          GLOBAL STRUCTURE INSTANCES                                  *
 ***************************************************************************************/
extern c_buf *buffer;

/***************************************************************************************
 *                          GLOBAL VARIABLES                                            *
 ***************************************************************************************/
int8_t error[20];

/*******************************************************************************
 * Function Name: buffer_init
 ********************************************************************************
 *
 * Summary
 *  This function is used to initialize the buffer, it brings both head and tail pointer at the start
 *
 * Parameters:
 *  None.
 *
 * Return:
 *  None.
 *
 * Reentrant:
 *  No.
 *
 * Reference:
 *  Self.
 *******************************************************************************/

void buffer_init()
{
	char* temporary;
	// Dynamically allocate memory for the structure holding the values for Circular buffer
	buffer = (c_buf*)malloc(1 * sizeof(c_buf) );
	// Check if dynamic memory allocation is a success for structure
	if(buffer == NULL)
	{
		sprintf(error,"ERROR");
		putst(error);
	}

	else
	{
		// Initialize the following variables in the buffer as 0
		((buffer)->added_items) = 0;
		((buffer)->num_of_items) = 0;
		((buffer)->deleted_items) = 0;
		// // Dynamically allocate memory for the buffer holding the characters entered by the user
		((buffer)-> buffer_number) = (char*)malloc(1);
		// // Check if dynamic memory allocation is a success for buffer
		if ( ((buffer)-> buffer_number) == NULL)
		{
			sprintf(error,"ERROR");
			putst(error);
		}

		else
		{
			// Initialize the buffer head and tail to one location
			temporary = (buffer)-> buffer_number;
			(buffer) -> head = temporary;   // Set all the pointers: head and tail at the start address of the different allocated buffers
			(buffer) -> tail = temporary;
		}
	}
}

/*******************************************************************************
 * Function Name: add_elements
 ********************************************************************************
 *
 * Summary
 *  This function is used to add the user entered characters to the circular buffer
 *
 * Parameters:
 *  Two. 1.The buffer address to which element is to be added, 2. the item to be added to the buffer
 *
 * Return:
 *  None.
 *
 * Reentrant:
 *  No.
 *
 * Reference:
 *  Self.
 *******************************************************************************/

void add_elements( c_buf* add_buff, char item)
{
	// Check if the buffer is full before adding elements
	if(add_buff -> num_of_items <= add_buff -> size_of_buffer)
	{
		// Add item at the head of c_buff
		*add_buff -> head = item;
		// Wrap around
		if ((add_buff -> head) == ((add_buff -> buffer_number)+(add_buff -> size_of_buffer) - 1) )
		{
			add_buff -> head = add_buff -> buffer_number; // Move the Head pointer to the start of the buffer
		}
		// Increment the head pointer to the next location
		else
		{
			add_buff -> head ++;
		}
		// Increment the number of items variable on addition of character to the buffer
		add_buff -> num_of_items++;
		add_buff -> added_items++;
	}

	else
	{
		printf("\nSorry the buffer is full\n");
	}

}

/*******************************************************************************
 * Function Name: delete_buffer
 ********************************************************************************
 *
 * Summary
 *  This function is used to delete the entered characters in FIFO manner from the circular buffer
 *
 * Parameters:
 *  One. 1.The buffer address from which element is to be deleted
 *
 * Return:
 *  None.
 *
 * Reentrant:
 *  No.
 *
 * Reference:
 *  Self.
 *******************************************************************************/

void delete_buffer (c_buf* delete_buff)
{
	// If there is no valid element in the buffer, nothing to be deleted
	if (delete_buff -> num_of_items == 0)
	{
		printf("\nThere is no element to be deleted");
	}
	else
	{
		// delete in case of wrap around
		if ((delete_buff -> tail) == ((delete_buff -> buffer_number)+(delete_buff -> size_of_buffer) - 1) )
		{
			delete_buff -> tail = delete_buff -> buffer_number;
		}
		// Delete in normal case
		else
		{
			delete_buff -> tail++;
		}
        delete_buff -> num_of_items--; 
		delete_buff -> deleted_items++;
	}

}





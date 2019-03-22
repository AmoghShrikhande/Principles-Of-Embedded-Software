#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"

/*@brief : Configures Circular Buffer.
 *
 *@param cbuff_t *ptr : pointer to cbuff_t structure
 *@param length       : sizeof circular buffer
 *
 *@return : CONFIG_SUCCESS if configuration successful
 *@return : CONFIG_FAIL if configuration failed
 *
 * */
cbuff_stat cbuff_config(cbuff_t *ptr, int length)
{
	cbuff_stat stat;

	//Check if ptr is NULL or length is negative
	if(ptr == NULL || length <0)
	{
		stat = CONFIG_FAIL;
		
	}
	else
	{
		ptr->cbuff = (int8_t *)malloc(sizeof(int8_t)*length);
		ptr->tail  = ptr->cbuff;
		ptr->head  = ptr->cbuff;
		ptr->char_count = 0;
		ptr->length = length;
		stat = CONFIG_SUCCESS;
	}
	return stat;
}

/*@brief :Checks if the circular buffer is empty or not.
 * 	 :If the circular buffer is empty, the user cannot
 * 	  delete any characters from the circular buffer.
 *
 *	
 *@param : cbuff_t *ptr : pointer to cbuff_t structure
 *
 *@return: CBUFF_EMPTY_CHECK_FAIL if Null pointer check fails
 *	 : CBUFF_EMPTY if circular buffer is empty 
 *	 : CBUFF_CAN_BE_FILLED if there is still space in the circular buffer
 *	   to add characters.
 * */
cbuff_stat cbuff_empty(cbuff_t *ptr)
{
	cbuff_stat stat;

	if(ptr == NULL)
	{
		stat = CBUFF_EMPTY_CHECK_FAIL;
		return stat;
	}
	
	
	if(ptr->char_count == 0)
	{
		stat = CBUFF_EMPTY;
		return stat;
	}
	else
	{
		stat = CBUFF_CAN_BE_FILLED;
		return stat;
	}

}

/*@brief : To check if the circular buffer is full.
 * 	 : If the circular buffer is full, the user
 * 	   cannot add any new characters.
 *
 *@param : cbuff_t *ptr : pointer to cbuff_t structure
 *
 *@return: CBUFF_FULL_CHECK_FAIL if null pointer check fails
 *	 : CBUFF_FULL if circular buffer is full
 *	 : CBUFF_HAS_SPCE if circular buffer has space and new
 *	   characters can be added
 * */
cbuff_stat cbuff_full(cbuff_t *ptr)
{
	cbuff_stat stat;

	if(ptr == NULL)
	{
		stat = CBUFF_FULL_CHECK_FAIL;
		return stat;
	}

	if(ptr->char_count == ptr->length)
	{
		stat = CBUFF_FULL;
	}
	else
	{
		stat = CBUFF_HAS_SPACE;
	}
	return stat;
}



/*@brief : Adds characters to the circular buffer.
 *	 : Calls cbuff_full before adding any new characters to
 *	   the circular buffer.
 *@param : cbuff_t *ptr : pointer to a structure cbuff_t
 *	 : int8_t character : character to be added to the circular buffer
 *
 *@return: CBUFF_ADD_FAILED if null pointer check fails
 *	   CBUFF_HAS_SPACE 
 *	   CBUFF_ADD SUCCESS if insertion of character is successful
 * */
cbuff_stat cbuff_insert(cbuff_t *ptr, int8_t character)
{
	cbuff_stat stat;

	if(ptr == NULL)
	{
		stat = CBUFF_ADD_FAILED;
		return stat;
	}

	//check if cbuff is full before adding a character
	stat = cbuff_full(ptr);

	if (stat == CBUFF_HAS_SPACE)
	{
		if(ptr->tail == ptr->cbuff + ptr->length -1)
		{
			*ptr->tail = character;	//add character to tail
			ptr->char_count++;	//increment character count
			ptr->tail = ptr->cbuff;	//wrap around condition
		}
		else
		{
			*ptr->tail = character;	//add character to tail
			(ptr->char_count)++;    //increase the character count
			(ptr->tail)++;		//increment tail position
		}
		stat = CBUFF_ADD_SUCCESS;
	}
	//printf("The character added to the Circular Buffer was %c\n",character);
	return stat;
}


/*@brief : Deletes a character from the circular buffer.
 *
 *@param : cbuff_t *ptr : pointer to cbuff_t structure
 *
 *@return: CBUFF_DELETE_FAILED if null pointer check failed
 * 	   CBUFF_DELETE_SUCCESS if deletion from circular buffer successful
 * 	   CBUFF_CAN_BE_FILLED 
 * */
cbuff_stat cbuff_delete(cbuff_t *ptr)
{
	cbuff_stat stat;
	int8_t DeletedChar;

	if(ptr == NULL)
	{
		stat = CBUFF_DELETE_FAILED;
		return stat;
	}
	
	//check if cbuff is empty before deleteing a character
	stat =cbuff_empty(ptr);
	
	if(stat == CBUFF_CAN_BE_FILLED)
	{
		if(ptr->tail == ptr->cbuff + ptr->length - 1)
		{
			DeletedChar = *(ptr->head);
			(ptr->char_count)--;
			ptr->head = ptr->cbuff;
			stat = CBUFF_DELETE_SUCCESS;
		}
		else
		{
			DeletedChar = *(ptr->head);
			(ptr->char_count)--;
			(ptr->head)++;
			stat = CBUFF_DELETE_SUCCESS;
		}
		//printf("IN CIRCULAR BUFFER\n");
		printf("Deleted Character is %c\n",DeletedChar);

	}
	return stat;
}


/*@brief : Destroys the circular buffer by freeing the memory allocated.
 *
 *@param : cbuff_t *ptr : poiter to the cbuff_t structure
 *
 *@return: CBUFF_DESTROYED_FAIL if null pointer check failed
 	 : CBUFF_DESTROYED if circular buffer destroyed successsfully
 * */
cbuff_stat cbuff_remove(cbuff_t *ptr)
{

	cbuff_stat stat;
	if(ptr == NULL)
	{
		stat = CBUFF_DESTROYED_FAIL;
	}
	else
	{
		free(ptr->cbuff);
		ptr->cbuff = NULL;
		stat = CBUFF_DESTROYED;
	}
	return stat;
}

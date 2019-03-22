#include <stdio.h>


typedef struct cbuff{
	int8_t *cbuff;
	int8_t *head;
	int8_t *tail;
	int8_t char_count;
	int8_t length;
}cbuff_t;


typedef enum{
	CONFIG_SUCCESS,		//0
	CONFIG_FAIL,		//1
	CBUFF_EMPTY_CHECK_FAIL,	//2
	CBUFF_EMPTY,		//3
	CBUFF_FULL_CHECK_FAIL,	//4
	CBUFF_CAN_BE_FILLED,	//5
	CBUFF_FULL,		//6
	CBUFF_HAS_SPACE,	//7
	CBUFF_ADD_FAILED,	//8
	CBUFF_ADD_SUCCESS,	//9
	CBUFF_DELETE_FAILED,	//10
	CBUFF_DELETE_SUCCESS,	//11
	CBUFF_DESTROYED_FAIL,	//12
	CBUFF_DESTROYED		//13
}cbuff_stat;



cbuff_stat cbuff_delete(cbuff_t *ptr);
cbuff_stat cbuff_full(cbuff_t *ptr);
cbuff_stat cbuff_config(cbuff_t *ptr, int length);
cbuff_stat cbuff_empty(cbuff_t *ptr);
cbuff_stat cbuff_insert(cbuff_t *ptr, int8_t character);
cbuff_stat cbuff_remove(cbuff_t *ptr);

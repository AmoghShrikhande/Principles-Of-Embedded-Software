#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"


int main()
{
	cbuff_stat stat;
	int length = 10;
	cbuff_t *ptr = (cbuff_t *)malloc(sizeof(cbuff_t));
	stat = cbuff_config(ptr,length);
	printf("Status of Cbuff_config() is %d\n",stat);

	for(int i=0;i<10;i++)
	{
		stat= cbuff_insert(ptr,i+97);
		printf("Status of cbuff_add() is %d\n",stat);
	}

	for(int i=0;i<5;i++)
	{
		stat = cbuff_delete(ptr);
		printf("Status of cbuff_delete() is %d\n",stat);
	}

	stat = cbuff_remove(ptr);
	printf("Cbuff was destroyed successfully with status %d\n",stat);

	return 0;
}

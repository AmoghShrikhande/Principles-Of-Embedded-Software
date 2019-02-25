/*File Name & Description : main.c, This file gives the user choices to use this command line utility
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No code leveraged in this file
 Applicable Links: No links*/

#include "../includes/main.h"

char command[100];

int main()
{
	memset(command,0,100);  // Used to allocate a block of memory of 10 bytes
	extern int memory_allocation_flag;  // A variable used as a flag to determine if memory has been allocated for the application

	printf("Welcome to Interactive Memory command line utility\n");
	memory_allocation_flag = 1;         //  When value of this variable is 1, memory is not allocated by the user

	while(1)
	{
		printf("\n Enter the desired operation that you want to perform (Example: To access the menu, type 'help' in the GUI)  ");
		printf("\n Please choose among the following commands:");
		printf("\n 1. help");
		printf("\n 2. exit\n");
		printf("-->");
		scanf("%s",command);
		printf("\n The entered command is: %s",command);

		if((!strcmp(command,"help")))
		{
			help_func();
		}
		else if((!strcmp(command,"exit")))
		{
			exit_func();
		}
		else 
		{
			printf("\n Please enter a valid command !\n");
		}
	}
	return 0;
}

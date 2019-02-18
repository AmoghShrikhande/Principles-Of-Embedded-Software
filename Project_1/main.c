#include "main.h"

char command[100];


int main()
{
       memset(command,0,10);  // Used to allocate a block of memory of 10 bytes

       printf("Welcome to Interactive Memory command line utility\n");
	
	while(1)
	{
		printf("\n Enter the desired operation that you want to perform (Example: To access the menu, type 'help' in the GUI)  ");
                printf("\n Please choose among the following commands:");
		printf("\n 1. help");
		printf("\n 2. exit\n");
                printf("-->");
                     
                //scanf("%[^\n]%c",command);
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

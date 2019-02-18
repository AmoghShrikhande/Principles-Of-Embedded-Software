#include "help.h"

void help_func(void)
{
        uint32_t a;
        int i;
	printf("\n ***************************************** HELP **************************************** ");
        printf("\n Please enter the number corresponding to the functionality that you want to implement:");
        printf("\n 0 --> Allocate memory"); 
        printf("\n 1 --> Free memory"); 
        printf("\n 2 --> Write memory words"); 
        printf("\n 3 --> Display memory words");   
        printf("\n 4 --> Invert Block"); 
        printf("\n 5 --> Write pattern");
        
        printf("\n 6 --> Verify pattern\n");
        for(i=0;i<=90;i++)               // To display organised GUI
         {
          printf("*");
         } 
        printf("\n");
        printf("\n ---> "); 
        scanf("%d",&a);
        for(i=0;i<=90;i++)
         {
          printf("*");
         } 
        

        switch(a){
                   case 0: printf("\n Oops! This function is currently unavailable to the user\n");
                           break;
                   case 1: printf("\n Oops! This function is currently unavailable to the user\n");
                           break;
                   case 2: printf("\n Oops! This function is currently unavailable to the user\n");
                           break;
                   case 3: printf("\n Oops! This function is currently unavailable to the user\n");
                           break;
                   case 4: printf("\n Oops! This function is currently unavailable to the user\n");
                           break;
                   case 5: printf("\n Oops! This function is currently unavailable to the user\n");
                           break;
                   case 6: printf("\n Oops! This function is currently unavailable to the user\n");
                           break;
                   default:printf("\n Please enter a valid number as per the menu !\n");
                          help_func();
          }
 
	
}



/***************************************************************************************
 *                          HEADERS & MACROS                                           *
 ***************************************************************************************/
#include "Proj 2.h"

/***************************************************************************************
 *                          MAIN                                                       *
 ***************************************************************************************/

int main(void)
{

	palindrome.palindrome_count=0;
	palindrome.check_flag=0;

	// Initialize the uart, circular buffer, LED port pins and interrupts
	system_init();

	while(1)
	{

		/* Logic for palindrome */

		// To check if a number is a palindrome number. The number should be equal to the reverse of the same number
		palindrome.reverse=0;
		palindrome.palindrome_count++;

		palindrome.temp = palindrome.palindrome_count;

		// Logic to reverse a number
		while((palindrome.temp)!= 0)
		{
			palindrome.remainder = (palindrome.temp )%10;
			palindrome.reverse = (palindrome.reverse)*10 + palindrome.remainder;
			palindrome.temp = (palindrome.temp)/10;

		}

		// If the number is a palindrome number, store that number in the latest_palindrome variable
		if(palindrome.palindrome_count == palindrome.reverse)
		{
			palindrome.latest_palindrome = palindrome.palindrome_count;
		}

		// Check the character_entred_flag, which signifies if user enters a character in serial terminal
		if(character_entred_flag==1)
		{
			// Give a delay of 20ms for report generation
			delayms(20);

			// Print report on serial terminal
			sprintf(pt_array.report,"******REPORT******");
			putst(pt_array.report);

			// Print the latest palindrome number calculated just before printing the report
			{
				sprintf(pt_array.palindrome_alert,"\n\rPalindrome value --> %d\n\r",palindrome.latest_palindrome);
				putst(pt_array.palindrome_alert);
			}

			// Printing the report
			for(int i=0;i<256;i++)
			{
				// If a particular character is not entered, dont print it
				if(report_charac[i] != 0)
				{
					sprintf(pt_array.str,"\n\r%c --> %d\n\r",i,count[i]);
					putst(pt_array.str);
				}
			}
			character_entred_flag=0;
		}

		// Toggle the LED, if ISR is not being executed
		if ( GPIO_flag = 1);
		{
			GPIO_toggle();
		}
	}




	return 0 ;
}


/*******************************************************************************
* Function Name: system_init
********************************************************************************
*
* Summary
*  This function helps the user to initialize uart, circular buffer, interrupts and GPIO pins
*
* Parameters:
*  None
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
* Reference:
*  Self
*******************************************************************************/

void system_init(void)
{
	// Initialize UART0 for FRDM KL25Z
	uart_init();
    // Initialize the circular buffer to hold characters
	buffer_init();
    // Enable the receive interrupts
	interrupt_enable();
    // Enable the GPIO pins for LED
	GPIO_init();
}

/*******************************************************************************
* Function Name: delayms
********************************************************************************
*
* Summary
*  This function enables the user to create a required delay in ms
*
* Parameters:
*  Integer, the value of integer gives the value of delay in ms
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
* Reference:
*  Professor Linden McClures Notes
*******************************************************************************/

void delayms(int t)
{
	int i,j;

	for(i=0;i<t;i++)
	{
		for(j=0;j<7000;j++)
		{

		}
	}
}


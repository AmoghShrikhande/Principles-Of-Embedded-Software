

/***************************************************************************************
 *                          HEADERS & MACROS                                            *
 ***************************************************************************************/
#include "Proj 2.h"

int main(void)
{


	palindrome.palindrome_count=0;
	palindrome.check_flag=0;

	system_init();

	while(1)
	{
		palindrome.reverse=0;
		palindrome.palindrome_count++;

		palindrome.temp = palindrome.palindrome_count;

		while((palindrome.temp)!= 0)
		{
			palindrome.remainder = (palindrome.temp )%10;
			palindrome.reverse = (palindrome.reverse)*10 + palindrome.remainder;
			palindrome.temp = (palindrome.temp)/10;

		}

		if(palindrome.palindrome_count == palindrome.reverse)
		{
			palindrome.latest_palindrome = palindrome.palindrome_count;
		}



		if(character_entred_flag==1)
		{
			delayms(20);

			sprintf(pt_array.report,"******REPORT******");
			putst(pt_array.report);


			{
				sprintf(pt_array.palindrome_alert,"\n\rPalindrome value --> %d\n\r",palindrome.latest_palindrome);
				putst(pt_array.palindrome_alert);
			}

			for(int i=0;i<256;i++)
			{
				if(report_charac[i] != 0)
				{

					sprintf(pt_array.str,"\n\r%c --> %d\n\r",i,count[i]);
					putst(pt_array.str);
				}
			}
			character_entred_flag=0;
		}

		if ( GPIO_flag = 1);
		{
			GPIO_toggle();
		}



	}




	return 0 ;
}

void system_init(void)
{
	uart_init();

	buffer_init();

	interrupt_enable();

	GPIO_init();


}

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


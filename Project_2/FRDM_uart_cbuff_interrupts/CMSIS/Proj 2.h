/*
 * Proj 2.h
 *
 *  Created on: Apr 11, 2019
 *      Author: amosh
 */

#ifndef PROJ_2_H_
#define PROJ_2_H_

/***************************************************************************************
*                          HEADERS & MACROS                                            *
***************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "../code_integration/includes/c_buff.h"
#include "../code_integration/includes/uart.h"

/***************************************************************************************
*                          GLOBAL STRUCTURES                                           *
***************************************************************************************/

/*Structure used to hold all the values relating to finding palindrome numbers */

typedef struct
{
	int palindrome_count;
	int temp;
	int remainder;
	int reverse;
	int check_flag;
	int latest_palindrome;
}pal;

/*Structure used to store the strings and values to be printed on the serial terminal*/

typedef struct{

	int8_t str[20];
	int8_t report[20];
	int8_t palindrome_alert[30];

}array_print;

/***************************************************************************************
*                          GLOBAL STRUCTURE INSTANCES                                  *
***************************************************************************************/
c_buf *buffer;
pal palindrome;
array_print pt_array = {0};

/***************************************************************************************
*                          GLOBAL VARIABLES                                            *
***************************************************************************************/
// An array used to determine the characters not entered by the user
char report_charac[256] = {0};
// An array used to hold the count of the characters.
// The array index directly relates to the ASCII value of the characters
int count[256] = {0};

uint8_t data_poll = 0;
// A flag variable used to alter the status of LED's
int GPIO_flag = 1;
// A flag variable used to print the report as soon as a new character is entered by the user
int character_entred_flag=0;

/***************************************************************************************
*                          FUNCTION PROTOTYPES                                         *
***************************************************************************************/
void system_init(void);
void delayms(int);

#endif /* PROJ_2_H_ */

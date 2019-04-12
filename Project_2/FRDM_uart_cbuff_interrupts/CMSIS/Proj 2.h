/*
 * Proj 2.h
 *
 *  Created on: Apr 11, 2019
 *      Author: amosh
 */

#ifndef PROJ_2_H_
#define PROJ_2_H_


#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

#include "../code_integration/includes/c_buff.h"
#include "../code_integration/includes/uart.h"


c_buf *buffer; // Creating instance for the structure

char report_charac[256] = {0};

int count[256] = {0};

uint8_t data_poll = 0;

int GPIO_flag = 1;

typedef struct{

	 int palindrome_count;
	    int temp;
		int remainder;
		int reverse;
		int check_flag;
		int latest_palindrome;


}pal;

pal palindrome;

typedef struct{

	int8_t str[20];
	    int8_t report[20];
	    int8_t palindrome_alert[30];

}array_print;


array_print pt_array = {0};

int character_entred_flag=0;

void system_init(void);

void delayms(int);



#endif /* PROJ_2_H_ */

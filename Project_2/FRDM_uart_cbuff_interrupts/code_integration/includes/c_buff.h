/*========================================================================
** ring.h
** Circular buffer
** ECEN5813
**========================================================================*/
#ifndef C_BUFF_H
#define C_BUFF_H

/***************************************************************************************
*                          HEADERS & MACROS                                            *
***************************************************************************************/
#include "MKL25Z4.h"
#include <stdlib.h>
#include "stdarg.h"
#include <stdio.h>

/***************************************************************************************
*                          GLOBAL STRUCTURES                                           *
***************************************************************************************/

/*Structure used to store different values for a circular buffer*/
typedef struct circular_buffer
{
    char* buffer_number;
    char* head;
    char* tail;
    size_t size_of_buffer;
    size_t num_of_items;
    size_t added_items;
    size_t deleted_items;
}c_buf;

/***************************************************************************************
*                          GLOBAL VARIABLES                                            *
***************************************************************************************/
extern int character_entred_flag;
extern uint8_t data_poll;

/***************************************************************************************
*                          FUNCTION PROTOTYPES                                         *
***************************************************************************************/
void add_elements( c_buf* add_buff, char item);
void delete_buffer (c_buf* delete_buff);
void buffer_init();

#endif

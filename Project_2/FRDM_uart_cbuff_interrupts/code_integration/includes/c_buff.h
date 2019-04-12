/*========================================================================
** ring.h
** Circular buffer
** ECEN5813
**========================================================================*/
#ifndef C_BUFF_H
#define C_BUFF_H

/**********************
******INCLUDES*********
**********************/

#include <stdlib.h>
#include "stdarg.h"
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"




/*********************************
*********GLOBAL STRUCTURE*********
**********************************/
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

//writ enum which has all return status for all functions





/*********************************
******FUCNTION PROTOTYPES*********
**********************************/
void add_elements( c_buf* add_buff, char item);
//int display_buffer (c_buf* display_buff);
void delete_buffer (c_buf* delete_buff);
void buffer_init();

// ring_t *init( int length );
// int insert( ring_t *ring, char data);
// int remove_t(ring_t *ring, char *data);
// int entries(ring_t *ring);

#endif

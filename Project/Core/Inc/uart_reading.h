/*
 * uart_reading.h
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#ifndef INC_UART_READING_H_
#define INC_UART_READING_H_

#include "global.h"

#define MAX_BUFFER_SIZE 30

void uart_reading_init();

uint8_t get_last_character();
#endif /* INC_ADC_READING_H_ */

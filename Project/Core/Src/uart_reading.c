/*
 * uart_reading.c
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#include "uart_reading.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

void uart_reading_init()
{
	HAL_UART_Receive_IT(&huart2, &temp, 1);
}

uint8_t get_last_character()
{
	return temp;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART2)
	{
		// Loop-back communication to observe system behavior conveniently
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		buffer[index_buffer] = temp;
		++index_buffer;
		if (index_buffer == MAX_BUFFER_SIZE)
		{
			index_buffer = 0;
		}
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

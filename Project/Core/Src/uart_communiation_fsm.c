/*
 * uart_communiation_fsm.c
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#include "uart_communiation_fsm.h"
#define USER_ACCEPT_TIMEOUT 3000

UARTState uartState = IDLE;

void uart_communiation_init()
{
	uartState = IDLE;
}

void uart_communiation_fsm()
{
	switch (uartState)
	{
	case IDLE:
		if (sensor_reading_flag == 1)
		{
			uartState = SENSOR_DISPLAY;
			sensor_reading_flag = 0;
		}
		break;
	case SENSOR_DISPLAY:
		set_sensor_timer(USER_ACCEPT_TIMEOUT);
		transmit_sensor_value();
		uartState = USER_ACCEPT;
		break;
	case USER_ACCEPT:
		if (user_accept_flag == 1)
		{
			uartState = IDLE;
			user_accept_flag = 0;
		}
		if (is_sensor_timer_flagged())
		{
			uartState = SENSOR_DISPLAY;
		}
		break;
	default:
		break;
	}
}

/*
 * uart_communiation_fsm.h
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#ifndef INC_UART_COMMUNIATION_FSM_H_
#define INC_UART_COMMUNIATION_FSM_H_

#include "global.h"

typedef enum {
	IDLE,
	SENSOR_DISPLAY,
	USER_ACCEPT
} UARTState;

void uart_communiation_fsm();
void uart_communiation_init();

#endif /* INC_UART_COMMUNIATION_FSM_H_ */

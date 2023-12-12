/*
 * global.h
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "uart_reading.h"
#include "command_parser_fsm.h"
#include "uart_communiation_fsm.h"
#include "adc_reading.h"
#include "timer.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim2;

extern uint8_t buffer_flag;

extern uint8_t sensor_reading_flag;
extern uint8_t user_accept_flag;
#endif /* INC_GLOBAL_H_ */

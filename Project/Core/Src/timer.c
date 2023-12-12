/*
 * timer.c
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#include "timer.h"

int sensor_timer_flag = 0;
int sensor_timer_counter = 0;

void timer_init()
{
	HAL_TIM_Base_Start_IT(&htim2);
}

void set_sensor_timer(int duration)
{
	sensor_timer_counter = duration / TIME_UNIT;
	sensor_timer_flag = 0;
}

int is_sensor_timer_flagged()
{
	return sensor_timer_flag;
}

void sensor_timer_run()
{
	--sensor_timer_counter;
	if (sensor_timer_counter <= 0)
	{
		sensor_timer_flag = 1;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		sensor_timer_run();
	}
}

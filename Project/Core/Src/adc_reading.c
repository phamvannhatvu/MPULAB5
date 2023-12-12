/*
 * adc_reading.c
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#define VCC_VALUE 4095
#define GND_VALUE 0
#define VCC_VOLTAGE 5

#include "adc_reading.h"

uint32_t ADC_value = 0;

void adc_reading_init()
{
	HAL_ADC_Start(&hadc1);
}

void read_sensor_value()
{
	ADC_value = HAL_ADC_GetValue(&hadc1);
}

void transmit_sensor_value()
{
	HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
	float sensor_voltage = 1.0 * (ADC_value - GND_VALUE) /
			(VCC_VALUE - GND_VALUE) * VCC_VOLTAGE;
	char str[10];
	uint8_t str_len = sprintf(str, "%4.3f\r\n", sensor_voltage);
	for (uint8_t i = 0; i < str_len; ++i)
	{
		HAL_UART_Transmit(&huart2, (uint8_t*)(&str[i]), 1, 50);
	}
}

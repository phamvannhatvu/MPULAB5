/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#include "command_parser_fsm.h"

ParserState parserState = SENSOR_READING_PARSE;

uint8_t sensor_reading_command[] = {'!', 'R', 'S', 'T', '#'};
uint8_t sensor_reading_command_len = 5;
uint8_t user_accept_command[] = {'!', 'O', 'K', '#'};
uint8_t user_accept_command_len = 4;
uint8_t command_index = 0;

uint8_t sensor_reading_flag = 0;
uint8_t user_accept_flag = 0;

void command_parser_init()
{
	parserState = SENSOR_READING_IDLE;
}

void command_parser_fsm()
{
	switch (parserState)
	{
	case SENSOR_READING_IDLE:
		if (get_last_character() == '!')
		{
			parserState = SENSOR_READING_PARSE;
			read_sensor_value();
			command_index = 1;
		}
		break;
	case SENSOR_READING_PARSE:
		if (get_last_character() != sensor_reading_command[command_index])
		{
			parserState = SENSOR_READING_IDLE;
		}
		++command_index;
		if (command_index == sensor_reading_command_len)
		{
			sensor_reading_flag = 1;
			parserState = USER_ACCEPT_IDLE;
		}
		break;
	case USER_ACCEPT_IDLE:
		if (get_last_character() == '!')
		{
			parserState = USER_ACCEPT_PARSE;
			command_index = 1;
		}
		break;
	case USER_ACCEPT_PARSE:
		if (get_last_character() != user_accept_command[command_index])
		{
			parserState = USER_ACCEPT_IDLE;
		}
		++command_index;
		if (command_index == user_accept_command_len)
		{
			user_accept_flag = 1;
			parserState = SENSOR_READING_IDLE;
		}
		break;
	default:
		break;
	}
}

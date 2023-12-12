/*
 * command_parser_fsm.h
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_

#include "global.h"

typedef enum {
	SENSOR_READING_IDLE,
	SENSOR_READING_PARSE,
	USER_ACCEPT_IDLE,
	USER_ACCEPT_PARSE
} ParserState;

void command_parser_fsm();
void command_parser_init();
#endif /* INC_COMMAND_PARSER_FSM_H_ */

/*
 * timer.h
 *
 *  Created on: Dec 12, 2023
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIME_UNIT 10 // in milliseconds

#include "global.h"

void timer_init();
void set_sensor_timer(int duration);
int is_sensor_timer_flagged();

#endif /* INC_TIMER_H_ */

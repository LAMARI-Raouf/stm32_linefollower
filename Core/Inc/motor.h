/*
 * motor.h
 *
 *  Created on: Sep 29, 2026
 *      Author: Raouf
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"
typedef struct Motor Motor;

struct Motor{
	TIM_HandleTypeDef *htim;
	uint32_t channel;          // for PWM

	GPIO_TypeDef *hgpio_AN1;
	GPIO_TypeDef *hgpio_AN2;
	uint16_t AN1;
	uint16_t AN2;
	uint32_t maxDuty;		// ARR

};

void motorInit(Motor* motor, GPIO_TypeDef* hgpio_AN1, uint16_t AN1,
               GPIO_TypeDef* hgpio_AN2, uint16_t AN2,TIM_HandleTypeDef* htim, uint32_t channel);
void motorControl(Motor* motor, int16_t speed);
void motorHalt(Motor* motor);

#endif /* INC_MOTOR_H_ */

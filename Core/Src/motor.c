/*
 * motor.c
 *
 *  Created on: Sep 30, 2026
 *      Author: Raouf
 */

#include "motor.h"

void motorControl(Motor* motor, int16_t speed){

	if (speed > 0){
		HAL_GPIO_WritePin(motor->hgpio_AN1, motor->AN1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor->hgpio_AN2, motor->AN2, GPIO_PIN_SET);
	}
	else if (speed < 0){
		HAL_GPIO_WritePin(motor->hgpio_AN1, motor->AN1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(motor->hgpio_AN2, motor->AN2, GPIO_PIN_RESET);
		speed = -speed;
	}
	else{
		HAL_GPIO_WritePin(motor->hgpio_AN1, motor->AN1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor->hgpio_AN2, motor->AN2, GPIO_PIN_RESET);
	}

	uint32_t duty = (uint32_t)speed;
	duty = duty > motor->maxDuty ? motor->maxDuty : duty;
	__HAL_TIM_SET_COMPARE(motor->htim, motor->channel, duty);
}

void motorHalt(Motor* motor){
	HAL_GPIO_WritePin(motor->hgpio_AN1, motor->AN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor->hgpio_AN2, motor->AN2, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(motor->htim, motor->channel, motor->maxDuty);
}

void motorInit(Motor* motor, GPIO_TypeDef* hgpio_AN1, uint16_t AN1, GPIO_TypeDef* hgpio_AN2, uint16_t AN2,TIM_HandleTypeDef* htim, uint32_t channel){
	motor->htim = htim;
	motor->hgpio_AN1 = hgpio_AN1;
	motor->hgpio_AN2 = hgpio_AN2;
	motor->AN1 = AN1;
	motor->AN2 = AN2;
	motor->channel = channel;
	motor->maxDuty = htim->Instance->ARR;

	HAL_TIM_PWM_Start(htim, channel);
}

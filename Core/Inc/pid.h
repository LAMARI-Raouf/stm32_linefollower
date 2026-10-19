/*
 * pid.h
 *
 *  Created on: Oct 3, 2026
 *      Author: Raouf
 */

#ifndef INC_PID_H_
#define INC_PID_H_


#include "main.h"
#include "motor.h"
#include "qtr.h"
#include "tim.h"
#include "common.h"

#define dt 0.001
#define MAX_PWM 1000
#define MIN_PWM 0

typedef struct PID PID;


struct PID{

	Motor* left;
	Motor* right;

	QTR* qtr;

	TIM_HandleTypeDef* tickTimer;

	float Kp;
	float Ki;
	float Kd;

	float alpha;

	uint32_t baseSpeed;

	float error;
	float lastError;
	float derivative;
	float filteredDerivative;
	float integral;

};

void pidInit(PID* pid, Motor* left, Motor* right, QTR* qtr, TIM_HandleTypeDef* tickTimer, float Kp, float Ki, float Kd, uint32_t baseSpeed);
void pidFollow(PID* pid);

#endif /* INC_PID_H_ */

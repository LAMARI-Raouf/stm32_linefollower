/*
 * pid.c
 *
 *  Created on: Oct 3, 2026
 *      Author: Raouf
 */

#include "pid.h"

void pidFollow(PID *pid)
{
    pid->error = qtrReadLine(pid->qtr);


    float derivative = (pid->error - pid->lastError) / dt;

    pid->filteredDerivative =
        pid->alpha * derivative +
        (1.0f - pid->alpha) * pid->filteredDerivative;

    float P = pid->Kp * pid->error;
    float D = pid->Kd * pid->filteredDerivative;


    float maxCorrection =
        (MAX_PWM - pid->baseSpeed < pid->baseSpeed - MIN_PWM) ?
        MAX_PWM - pid->baseSpeed :
        pid->baseSpeed - MIN_PWM;

    float correction = P + D + pid->Ki * pid->integral;

    if (!((correction >= maxCorrection && pid->error > 0) ||
          (correction <= -maxCorrection && pid->error < 0)))
    {
        pid->integral += pid->error * dt;
    }



    correction = P + D + pid->Ki * pid->integral;


    correction = (correction > maxCorrection) ? maxCorrection :
                 (correction < -maxCorrection) ? -maxCorrection :
                 correction;


    motorControl(pid->left,
        (int16_t)(_abs(pid->baseSpeed + correction)));

    motorControl(pid->right,
        (int16_t)(_abs(pid->baseSpeed - correction)));

    pid->lastError = pid->error;
}

void pidInit(PID* pid, Motor* left, Motor* right, QTR* qtr, TIM_HandleTypeDef* tickTimer, float Kp, float Ki, float Kd, uint32_t baseSpeed){


	pid->left = left;
	pid->right = right;
	pid->qtr = qtr;
	pid->tickTimer = tickTimer;

	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;
	pid->baseSpeed = baseSpeed;

	pid->error = 0;
	pid->lastError = 0;
	pid->integral = 0;

	pid->alpha = 0.1;

	HAL_TIM_Base_Start_IT(pid->tickTimer); // start 1ms interrupts for PID correction.




}

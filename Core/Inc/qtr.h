/*
 * qtr.h
 *
 *  Created on: Sep 30, 2026
 *      Author: Raouf
 */

#ifndef INC_QTR_H_
#define INC_QTR_H_

#include "main.h"

#define QTR_COUNT 8

static const int32_t weights[QTR_COUNT] = {
    -500, -400, -200, -50, 50, 200, 400, 500
};


typedef struct QTR QTR;

struct QTR{

    ADC_HandleTypeDef *hadc;
    volatile uint16_t  dmaBuf[QTR_COUNT];

    uint32_t raw[QTR_COUNT];
    uint32_t min[QTR_COUNT];
    uint32_t max[QTR_COUNT];
    uint32_t cal[QTR_COUNT];
    int32_t  lastPosition;
    uint8_t lost;

};


void    qtrInit(QTR* qtr, ADC_HandleTypeDef* hadc);
void    qtrReadRaw(QTR* qtr);
void    qtrCalibrate(QTR* qtr);
void    qtrReadCalibrated(QTR* qtr);
int32_t qtrReadLine(QTR* qtr);

#endif /* INC_QTR_H_ */

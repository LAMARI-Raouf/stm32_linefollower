/*
 * qtr.c
 *
 *  Created on: Oct 2, 2026
 *      Author: Raouf
 */

#include "qtr.h"

void qtrReadRaw(QTR* qtr){

	for (int i = 0; i < QTR_COUNT; i++)
		qtr->raw[i] = qtr->dmaBuf[i];
}

void qtrCalibrate(QTR* qtr){

		qtrReadRaw(qtr);

		for (int i = 0; i < QTR_COUNT; i++){
			qtr->min[i] = (qtr->min[i] > qtr->raw[i]) ? qtr->raw[i] : qtr->min[i];
			qtr->max[i] = (qtr->max[i] < qtr->raw[i]) ? qtr->raw[i] : qtr->max[i];
		}
}



void qtrReadCalibrated(QTR* qtr){
    qtrReadRaw(qtr);

    for (int i = 0; i < QTR_COUNT; i++) {
        int32_t range = (int32_t)qtr->max[i] - (int32_t)qtr->min[i];

        if (range <= 100) { qtr->cal[i] = 0; continue; }

        int32_t calValue = ((int32_t)qtr->raw[i] - (int32_t)qtr->min[i]) * 1000 / range;

        if (calValue < 0)    calValue = 0;
        if (calValue > 1000) calValue = 1000;

        qtr->cal[i] = 1000 - calValue;
    }
}


int32_t qtrReadLine(QTR* qtr)
{
    qtrReadCalibrated(qtr);

    int32_t weighted = 0, sum = 0;
    for (int i = 0; i < QTR_COUNT; i++) {
            weighted += qtr->cal[i] * weights[i];
            sum      += qtr->cal[i];
    }

    if (sum > 200) {
        qtr->lost = 0;
        qtr->lastPosition = weighted / sum;
        return qtr->lastPosition;
    } else {
        qtr->lost = 1;
        return (qtr->lastPosition >= 0) ? 350 : -350;   // lastPosition untouched
    }

    return qtr->lastPosition;
}


void qtrInit(QTR* qtr, ADC_HandleTypeDef* hadc){


	qtr->hadc = hadc;
	qtr->lastPosition = 0;

    for (int i = 0; i < QTR_COUNT; i++) {
        qtr->min[i] = 4095;
        qtr->max[i] = 0;
    }

    HAL_ADC_Start_DMA(qtr->hadc, (uint32_t*)qtr->dmaBuf, QTR_COUNT);

}

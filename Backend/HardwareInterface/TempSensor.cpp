/*
 * TempSensor.cpp
 *
 *  Created on: 23.03.2023
 *      Author: simon
 */

#include "TempSensor.hpp"

#include "main.h"

extern SPI_HandleTypeDef hspi2;

float TempSensor::getTemp() {
	if(status == TEMP_OPEN_CIRCUIT || status == TEMP_DUMMY_SIGN_BIT_1)
		return -10;
	return temp;
}

TempSensorStatus TempSensor::getStatus() {
	return status;
}

void TempSensor::proccess() {
	readTempIC();
	convertICData();
}

void TempSensor::readTempIC() {
	HAL_GPIO_WritePin(TEMP_SPI2_CS_GPIO_Port, TEMP_SPI2_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Receive(&hspi2, (uint8_t*) &ic_data, 1, 100);
	HAL_GPIO_WritePin(TEMP_SPI2_CS_GPIO_Port, TEMP_SPI2_CS_Pin, GPIO_PIN_SET);
}

void TempSensor::convertICData() {
	uint8_t dummySignBit = (ic_data) >> 15;
	uint8_t openFlag = (ic_data & 0b100) >> 2;
	uint16_t tempCode = ic_data >> 3;
	temp = tempCode * 0.25;
	if(openFlag == 1) {
		status = TEMP_OPEN_CIRCUIT;
		return;
	}
	if(dummySignBit == 1) {
		status = TEMP_DUMMY_SIGN_BIT_1;
		return;
	}
	if(temp > 140.0) {
		status = TEMP_OVER_140;
		return;
	}
	if(temp < 5.0) {
		status = TEMP_UNDER_5;
		return;
	}
	status = TEMP_OK;
}

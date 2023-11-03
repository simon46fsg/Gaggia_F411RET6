/*
 * TriacControl.cpp
 *
 *  Created on: 23.03.2023
 *      Author: simon
 */

#include "TriacControl.hpp"
#include "TempSensor.hpp"

extern TempSensor tempSensor;

#include "main.h"

void valve_open() {
	HAL_GPIO_WritePin(CONTROL_VALVE_GPIO_Port, CONTROL_VALVE_Pin, GPIO_PIN_SET);
}

void valve_close() {
	HAL_GPIO_WritePin(CONTROL_VALVE_GPIO_Port, CONTROL_VALVE_Pin, GPIO_PIN_RESET);
}

void pump_turnOn() {
	HAL_GPIO_WritePin(CONTROL_PUMP_GPIO_Port, CONTROL_PUMP_Pin, GPIO_PIN_SET);
}

void pump_turnOff() {
	HAL_GPIO_WritePin(CONTROL_PUMP_GPIO_Port, CONTROL_PUMP_Pin, GPIO_PIN_RESET);
}

//check if there is an issue with anything related to the temperature
void heater_turnOn() {
	if(tempSensor.getStatus() == TEMP_OK)
		HAL_GPIO_WritePin(CONTROL_HEATER_GPIO_Port, CONTROL_HEATER_Pin, GPIO_PIN_SET);
}

void heater_turnOff() {
	HAL_GPIO_WritePin(CONTROL_HEATER_GPIO_Port, CONTROL_HEATER_Pin, GPIO_PIN_RESET);
}



/*
 * Manometer.cpp
 *
 *  Created on: 20.03.2023
 *      Author: simon
 */
#include "Manometer.hpp"

extern ADC_HandleTypeDef hadc1;

float Manometer::getPressure() {
	return pressure;
}

ManometerStatus Manometer::getStatus() {
	return status;
}

void Manometer::proccess() {
	readADC();
	convertAdcValueToPressure();
}

void Manometer::readADC() {
	HAL_ADC_Start(&hadc1);
	adc_data = HAL_ADC_GetValue(&hadc1);
}

/*
 * Sensor output: 0.5V - 4.5V
 * Corresponds to 0bar - 12bar
 */
void Manometer::convertAdcValueToPressure() {
	float sensor_output = (float) adc_data * (3.3 / 0xFFF) * ((4.7 + 10.0) / 10.0); //convert to original voltage range of sensor (0.5V - 4.5V)

	if (sensor_output < 0.45 || sensor_output > 4.55) {
		status = MAN_OUT_OF_RANGE;
		return;
	}

	sensor_output -= 0.5;
	if (sensor_output < 0) {
		sensor_output = 0;
	}
	sensor_output *= 12.0 / 4; //convert to bar
	pressure = sensor_output;
	status = MAN_OK;
}


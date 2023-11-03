/*
 * TemperatureController.hpp
 *
 *  Created on: 30.04.2023
 *      Author: simon
 */
#ifndef FEEDBACKCONTROLSYSTEMS_TEMPERATURECONTROLLER_HPP_
#define FEEDBACKCONTROLSYSTEMS_TEMPERATURECONTROLLER_HPP_

extern "C" {
#include "PID.h"
}

#include "stdint.h"

class TemperatureController {
public:
	void setTargetTemperature(float temp_c);
	float getTargetTemperature();
	void setPowerOffset(float power_offset);
	float getPowerOffset();
	void proccess();
	void init(float init_temp_c);
private:
	float target_temperature = 0;
	float power_offset = 0;
	PIDController pid_controller;
};

#endif /* FEEDBACKCONTROLSYSTEMS_TEMPERATURECONTROLLER_HPP_ */

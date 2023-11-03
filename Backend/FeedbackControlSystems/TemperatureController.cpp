/*
 * TemperatureController.cpp
 *
 *  Created on: 30.04.2023
 *      Author: simon
 */

#include "TemperatureController.hpp"
#include "../HardwareInterface/TempSensor.hpp"
#include "../HardwareInterface/HeaterControl.hpp"

extern TempSensor tempSensor;
extern HeaterControl heaterControl;

void TemperatureController::setTargetTemperature(float temp_c) {
	if(temp_c < 0) target_temperature = 0;
	else if(temp_c > 130) target_temperature = 130;
	else target_temperature = temp_c;
}

float TemperatureController::getTargetTemperature() {
	return target_temperature;
}

void TemperatureController::proccess() {
	PIDController_Update(&pid_controller, target_temperature, tempSensor.getTemp());
	heaterControl.setPower((uint8_t) (pid_controller.out + power_offset));
}

void TemperatureController::init(float init_temp_c) {
	setTargetTemperature(init_temp_c);
	//shall be as an PI Controller
	pid_controller.Kd = 0;
	pid_controller.Ki = 0.1;
	pid_controller.Kp = 2;
	pid_controller.T = 0.25;
	pid_controller.limMax = 32.0;
	pid_controller.limMaxInt = 4;
	pid_controller.limMin = 0;
	pid_controller.limMinInt = 0;
	pid_controller.tau = 0;
	PIDController_Init(&pid_controller);
}

void TemperatureController::setPowerOffset(float power_offset) {
	power_offset < 0 ? this->power_offset = 0 : 0;
	power_offset > 32 ? this->power_offset = 32 : 0;
	this->power_offset = power_offset;
}

float TemperatureController::getPowerOffset() {
}

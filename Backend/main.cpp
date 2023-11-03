/*
 * main.cpp
 *
 *  Created on: 23.03.2023
 *      Author: simon
 */
#include "HardwareInterface/HeaterControl.hpp"
#include "HardwareInterface/Manometer.hpp"
#include "HardwareInterface/PumpControl.hpp"
#include "HardwareInterface/TempSensor.hpp"
#include "HardwareInterface/TriacControl.hpp"
#include "FeedbackControlSystems/TemperatureController.hpp"
#include "main.h"

extern "C" {
void mainInit();
void mainLoop();
void zeroCrossCallback();
void timer1Callback();
void timer2Callback();
void timer16Callback();
void timer17Callback();
}

extern TIM_HandleTypeDef htim1;

PumpControl16Lvl pumpControl;
HeaterControl heaterControl;
TempSensor tempSensor;
Manometer manometer;
TemperatureController temperatureController;

volatile uint32_t start_time;
volatile uint32_t time;

void mainInit() {
	valve_close();
	pumpControl.setPulseLevel(0);
	heaterControl.setPower(0);
	temperatureController.init(100);
}

void mainLoop() {

}

void zeroCrossCallback() {
	pumpControl.proccess();
	heaterControl.proccess();
	HAL_TIM_Base_Start_IT(&htim1);
}

/*
 * this time is set to overflow at roughly 5ms after a zero cross
 * the triacs wont turn off here but a the new zero cross
 */
void timer1Callback() {
	pump_turnOff();
	heater_turnOff();
	HAL_TIM_Base_Stop_IT(&htim1);
}

//touchgfx timer 20hz
void timer2Callback() {

}

//heater on timer (one shot)
void timer16Callback() {
}

//sensor timer 4hz
void timer17Callback() {
	tempSensor.proccess();
	manometer.proccess();
	temperatureController.proccess();
}




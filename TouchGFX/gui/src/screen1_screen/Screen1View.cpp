//#include <gui/screen1_screen/Screen1View.hpp>
//
//#include "../../Hardware_Interface/temp_sensor.h"
//#include "../../Hardware_Interface/pressure_sensor.h"
//
//extern TemperatureSensor temperatureSensor;
//extern PressureSensor pressureSensor;
//
//Screen1View::Screen1View()
//{
//
//}
//
//void Screen1View::setupScreen()
//{
//    Screen1ViewBase::setupScreen();
//}
//
//void Screen1View::tearDownScreen()
//{
//    Screen1ViewBase::tearDownScreen();
//}
//
//void Screen1View::startStopWatch() {
//	if(stopWatchIsRunning) {
//		stopWatchIsRunning = false;
//	}else{
//		stopWatchIsRunning = true;
//	}
//}
//
//void Screen1View::resetStopWatch() {
//	stopWatchIsRunning = false;
//	stopWatchTime = 0;
//	brewing_data1.updateTimer(stopWatchTime);
//}
//
//void Screen1View::handleTickEvent() {
//	static uint8_t i = 0;
//	i++;
//	if(stopWatchIsRunning) {
//		stopWatchTime += 0.05;
//		brewing_data1.updateTimer(stopWatchTime);
//	}
//	if (i == 20) {
//		brewing_data1.updateTempData(temperatureSensor.temp);
//		brewing_data1.updatePressureData(pressureSensor.pressure);
//		i = 0;
//	}
//	brewing_data1.invalidate();
//
//
//}

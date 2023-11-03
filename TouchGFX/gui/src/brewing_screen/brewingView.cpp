#include <gui/brewing_screen/brewingView.hpp>

#include "../../../../Backend/HardwareInterface/Manometer.hpp"
#include "../../../../Backend/HardwareInterface/PumpControl.hpp"
#include "../../../../Backend/HardwareInterface/TempSensor.hpp"
#include "../../../../Backend/HardwareInterface/TriacControl.hpp"
#include "../../../../Backend/HardwareInterface/HeaterControl.hpp"
#include "../../../../Backend/FeedbackControlSystems/TemperatureController.hpp"

extern PumpControl16Lvl pumpControl;
extern Manometer manometer;
extern TempSensor tempSensor;
extern TemperatureController temperatureController;
extern HeaterControl heaterControl;

brewingView::brewingView() {

}

void brewingView::setupScreen() {
	brewingViewBase::setupScreen();
}

void brewingView::tearDownScreen() {
	brewingViewBase::tearDownScreen();
}

void brewingView::handleTickEvent() {
	if (is_brewing) {
		if (brewing_time < set_brewing_time) {
			brewing_time += 0.05;
		} else {
			is_brewing = false;
			valve_close();
			brewing_time = 0;
		}
	}
	brewing_data.updateTempData(tempSensor.getTemp());
	brewing_data.updateTimer(brewing_time);
	brewing_data.updatePressureData(manometer.getPressure());
	Unicode::snprintf(heater_infoBuffer, HEATER_INFO_SIZE, "%d", heaterControl.getPowerLvl());
	Unicode::snprintf(pump_infoBuffer, PUMP_INFO_SIZE, "%d", pumpControl.getPulseLevel());
	heater_info.invalidate();
	pump_info.invalidate();
}

void brewingView::startStopBrew() {
	if (!is_brewing) {
		brewing_time = 0;
		is_brewing = true;
		pumpControl.setPulseLevel(16);
		valve_open();
	} else {
		is_brewing = false;
		pumpControl.setPulseLevel(0);
		valve_close();
	}
}

void brewingView::flushWand() {
	if (!is_flushing_wand) {
		is_flushing_wand = true;
		pump_turnOn();
	} else {
		is_flushing_wand = false;
		pump_turnOff();
	}
}

void brewingView::increaseTemp() {
	uint8_t target_temp = 0;
	target_temp = (uint8_t) temperatureController.getTargetTemperature();
	target_temp < 120 ? target_temp++ : target_temp = 0;
	Unicode::snprintf(set_temp_textBuffer, SET_TEMP_TEXT_SIZE, "%d",
			target_temp);
	set_temp_text.invalidate();
	temperatureController.setTargetTemperature((float) target_temp);
}

void brewingView::decreaseTemp() {
	uint8_t target_temp = 0;
	target_temp = (uint8_t) temperatureController.getTargetTemperature();
	target_temp > 0 ? target_temp-- : target_temp = 120;
	Unicode::snprintf(set_temp_textBuffer, SET_TEMP_TEXT_SIZE, "%d",
			target_temp);
	set_temp_text.invalidate();
	temperatureController.setTargetTemperature((float) target_temp);
}

void brewingView::increaseTime() {
	set_brewing_time++;
	Unicode::snprintf(set_time_textBuffer, SET_TIME_TEXT_SIZE, "%d",
			set_brewing_time);
	set_time_text.invalidate();
	pumpControl.setPulseLevel(set_brewing_time);
}

void brewingView::decreaseTime() {
	set_brewing_time--;
	Unicode::snprintf(set_time_textBuffer, SET_TIME_TEXT_SIZE, "%d",
			set_brewing_time);
	set_time_text.invalidate();
	pumpControl.setPulseLevel(set_brewing_time);
}

void brewingView::decreasePump() {
	uint8_t pump_lvl = 0;
	pump_lvl = pumpControl.getPulseLevel();
	pump_lvl > 0 ? pump_lvl-- : pump_lvl = 16;
	pumpControl.setPulseLevel(pump_lvl);
}

void brewingView::increasePump() {
	uint8_t pump_lvl = 0;
	pump_lvl = pumpControl.getPulseLevel();
	pump_lvl < 16 ? pump_lvl++ : pump_lvl = 0;
	pumpControl.setPulseLevel(pump_lvl);
}

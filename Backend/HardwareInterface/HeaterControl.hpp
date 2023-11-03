/*
 * HeaterControl.hpp
 *
 *  Created on: 06.04.2023
 *      Author: simon
 */

#ifndef HEATERCONTROL_HPP_
#define HEATERCONTROL_HPP_

#include "main.h"

class HeaterControl {
public:
	void setPower(uint8_t power);
	uint8_t getPowerLvl();
	void proccess();	//call this at zerocross
private:
	static uint32_t control_sequence[33];
	uint8_t control_index = 32;
	uint8_t power_level = 0;
	uint8_t queued_power_level = 0;
	bool heater_state = false;	//true means the pump is on
};

#endif /* HEATERCONTROL_HPP_ */

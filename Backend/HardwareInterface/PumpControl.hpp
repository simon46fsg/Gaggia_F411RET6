/*
 * PumpControl.hpp
 *
 *  Created on: 21.03.2023
 *      Author: simon
 */

#ifndef PUMPCONTROL_HPP_
#define PUMPCONTROL_HPP_

#include "main.h"

class PumpControl16Lvl {
public:
	void setPulseLevel(uint8_t level);
	uint8_t getPulseLevel();
	void proccess();	//call this at zerocross
	bool getPumpState();
private:
	static uint16_t control_sequence[17];
	uint8_t control_index = 16;
	uint8_t power_level = 0;
	uint8_t queued_power_level = 0;
	bool pump_state = false;	//true means the pump is on
};



#endif /* PUMPCONTROL_HPP_ */

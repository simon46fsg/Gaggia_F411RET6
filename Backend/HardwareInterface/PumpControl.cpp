/*
 * PumpControl.cpp
 *
 *  Created on: 21.03.2023
 *      Author: simon
 */

#include "PumpControl.hpp"

#include "TriacControl.hpp"

uint16_t PumpControl16Lvl::control_sequence[17] = {
	0b0000000000000000,
	0b1000000000000000,
	0b1000000010000000,
	0b1000010000100000,
	0b1000100010001000,
	0b1001001001001000,
	0b1001001001001001,
	0b1010101010101000,
	0b1010101010101010,
	0b1110101010101010,
	0b1110101011101010,
	0b1110111011101010,
	0b1110111011101110,
	0b1111111011101110,
	0b1111111011111110,
	0b1111111111111110,
	0b1111111111111111,
};

/*
 * The power level get queued. It is only assigned when the old sequence is done.
 * This shall prevent unexpected behavior.
 */
void PumpControl16Lvl::setPulseLevel(uint8_t level) {
	if(level > 16) {
		queued_power_level = 16;
		return;
	}
	if(level < 0) {
		queued_power_level = 0;
		return;
	}
	queued_power_level = level;
}

uint8_t PumpControl16Lvl::getPulseLevel() {
	return queued_power_level;
}

bool PumpControl16Lvl::getPumpState() {
	return pump_state;
}

void PumpControl16Lvl::proccess() {
	pump_state ? pump_turnOn() : pump_turnOff();
	/*
	 * Function shall only be executed every second time,
	 * because there are two zero crossing detections per period.
	 */
	static bool every_second_function_entry = true;
	(every_second_function_entry) ? every_second_function_entry = false : every_second_function_entry = true;

	if (every_second_function_entry) {
		if (control_index >= 15) {
			control_index = 0;
			power_level = queued_power_level; //only gets assigned when the sequence is done
		} else
			control_index++;
		pump_state = control_sequence[power_level] & (1 << control_index);
	}
}



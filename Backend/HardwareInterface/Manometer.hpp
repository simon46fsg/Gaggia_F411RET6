/*
 * Manometer.hpp
 *
 *  Created on: 20.03.2023
 *      Author: simon
 */

#ifndef MANOMETER_HPP_
#define MANOMETER_HPP_

#include "main.h"

enum ManometerStatus {
	MAN_OK, MAN_OUT_OF_RANGE, MAN_ADC_ERROR
};

class Manometer {
public:
	float getPressure();	//get pressure in bar
	ManometerStatus getStatus();
	void proccess();
private:
	float pressure = 0.0;
	ManometerStatus status = MAN_OK;
	uint16_t adc_data = 0;
	void readADC();
	void convertAdcValueToPressure();
};



#endif /* MANOMETER_HPP_ */

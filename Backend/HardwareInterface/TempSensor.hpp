/*
 * TempSensor.hpp
 *
 *  Created on: 23.03.2023
 *      Author: simon
 */

#ifndef TEMPSENSOR_HPP_
#define TEMPSENSOR_HPP_

#include "stdint.h"

enum TempSensorStatus {
	TEMP_OK,
	TEMP_OVER_140,
	TEMP_UNDER_5,
	TEMP_OPEN_CIRCUIT,
	TEMP_DUMMY_SIGN_BIT_1,
};

class TempSensor {
public:
	float getTemp();
	TempSensorStatus getStatus();
	void proccess();
private:
	TempSensorStatus status = TEMP_OK;
	float temp = 0;
	uint16_t ic_data= 0;
	void readTempIC();
	void convertICData();
};



#endif /* TEMPSENSOR_HPP_ */

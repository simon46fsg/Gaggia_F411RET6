#include <gui/containers/Brewing_data.hpp>

Brewing_data::Brewing_data()
{

}

void Brewing_data::initialize()
{
    Brewing_dataBase::initialize();
}

void Brewing_data::updateTempData(float temp) {
	Unicode::snprintfFloat(temperatureBuffer, TEMPERATURE_SIZE, "%2.2f", temp);
	temperature.invalidate();
}

void Brewing_data::updatePressureData(float pressureVal) {
	Unicode::snprintfFloat(pressureBuffer, PRESSURE_SIZE, "%2.1f", pressureVal);
	pressure.invalidate();
}

void Brewing_data::updateTimer(float seconds) {
	Unicode::snprintfFloat(timerBuffer, TIMER_SIZE, "%4.2f", seconds);
	timer.invalidate();
}

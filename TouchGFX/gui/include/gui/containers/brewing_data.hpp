#ifndef BREWING_DATA_HPP
#define BREWING_DATA_HPP

#include <gui_generated/containers/Brewing_dataBase.hpp>

class Brewing_data : public Brewing_dataBase
{
public:
    Brewing_data();
    virtual ~Brewing_data() {}

    virtual void initialize();

    void updateTempData(float temp);
    void updatePressureData(float pressureVal);
    void updateTimer(float seconds);
protected:
};

#endif // BREWING_DATA_HPP

#ifndef BREWINGVIEW_HPP
#define BREWINGVIEW_HPP

#include <gui_generated/brewing_screen/brewingViewBase.hpp>
#include <gui/brewing_screen/brewingPresenter.hpp>

class brewingView : public brewingViewBase
{
public:
    brewingView();
    virtual ~brewingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void handleTickEvent();
    void startStopBrew();
    void flushWand();
    void increaseTemp();
    void decreaseTemp();
    void increaseTime();
    void decreaseTime();
    void increasePump();
    void decreasePump();

    bool is_brewing = false;
    bool is_flushing_wand = false;
    float brewing_time = 0;
    uint8_t set_brewing_time = 30;
protected:
};

#endif // BREWINGVIEW_HPP

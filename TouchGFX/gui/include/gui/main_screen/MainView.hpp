#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
protected:
    int tickCounter;
    int digitalHours;
    int digitalMinutes;
    int digitalSeconds;
};

#endif // MAINVIEW_HPP

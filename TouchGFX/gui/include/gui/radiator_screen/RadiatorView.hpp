#ifndef RADIATORVIEW_HPP
#define RADIATORVIEW_HPP

#include <gui_generated/radiator_screen/RadiatorViewBase.hpp>
#include <gui/radiator_screen/RadiatorPresenter.hpp>

class RadiatorView : public RadiatorViewBase
{
public:
    RadiatorView();
    virtual ~RadiatorView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void buttonUpClicked();
    virtual void buttonDownClicked();
    void handleTickEvent();
protected:
    int counter=20;
    int tickCounter;
    float startingValue=15;
    float cur_temp = 15;
    float pente;
};

#endif // RADIATORVIEW_HPP

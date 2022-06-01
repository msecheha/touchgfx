#include <gui/main_screen/MainView.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
    digitalHours = digitalClock1.getCurrentHour();
    digitalMinutes = digitalClock1.getCurrentMinute();
    digitalSeconds = digitalClock1.getCurrentSecond();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::handleTickEvent()
{
    tickCounter++;

    if (tickCounter % 60 == 0)
    {
        if (++digitalSeconds >= 60)
        {
            digitalSeconds = 0;
            if (++digitalMinutes >= 60)
            {
                digitalMinutes = 0;
                if (++digitalHours >= 24)
                {
                    digitalHours = 0;
                }
            }
        }

        // Update the clock
        digitalClock1.setTime24Hour(digitalHours, digitalMinutes, digitalSeconds);
    }
}

#include <gui/radiator_screen/RadiatorView.hpp>
#include <math.h>

RadiatorView::RadiatorView()
{
	tickCounter=0;
	dynamicGraph2.addDataPoint(startingValue);
}

void RadiatorView::setupScreen()
{
    RadiatorViewBase::setupScreen();
}

void RadiatorView::tearDownScreen()
{
    RadiatorViewBase::tearDownScreen();
}

void RadiatorView::buttonUpClicked()
{
	if (counter<30){
		counter++;
		Unicode::snprintf(textCounterBuffer, TEXTCOUNTER_SIZE, "%d", counter);
		// Invalidate text area, which will result in it being redrawn in next tick.
		textCounter.invalidate();
	}
}

void RadiatorView::buttonDownClicked()
{
	if (counter>0){
		counter--;
		Unicode::snprintf(textCounterBuffer, TEXTCOUNTER_SIZE, "%d", counter);
		// Invalidate text area, which will result in it being redrawn in next tick.
		textCounter.invalidate();
	}
}

void RadiatorView::handleTickEvent()
{
	tickCounter = tickCounter + 1;

	if (tickCounter % 3 == 0){
		dynamicGraph1.addDataPoint(counter);
		if (cur_temp < counter - 2){
			pente = 0.5;
		}
		else if (cur_temp > counter + 2){
			pente = -0.1;
		}
		cur_temp = cur_temp + pente;
		dynamicGraph2.addDataPoint(cur_temp);
	}
}

#include "idletimeout.h"
#include "powermanager.h"
#include "ui.h"
#include "buttonmanager.h"
#include "haptic.h"
#include "battery.h"

unsigned IdleTimeout::ticker;
bool IdleTimeout::userDisabled;

void IdleTimeout::onButtonEvent(Button *b, Button::Event e)
{
    /*
     * Look for a button combo to disable idle timeout.
     */

    UNUSED(b);
    UNUSED(e);

    if (userDisabled) {
        return;
    }


    if (ButtonManager::button(Io::ButtonPreset1).isHeldShort() &&
        ButtonManager::button(Io::ButtonPreset2).isHeldShort())
    {
	Ui::instance.pendEvent(Event::IdleTimeoutDisabled);
	userDisabled = true;
    }


}

bool IdleTimeout::enabled()
{
    /*
     * states in which we should disable countdown;
     */

    if (userDisabled) {
        return false;
    }

    if (Ui::instance.state() == Ui::Updater) {
        return false;
    }

    if (FlightManager::instance.linkIsConnected()) {
        return false;
    }

	// if the battery charger is connected, don't idletimeout
    if (Battery::instance.chargerIsPresent()) {
	return false;
    }

    return true;
}

void IdleTimeout::tick()
{
    if (!enabled()) {
        reset();
        return;
    }

    switch (++ticker) {
    case IDLE_WARN:
        Ui::instance.pendEvent(Event::SystemIdleWarning);
        break;

    case IDLE_TIMEOUT:
	PowerManager::shutdown();
        break;
    }
}

void IdleTimeout::reset()
{
    if (Ui::instance.alertManager.currentEvent() == Event::SystemIdleWarning) {
        Ui::instance.alertManager.dismiss();
    }

    ticker = 0;
}

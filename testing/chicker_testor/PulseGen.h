/* Single pulse generator class using the teensy AMR timer tools library

  inputs:
    delayTimer: time between "triggering" and pulse generation
    durationTimer: length of pulse

  Author: Simon Zheng
  */

#include "Arduino.h"
#include "TeensyTimerTool.h"

using namespace TeensyTimerTool;

class PulseGen
{
public:
    PulseGen() : delayTimer(TCK), durationTimer(TCK) // use the tick timers for this task, we have 20 per default, can be increased in config
    {
    }

    void begin(unsigned pin, unsigned delay, unsigned duration)
    {
        this->pin = pin;
        this->delay = delay;
        this->duration = duration;

        pinMode(pin, OUTPUT);
        delayTimer.begin([this] { digitalWriteFast(this->pin,HIGH); this->durationTimer.trigger(this->duration) ; });
        durationTimer.begin([this] { digitalWriteFast(this->pin, LOW); });
    }

    void trigger() { delayTimer.trigger(delay); }

protected:
    unsigned pin, delay, duration;
    OneShotTimer delayTimer, durationTimer;
};

#include "TeensyTimerTool.h"
#include "PulseGen.h"

volatile bool kick_cooldown = true; // flag for kicker grace period, initial TRUE for safety
volatile bool kick = false;

const unsigned TRIG_INDICATOR_PIN = 12;  // pin to indicate when triggering occurs
const unsigned KICKER_PIN = 2;
const unsigned KICK_DELAY = 1'000;        // delay (us)
const unsigned KICK_POWER = 1000;         // pulse width (us)
const unsigned KICK_GRACE_MIN = 100'000;  // minimum time between kicks (us)
const unsigned KICK_INTERRUPT = 30;       // kicker button pin

PulseGen kicker;
IntervalTimer kicker_grace_timer;

void trigger(PulseGen pulse_gen)
{
  digitalWriteFast(TRIG_INDICATOR_PIN, HIGH);

  pulse_gen.trigger();

  digitalWriteFast(TRIG_INDICATOR_PIN, LOW);
}

void kick_ISR()
{
  if(!kick_cooldown){
    kick_cooldown = true;
    kicker.trigger();
    kicker_grace_timer.begin(kick_grace_ISR, KICK_GRACE_MIN);
  }
}

void kick_grace_ISR()
{
  kicker_grace_timer.end();
  kick_cooldown = false;
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_INDICATOR_PIN, OUTPUT);
  pinMode(KICK_INTERRUPT, INPUT_PULLDOWN);
  // TODO: setup serial parsing from PC

  attachInterrupt(digitalPinToInterrupt(KICK_INTERRUPT), kick_ISR, RISING);

  kicker.begin(KICKER_PIN, KICK_DELAY, KICK_POWER);

  kick_cooldown = false;
}

void loop()
{

}

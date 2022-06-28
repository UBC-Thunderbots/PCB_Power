#include <Arduino.h>

int HV_SENSE = 36;
int FAULT = 27;
int DONE = 26;
int CHRG = 25;

hw_timer_t * timer = NULL; 

const int GPIO_PIN = 32; //kicking pin

/**
 * Creates a pulse for a given duration.
 *
 * @param duration the duration of the pulse in microseconds.
 */
void oneShotPulse(int duration) {
  timerWrite(timer, 0);
  timerAlarmWrite(timer, duration, false); 
  timerAlarmEnable(timer);

  digitalWrite(GPIO_PIN, HIGH);
}

/**
 * Helper function that ends a pulse.
 */
void IRAM_ATTR stopPulse() {
  digitalWrite(GPIO_PIN, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(HV_SENSE, INPUT);
  pinMode(DONE, INPUT);
  pinMode(FAULT, INPUT);
  pinMode(CHRG, OUTPUT);
  pinMode(GPIO_PIN, OUTPUT);
  //digitalWrite(CHRG, HIGH);

  timer = timerBegin(0, 80, true); 
  timerAttachInterrupt(timer, &stopPulse, true);
}

void loop() {
  // put your main code here, to run repeatedly
  int pulse_width = 0;
  do {
    pulse_width = Serial.parseInt();
    delay(50);
  } while (pulse_width == 0);

  Serial.print("Charging to kick at ");
  Serial.println(pulse_width);

//  if (pulse_width > 4000)
//  {
//    Serial.println("Pulse width is greater than 4000");
//    return;
//  }

  digitalWrite(CHRG, HIGH);
  //delay(1000);
  //digitalWrite(CHRG, LOW);
  
  Serial.println("Going to kick in 3 seconds, standback");
  delay(3000);
  //oneShotPulse(pulse_width);
  Serial.println("Kicked");
  
}

int HVmeasure(int HV_SENSE){
  return analogRead(HV_SENSE);
}

bool ChargeCap(int CHRG, int FAULT, int DONE, int HV_SENSE){
  digitalWrite(CHRG, HIGH);
  Serial.println("ChargeHigh");
  while (digitalRead(DONE) == HIGH){
    //Serial.println(HVmeasure(HV_SENSE));
    if (digitalRead(FAULT) == LOW){
      Serial.println("FAIL");
      digitalWrite(CHRG,LOW);
      return false;
    }
  }
  digitalWrite(CHRG, LOW);
  return true;
}

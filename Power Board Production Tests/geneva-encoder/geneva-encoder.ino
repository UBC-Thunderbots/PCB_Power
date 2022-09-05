int ENC_A = 18;
int ENC_B = 5;
int prev_count = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_A), increment_count, RISING);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (prev_count != count)
  {
    if(digitalRead(ENC_B) == HIGH)
    {
      Serial.println("counterclockwise");
    }
    else
    {
      Serial.println("clockwise");
    }
    prev_count = count;
  }
  else
  {
    Serial.println("still");
  }
  //Serial.println(digitalRead(ENC_A));
}

void increment_count()
{
    count += 1;
}

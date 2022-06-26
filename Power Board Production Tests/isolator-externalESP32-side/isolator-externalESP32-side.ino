int HB = 5;
int ESP_TX = 9;
int ESP_RX = 35;
int time_delay = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(HB, OUTPUT);
  pinMode(ESP_TX, OUTPUT);
  pinMode(ESP_RX, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(HB,HIGH);
  digitalWrite(ESP_TX, HIGH);
  Serial.println(digitalRead(ESP_RX));
  delay(time_delay);
  digitalWrite(HB,LOW);
  digitalWrite(ESP_TX, LOW);
  Serial.println(digitalRead(ESP_RX));
  delay(time_delay);
  
}

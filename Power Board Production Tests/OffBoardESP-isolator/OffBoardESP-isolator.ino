int HB = 5;
int ESP_TX = 9;
int ESP_RX = 35;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600,SERIAL_8N1,ESP_RX,ESP_TX);
}

void loop() {
  // put your main code here, to run repeatedly:
  String received = "";
  while (Serial.available())
  {
    received = Serial.read();
    Serial.println(received);
  }
}

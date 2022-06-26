int J_TX = 22;
int J_RX = 19;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600,SERIAL_8N1,J_RX,J_TX);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Test..");
  delay(1000);
}

int J_TX = 22;
int J_RX = 19;

int time_delay = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(J_TX, OUTPUT);
  pinMode(J_RX, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(J_TX,HIGH);
  Serial.println(digitalRead(J_RX));
  delay(time_delay);
  digitalWrite(J_TX,LOW);
  Serial.println(digitalRead(J_RX));
  delay(time_delay);
  // put your main code here, to run repeatedly:

}

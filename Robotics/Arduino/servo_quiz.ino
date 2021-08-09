int servoPin = 9;
int angle = 180;
int mapped = map(angle, 0, 180, 500, 3000);
void setup() {
  // put your setup code here, to run once:
 pinMode(servoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(servoPin, HIGH);
 delayMicroseconds(mapped);
 digitalWrite(servoPin, LOW);
 delay(10);
}

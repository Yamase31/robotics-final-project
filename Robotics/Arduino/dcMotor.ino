int pwm = 10;
int in1 = 9;
int in2 = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm, 150);
}

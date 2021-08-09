int led = 7;
int grd = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(grd,OUTPUT);
//digitalWrite(grd,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(grd,LOW);
digitalWrite(led,HIGH);
delay(10);
digitalWrite(led,LOW);
delay(10);
}

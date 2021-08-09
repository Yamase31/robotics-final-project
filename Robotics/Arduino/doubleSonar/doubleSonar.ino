
int trigPin1 = 10;    // Trigger
int echoPin1 = 11;    // Echo
int trigPin2 = 12;
int echoPin2 = 13;
int trigPin3 = 9;
int echoPin3 = 8;
long duration1, duration2,duration3, inches1, inches2, inches3;
//int green = 3;
//int yellow = 5;
//int red = 6;
int led1 = 3;
int led2 = 2;
int led3 = 4;

void setup() {
  // put your setup code here, to run once:
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT); 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // send and read signal for sonar 1:
digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);

  // send and read signal for sonar 2:
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

  
  // send and read signal for sonar 2:
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin3, INPUT);
  duration3 = pulseIn(echoPin3, HIGH);

  inches1 = (duration1/2) / 74;
  inches2 = (duration2/2) / 74;
  inches3 = (duration3/2) / 74;

  if(inches1 <= 2) digitalWrite(led1,HIGH);
  else digitalWrite(led1,LOW);
  if(inches2 <= 2) digitalWrite(led2,HIGH);
  else digitalWrite(led2,LOW);
  if(inches3 <= 5) digitalWrite(led3,HIGH);
  else digitalWrite(led3,LOW);

  Serial.print("Sonar 1: ");
  Serial.print(inches1);
  Serial.print(",   Sonar 2: ");
  Serial.print(inches2);
  Serial.print(",   Sonar 3: ");
  Serial.print(inches3);
  Serial.println();

  delay(150);
}

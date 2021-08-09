// Motor A
int motor1Pin1 = 10; 
int motor1Pin2 = 9; 
int enable1Pin = 11; 
// Motor B 
int motor2Pin1 = 5; 
int motor2Pin2 = 6; 
int enable2Pin = 7; 
int power = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  pinMode(power, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(power, HIGH); 
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(5000);

  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(2000);

  
}

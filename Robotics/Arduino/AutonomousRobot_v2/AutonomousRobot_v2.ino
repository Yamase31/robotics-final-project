// Motor Relevant Variables
const int Right_Motor_Pin1 = 6;
const int Right_Motor_Pin2 = 7;
const int Left_Motor_Pin1 = 3;
const int Left_Motor_Pin2 = 4;
const int Right_Motor_PWM = 8;
const int Left_Motor_PWM = 5;

// Ultrasonic Relevant Variables
const int Left_Trig_Pin = 53;
const int Left_Echo_Pin = 52;
const int Front_Trig_Pin = 51;
const int Front_Echo_Pin = 50;
const int Right_Trig_Pin = 49;
const int Right_Echo_Pin = 48;

long duration, inches;
bool test = false;

// This doesn't seem to do anything
int power = 12;

void setup() {
  // put your setup code here, to run once:

  //Initialize USB for testing
  Serial.begin(9600);
  
  //Right Motor Pins Initialized as OUTPUT
  pinMode(Right_Motor_Pin1, OUTPUT);
  pinMode(Right_Motor_Pin2, OUTPUT);
  //Left Motor Pins Initialized as OUTPUT
  pinMode(Left_Motor_Pin1, OUTPUT);
  pinMode(Left_Motor_Pin2, OUTPUT);
  //ENABLE PWM
  pinMode(Right_Motor_PWM, OUTPUT);
  pinMode(Left_Motor_PWM, OUTPUT);

  // Ultrasonic Sensor Setup
  pinMode(Left_Trig_Pin,OUTPUT);
  pinMode(Left_Echo_Pin,INPUT);
  pinMode(Front_Trig_Pin,OUTPUT);
  pinMode(Front_Echo_Pin,INPUT);
  pinMode(Right_Trig_Pin,OUTPUT);
  pinMode(Right_Echo_Pin,INPUT);

  //POWER
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);

  //Set Initial Direction
  digitalWrite(Right_Motor_Pin1, HIGH);
  digitalWrite(Right_Motor_Pin2, LOW);
  digitalWrite(Left_Motor_Pin1, HIGH);
  digitalWrite(Left_Motor_Pin2, LOW);
}

// MOTOR FUNCTIONS

void forward(int pwm = 200) {
  digitalWrite(Right_Motor_Pin1, HIGH);
  digitalWrite(Right_Motor_Pin2, LOW);
  digitalWrite(Left_Motor_Pin1, HIGH);
  digitalWrite(Left_Motor_Pin2, LOW);
  analogWrite(Right_Motor_PWM, pwm);
  analogWrite(Left_Motor_PWM, pwm);
}

void reverse(int pwm = 200) {
  digitalWrite(Right_Motor_Pin1, LOW);
  digitalWrite(Right_Motor_Pin2, HIGH);
  digitalWrite(Left_Motor_Pin1, LOW);
  digitalWrite(Left_Motor_Pin2, HIGH);
  analogWrite(Right_Motor_PWM, pwm);
  analogWrite(Left_Motor_PWM, pwm);
}

void rightTurn(int pwm = 80, bool quick = false) {
  // Drive forward left motor
  analogWrite(Left_Motor_PWM, pwm);
  analogWrite(Right_Motor_PWM, 0);
  // If quick turn
  if (quick) {
    // Reverse Right Motor Polarity
    digitalWrite(Right_Motor_Pin1, LOW);
    digitalWrite(Right_Motor_Pin2, HIGH);
    analogWrite(Right_Motor_PWM, pwm);
  }
}

void leftTurn(int pwm = 80, bool quick = false) {
  // Drive forward right motor
  analogWrite(Right_Motor_PWM, pwm);
  analogWrite(Left_Motor_PWM, 0);
  // If quick turn
  if (quick) {
    digitalWrite(Left_Motor_Pin1, LOW);
    digitalWrite(Left_Motor_Pin2, HIGH);
    analogWrite(Left_Motor_PWM, pwm);
  }
}

// ULTRASONIC SENSOR FUNCTIONS

int nextObjectFront() {
  // Send Signal
  digitalWrite(Front_Trig_Pin, LOW);
  delayMicroseconds(1000);
  digitalWrite(Front_Trig_Pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(Front_Trig_Pin, LOW);

  // Read Signal
  duration = pulseIn(Front_Echo_Pin, HIGH);
  // Return value
  Serial.println("Front: " +  String((duration / 2) / 74));
  return ((duration / 2) / 74);
}

void nextObjectRight() {
  // Send Signal
  digitalWrite(Right_Trig_Pin, LOW);
  delayMicroseconds(1000);
  digitalWrite(Right_Trig_Pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(Right_Trig_Pin, LOW);

  // Read Signal
  duration = pulseIn(Right_Echo_Pin, HIGH);
  // Return value
  Serial.println("Right: " +  String((duration / 2) / 74));
  return ((duration / 2) / 74);
}

void nextObjectLeft() {
  // Send Signal
  digitalWrite(Left_Trig_Pin, LOW);
  delayMicroseconds(1000);
  digitalWrite(Left_Trig_Pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(Left_Trig_Pin, LOW);

  // Read Signal
  duration = pulseIn(Left_Echo_Pin, HIGH);
  // Return value
  Serial.println("Left: " +  String((duration / 2) / 74));
  return ((duration / 2) / 74);
}

void loop() {
//  forward(255);
//  delay(2000);
//  reverse();
//  delay(2000);
//  rightTurn();4
//  leftTurn();
//  nextObjectFront();
//  nextObjectLeft();
//  nextObjectRight();
//  if (nextObjectFront() < 10) {
//    reverse();
//  }
  delay(20000);
  if ( test != true) {
    for(int i = 0; i < 3; i ++) {
      forward(100);
    }
  }
  test = true;
}

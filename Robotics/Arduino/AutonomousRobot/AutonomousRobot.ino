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

void stop() {
  analogWrite(Right_Motor_PWM, 0);
  analogWrite(Left_Motor_PWM, 0);
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

void rightWheelTurnPower(int pwm) {
  analogWrite(Right_Motor_PWM, pwm);
}

void leftWheelTurnPower(int pwm) {
  analogWrite(Left_Motor_PWM, pwm);
}

void correctCourse() {
  while(abs(nextObjectLeft() - nextObjectRight()) > 3) {
    if (nextObjectLeft() > nextObjectRight()) {
      // Left Correction
    } else {
      // Right Correction
    }
  }
}

// ULTRASONIC SENSOR FUNCTIONS

int nextObjectFront() {
  // Send Signal
  digitalWrite(Front_Trig_Pin, LOW);
  delayMicroseconds(5);
  digitalWrite(Front_Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Front_Trig_Pin, LOW);

  // Read Signal
  duration = pulseIn(Front_Echo_Pin, HIGH);
  // Return value
  Serial.println((duration / 2) / 74);
  return (duration / 2) / 74;
}

int nextObjectRight() {
  // Send Signal
  digitalWrite(Right_Trig_Pin, LOW);
  delayMicroseconds(5);
  digitalWrite(Right_Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Right_Trig_Pin, LOW);

  // Read Signal
  duration = pulseIn(Right_Echo_Pin, HIGH);
  // Return value
  Serial.println((duration / 2) / 74);
  return (duration / 2) / 74;
}

int nextObjectLeft() {
  // Send Signal
  digitalWrite(Left_Trig_Pin, LOW);
  delayMicroseconds(5);
  digitalWrite(Left_Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Left_Trig_Pin, LOW);

  // Read Signal
  duration = pulseIn(Left_Echo_Pin, HIGH);
  // Return value
  Serial.println((duration / 2) / 74);
  return (duration / 2) / 74;
  
}

void loop() {
//  forward(255);
//  delay(2000);
//  reverse();
//  delay(2000);
//  rightTurn();
//  leftTurn();
//  nextObjectFront();
//  nextObjectLeft();
//  nextObjectRight();
//  delay(5000);
//  if (test != true) {
////    forward(80);
////    delay(1000);
////    rightWheelTurnPower(200);
////    delay(1000);
////    rightWheelTurnPower(80);
////    delay(1000);
////    leftWheelTurnPower(200);
////    delay(1000);
////    leftWheelTurnPower(80);
////    delay(1000);
//
////    //Fast turn test
////    rightWheelTurnPower(255);
////    delay(5000);
////    stop();
////    delay(5000);
////
////    // Slow turn test
////    rightWheelTurnPower(80);
////    delay(5000);
////    stop();
////    delay(5000);
////
////    // Both wheels turn test
////    rightTurn(100,true);
////    delay(5000);
////    stop();
//
//    test = true;
//  }
//  if (nextObjectFront() < 30) {
//    reverse(100);
//  }
//  else {
//    stop();
//  }
//  if (nextObjectRight() < 10) {
//    leftTurn();
//  }
//  else {
//    stop();
//  }
//  if(nextObjectLeft() < 10) {
//    rightTurn();
//  }
//  else {
//    stop();
//  }
}

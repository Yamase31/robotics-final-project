int rightPWM = 8;
int rightMotor1 = 6;
int rightMotor2 = 7;
int leftPWM = 5;
int leftMotor1 = 4;
int leftMotor2 = 3;

int Left_Trig_Pin = 52;
int Left_Echo_Pin = 53;
int Front_Trig_Pin = 51;
int Front_Echo_Pin = 50;
int Right_Trig_Pin = 49;
int Right_Echo_Pin = 48;

int duration;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rightPWM, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(leftPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);

  pinMode(Left_Trig_Pin, OUTPUT);
  pinMode(Front_Trig_Pin, OUTPUT);
  pinMode(Right_Trig_Pin, OUTPUT);
  pinMode(Left_Echo_Pin, INPUT);
  pinMode(Front_Echo_Pin, INPUT);
  pinMode(Right_Echo_Pin, INPUT);
}

void forwardBurst() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 200);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 200);
  delay(240);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}
void shortBurstForward() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 200);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 200);
  delay(100);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}
void burstBack() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  analogWrite(leftPWM, 200);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  analogWrite(rightPWM, 200);
  delay(75);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}
void rightBurst() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 255);
  delay(110);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 200);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 200);
  delay(50);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}
void leftBurst() {
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 255);
  delay(110);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 200);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 200);
  delay(50);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}
void rightTurnBurst() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 255);
  delay(150);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
}
void leftTurnBurst() {
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 255);
  delay(150);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}
void rightCorrection() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 255);
  delay(75);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
}
void leftCorrection() {
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 255);
  delay(75);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}

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

int nextObjectRight() {
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

int nextObjectLeft() {
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
  // put your main code here, to run repeatedly:
  delay(500);
  //bumper protocol
  if (nextObjectLeft() < 4 or nextObjectLeft() > 120) {
    rightBurst();
    delay(500);
  }
  else if (nextObjectRight() < 4 or nextObjectRight() > 120) {
    leftBurst();
    delay(500);
  }
  else if (nextObjectFront() <= 3) {
    burstBack();
    delay(3000);
  }
  else if (nextObjectFront() > 10 and abs(nextObjectLeft()-nextObjectRight()) < 1) {
    forwardBurst();
  }
  else if (nextObjectFront() > 10 and abs(nextObjectLeft()-nextObjectRight()) > 1 and abs(nextObjectLeft()-nextObjectRight()) < 18) {
    delay(500);
    if (nextObjectLeft() > nextObjectRight()) {
      leftBurst();
      shortBurstForward();
    }
    else if (nextObjectRight() > nextObjectLeft()) {
      rightBurst();
      shortBurstForward();
    }
    else {
      forwardBurst();
    }
  }
  else if (nextObjectFront() > 10 and abs(nextObjectLeft()-nextObjectRight()) > nextObjectFront()) {
    if (nextObjectRight() > nextObjectLeft() and nextObjectRight() > nextObjectFront()) {
      forwardBurst();
      rightTurnBurst();
      rightTurnBurst();
      rightTurnBurst();
      rightTurnBurst();
      leftCorrection();
      delay(1000);
      while(nextObjectLeft() > 8) {
        rightTurnBurst();
        delay(1000);
      }
    }
    else if (nextObjectLeft() > nextObjectRight() and nextObjectLeft() > nextObjectFront()) {
      forwardBurst();
      leftTurnBurst();
      leftTurnBurst();
      leftTurnBurst();
      leftTurnBurst();
      rightCorrection();
      delay(1000);
      while(nextObjectRight() > 8) {
        leftTurnBurst();
        delay(1000);
      }
    }
  }
  else if (nextObjectFront() < 10) {
    if (nextObjectFront() >= 4 and nextObjectFront() <= 10) {
      if (nextObjectLeft() > nextObjectRight() and nextObjectLeft() > 10) {
        forwardBurst();
        leftTurnBurst();
        leftTurnBurst();
        leftTurnBurst();
        leftTurnBurst();
        rightCorrection();
        delay(1000);
        while(nextObjectRight() > 8) {
        leftTurnBurst();
        delay(1000);
      }
      }
      else if (nextObjectRight() > nextObjectLeft() and nextObjectRight() > 10) {
        forwardBurst();
        rightTurnBurst();
        rightTurnBurst();
        rightTurnBurst();
        rightTurnBurst();
        leftCorrection();
        delay(1000);
        while(nextObjectLeft() > 8) {
        rightTurnBurst();
        delay(1000);
      }
      }
      else if (nextObjectFront() < 4) {
        burstBack();
        delay(2000);
      }
    }
    else {
      forwardBurst();
    }
  }
  else {
    forwardBurst();
  }
}

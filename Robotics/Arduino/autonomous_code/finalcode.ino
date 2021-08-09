// Define Variables:
//const int chA=3;  //Constant variables relating to pin locations
//const int chB=2;

//#define chA 3;  //Constant variables relating to pin locations
//#define chB 2;

int ch1;  //Varibles to store and display the values of each channel
int ch2l;
int ch2;
int ch3;
int ch4;
int ch5;

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

// the setup routine runs once when you press reset:
void setup() {
   ch5 = pulseIn (11,HIGH);
   Serial.print ("Ch5:");
   Serial.print (ch5);
   Serial.print (" . | . ");
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
      Serial.begin(9600);
            // Set input pins
           // pinMode(5,INPUT);
           // pinMode(10, INPUT);
            pinMode( 9, INPUT);
            pinMode( 10, INPUT);
          
            pinMode(6, OUTPUT); // right motor
            pinMode(7, OUTPUT);
            pinMode(8, OUTPUT); //pwm
          
            pinMode(3, OUTPUT); //left motor
            pinMode(4, OUTPUT);
            pinMode(5, OUTPUT); //pwm

      

}
   
void stop() {
  analogWrite(8, 0);
  analogWrite(5, 0);}

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


//Main Program
void loop() {
 ch5 = pulseIn(11, HIGH);
    if (ch5 > 1000) {
    
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
    else{
        // read the input channels
  ch1 = pulseIn (10,HIGH);  //Read and store channel 1
  Serial.print ("Ch1:");  //Display text string on Serial Monitor to distinguish variables
  Serial.print (ch1);     //Print in the value of channel 1
  Serial.println();
  //Serial.print (" . | . ");
 
  ch2 = pulseIn (9,HIGH);
  Serial.print ("Ch2r:");
  Serial.print (ch2);
  Serial.println();
  //Serial.print (" . | . ");

//  ch3 = pulseIn (11,HIGH);  
//  Serial.print ("Ch3:");  
//  Serial.print (ch3);     
//  Serial.print (" . | . ");
 
//  ch4 = pulseIn (6,HIGH);
//  Serial.print ("Ch4:");
//  Serial.print (ch4);
//  Serial.print (" . | . ");

  ch5 = pulseIn (11,HIGH);
  Serial.print ("Ch5:");
  Serial.print (ch5);
  Serial.print (" . | . ");
  
  int th = map(ch2, 950, 2000, -240, 240);
  //int th2 = map(ch2l, 950, 2000, -240, 240);
  int dir = map(ch1, 950, 2000, -240, 240);
  
  Serial.print("th: "); //print the positive throttle
  Serial.println(th); //print the positive throttle
  Serial.print("dir: "); //print the positive throttle
  Serial.println(dir); //print the positive throttle
  delay(500);

  if (th > 20){
    if (th < 120) {
    th = 120;
  }
  digitalWrite(6, HIGH); //forward
  digitalWrite(7, LOW);
  analogWrite(8, th);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  analogWrite(5, th);
  }
  else if (th < -20){  //back
    if (th > -120) { //if abs signal is less than 120 then the th is automatically set to 120
    th = 120;
  }
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  analogWrite(8, abs(th));
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  analogWrite(5, abs(th));
  }
  else if (dir > 20){  //right turn
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  analogWrite(8, dir);
  if (dir < 120) {
    dir = 120;
  }
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  analogWrite(5, dir);
  }
  else if (dir < -20){  //left turn
  if (dir > -150) { //if abs signal is less than 120 then the dir is automatically set to 120
    dir = 150;
  }
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  analogWrite(8, abs(dir));
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  analogWrite(5, abs(dir));
  }
  else {
    stop();
  }

    }
  
}

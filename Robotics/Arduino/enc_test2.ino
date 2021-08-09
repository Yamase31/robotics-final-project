// The pin the encoder is connected
int r_encoder_in = 18;
const int rmp1 = 6;
const int rmp2 = 7;
const int rm_PWM = 8;

const int sideThresh = 6;
int l_encoder_in = 20;
const int lmp1 = 3;
const int lmp2 = 4;
const int lm_PWM = 5;
int j;

volatile int rpwm;
volatile int lpwm;
volatile int targetrpm;
volatile int leftdist, rightdist;

bool rightCorrect;
int power = 12;
  

// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 5;

// The total number of revolutions
unsigned int rightrevolutions = 0;
unsigned int leftrevolutions = 0;

// Initialize the counter
volatile unsigned int rightpulses = 0;
volatile unsigned int leftpulses = 0;

volatile double rpm_ratio = 0;


const int Left_Trig_Pin = 53;
const int Left_Echo_Pin = 52;
const int Front_Trig_Pin = 51;
const int Front_Echo_Pin = 50;
const int Right_Trig_Pin = 49;
const int Right_Echo_Pin = 48;
long duration, inches;

void rightcount() {
  // This function is called by the interrupt
  rightpulses++;
}

void leftcount(){
  leftpulses++;
}

void pause(int seconds){
  analogWrite(lm_PWM, 0);
  analogWrite(rm_PWM, 0);
  delay(seconds*1000);
}


void setup() {
  delay(3000);
  rpwm = 80;
  lpwm = 80;
  targetrpm = 80;
  j=0;
  rightCorrect = true;
  pinMode(r_encoder_in, INPUT_PULLUP);
  pinMode(rmp1, OUTPUT);
  pinMode(rmp2, OUTPUT);

  pinMode(l_encoder_in, INPUT_PULLUP);
  pinMode(lmp1, OUTPUT);
  pinMode(lmp2, OUTPUT);

  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);

  pinMode(Left_Trig_Pin,OUTPUT);
  pinMode(Left_Echo_Pin,INPUT);
  pinMode(Front_Trig_Pin,OUTPUT);
  pinMode(Front_Echo_Pin,INPUT);
  pinMode(Right_Trig_Pin,OUTPUT);
  pinMode(Right_Echo_Pin,INPUT);

  attachInterrupt(INT2, rightcount, RISING);
  attachInterrupt(INT4, leftcount, RISING);
  Serial.begin(9600);
}

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
  //Serial.println((duration / 2) / 74);
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
  //Serial.println((duration / 2) / 74);
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
  //Serial.println((duration / 2) / 74);
  return (duration / 2) / 74;
  
}

void easeForward(){
    
  for(int i = 40; i<targetrpm; i++){
    analogWrite(lm_PWM, i);
    driveForward(i);
    delay(10);
  }
}
void backUp(){
   digitalWrite(lmp2, HIGH);
    digitalWrite(rmp2, HIGH);
    digitalWrite(lmp1, LOW);
    digitalWrite(rmp1, LOW);
    analogWrite(rm_PWM, rpwm);
    analogWrite(lm_PWM, lpwm);
    delay(1000);
    analogWrite(rm_PWM, 0);
    analogWrite(lm_PWM, 0);
    digitalWrite(lmp1, HIGH);
    digitalWrite(rmp1, HIGH);
    digitalWrite(lmp2, LOW);
    digitalWrite(rmp2, LOW);
}

void driveForward(int rpm){
    digitalWrite(lmp1, HIGH);
    digitalWrite(rmp1, HIGH);
    digitalWrite(lmp2, LOW);
    digitalWrite(rmp2, LOW);
    
  rightrevolutions = rightpulses;
  leftrevolutions = leftpulses;
  rightdist = nextObjectRight();
  leftdist = nextObjectLeft();
  /*Serial.print("Right Pulses: ");
  Serial.print(rightpulses);
  Serial.print(", Left Pulse: ");
  Serial.print(leftpulses);
  Serial.println();*/
  rightpulses = leftpulses = 0;
  //rightCorrect = !rightCorrect;
if(rightCorrect){
  if(rightrevolutions != leftrevolutions){
     rpwm =  rpwm * leftrevolutions  / rightrevolutions ;
  }
  
  if(rightdist<6 && leftdist<6){
    //if(rightdist> leftdist) {
      //rpwm-=1;
      //lpwm+=1;
    //}
    //else if (leftdist>rightdist){
     // rpwm+=1;
      //lpwm-=1;
    //}
   rpwm = rpwm *  leftdist  / rightdist;
  }
}
//else{
//  if(rightrevolutions != leftrevolutions){
//      lpwm  = lpwm * rightrevolutions / leftrevolutions ;
//
//}
//if(leftdist < 5  && rightdist< 5){
//    lpwm = lpwm * rightdist/ leftdist;
//  }
//}
//if(rpwm < rpm) rpwm+= 1;
 //if(lpwm < rpm) lpwm+= 1;
 //if(rpm < rpwm) rpwm-= 1;
 //if(rpm < lpwm) lpwm-= 1;
  analogWrite(lm_PWM, lpwm);
    analogWrite(rm_PWM, rpwm);
}

 void leftTurn(){
  //Serial.println("About to turn left");
  digitalWrite(lmp1, LOW);
  analogWrite(rm_PWM, 100);
  delay(825);
  while(nextObjectLeft()>sideThresh && nextObjectRight()>sideThresh ){
    delay(25);
  }
  //Serial.println("Done turning left");
  pause(1);
   analogWrite(rm_PWM, rpwm);
   analogWrite(lm_PWM, lpwm);
digitalWrite(lmp1, HIGH);
//easeForward();
 }

 void rightTurn(){
  //Serial.println("About to turn right");
  digitalWrite(rmp1, LOW);
  analogWrite(lm_PWM, 100);
  delay(850);
  while(nextObjectRight()>sideThresh && nextObjectLeft()>sideThresh ){
    delay(25);
  }
    //Serial.println("Done turning right");
  pause(1);
   analogWrite(lm_PWM, lpwm);
   analogWrite(rm_PWM, rpwm);
digitalWrite(rmp1, HIGH);
//easeForward();
 }



void loop() {
  if(j<200){
  digitalWrite(rmp1, HIGH);
  digitalWrite(rmp2, LOW);
  //analogWrite(rm_PWM, rpwm);
  //rightrevolutions = rightpulses;
  //Serial.print(rightrevolutions);
  digitalWrite(lmp1, HIGH);
  digitalWrite(lmp2, LOW);
  //analogWrite(lm_PWM, lpwm);
  driveForward(targetrpm);
  //Serial.print("       " );
  //leftrevolutions = leftpulses;
  //Serial.print( leftrevolutions);
  //Serial.println();
  //rightpulses = leftpulses = 0;
  //rightCorrect = !rightCorrect;

/*  
if(rightCorrect){
  if(rightrevolutions != leftrevolutions){
      rpwm = rpwm * leftrevolutions / rightrevolutions;
  }}
else{
  if(rightrevolutions != leftrevolutions){
      lpwm  = lpwm * rightrevolutions / leftrevolutions;

}}
  */
  

  Serial.print("Distance Front: ");
  Serial.print(nextObjectFront());
  Serial.print("    Distance Right: ");
  Serial.print(nextObjectRight());
  Serial.print("    Distance Left: ");  
  Serial.print(nextObjectLeft());
  Serial.println();

  
    if(nextObjectFront()<11 ){
      pause(3);
      if((nextObjectLeft()>sideThresh && nextObjectRight()<sideThresh) || nextObjectLeft()-nextObjectRight() > 15){
      Serial.println("I should turn left!");
      leftTurn();
    }
    else if((nextObjectRight()>sideThresh && nextObjectLeft()<sideThresh) || nextObjectRight()-nextObjectLeft() > 15 ){
      Serial.println("I should turn right!");
      rightTurn();
    }
    else if(nextObjectLeft()<sideThresh && nextObjectRight()<sideThresh){
      backUp();
      
      if(nextObjectLeft()< sideThresh) rightTurn();
      else leftTurn();
    }
}
  // Here you can output the revolutions, e. g. once a second
  //
  //
  delay(20);
  j++;
  }
  else{
    digitalWrite(lmp1, LOW);
    digitalWrite(rmp1, LOW);
    }
    

}


 

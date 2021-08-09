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



// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
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
  analogWrite(5, 0);
}


//Main Program
void loop() {
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

//  ch5 = pulseIn (7,HIGH);
//  Serial.print ("Ch5:");
//  Serial.print (ch5);
//  Serial.print (" . | . ");
  
  int th = map(ch2, 950, 2000, -200, 200);
  //int th2 = map(ch2l, 950, 2000, -240, 240);
  int dir = map(ch1, 950, 2000, -200, 200);
  
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
//  digitalWrite(6, LOW);
//  digitalWrite(7, HIGH);
//  analogWrite(8, dir);
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
//  digitalWrite(3, HIGH);
//  digitalWrite(4, LOW);
//  analogWrite(5, abs(dir));
  }
  else {
    stop();
  }

  
  


}

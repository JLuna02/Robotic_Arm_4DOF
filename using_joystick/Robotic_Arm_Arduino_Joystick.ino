#include <Servo.h>

int right_X = A2; // define the right X pin to A2 
int right_Y = A5; // define the right Y pin to A5 
int right_key = 7; //define the right key pin to 7（that is the value Z）

int left_X = A3; //define the left X pin to A3
int left_Y = A4;  // define the left Y pin to A4
int left_key = 8; //define the left key pin to 8（that is the value Z） 

Servo servBase, servShoulder, servElbow, servClaw;
int BasePos, ShoulderPos, ElbowPos, ClawPos;

void setup() {
  pinMode(right_key, INPUT);   // set the right/left key to INPUT 
  pinMode(left_key, INPUT);

  servBase.attach(3);
  servBase.write(0);

  servShoulder.attach(5);
  servShoulder.write(0);

  servElbow.attach(6);
  servElbow.write(0);

  servClaw.attach(9);
  servClaw.write(0);

  BasePos = 0;
  ShoulderPos = 90;
  ElbowPos = 90;
  ClawPos = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  int x1,y1,z1;  // define the variable, used to save the joystick value it reads
  int x2,y2,z2;
  
  x2 = analogRead(right_X); // read the value of right X 
  y2 = analogRead(right_Y);  // read the value of right Y 
  z2 = digitalRead(right_key);  //// read the value of right Z
  x2 = map(x2, 0, 1023, 0, 180);
  y2 = map(y2, 0, 1023, 0, 180);
  
  x1 = analogRead(left_X);  // read the value of left X
  y1 = analogRead(left_Y);  // read the value of left Y 
  z1 = digitalRead(left_key);  // read the value of left Z 
  x1 = map(x1, 0, 1023, 0, 180);
  y1 = map(y1, 0, 1023, 0, 180);

  //servBase.write(y1);
  if(BasePos < y1){
    BasePos += 1;
    servBase.write(BasePos);
  }
  else if(BasePos > y1){
    BasePos -= 1;
    servBase.write(BasePos);
  }

  //servShoulder.write(x1);
  if(ShoulderPos < x1){
    ShoulderPos += 1;
    servShoulder.write(ShoulderPos);
  }
  else if(ShoulderPos > x1){
    ShoulderPos -= 1;
    servShoulder.write(ShoulderPos);
  }

  //servElbow.write(y2);
  if(ElbowPos < y2){
    ElbowPos += 1;
    servElbow.write(ElbowPos);
  }
  else if(ElbowPos > y2){
    ElbowPos -= 1;
    servElbow.write(ElbowPos);
  }

  //servClaw.write(x2);
  if(ClawPos < x2){
    ClawPos += 1;
    servClaw.write(ClawPos);
  }
  else if(ClawPos > x2){
    ClawPos -= 1;
    servClaw.write(ClawPos);
  }
  // Delay 5 ms
  delay(5);

}

#include <Servo.h>

Servo servBase, servShoulder, servElbow, servClaw;
int currentPos, pos;
// store the current position
int BasePos, ShoulderPos, ElbowPos, ClawPos;
String msg;


void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);
  servBase.attach(3);
  servBase.write(0);

  servShoulder.attach(5);
  servShoulder.write(0);

  servElbow.attach(6);
  servElbow.write(0);

  servClaw.attach(9);
  servClaw.write(0);
  BasePos = 0;
  ShoulderPos = 0;
  ElbowPos = 0;
  ClawPos = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  msg = Serial.readStringUntil('\n');
  int values[4];
  int index = 0;
  int pos = 0;
  while ((pos = msg.indexOf(',')) != -1) {
    values[index] = msg.substring(0, pos).toInt();
    msg = msg.substring(pos + 1);
    index++;
  }
  values[index] = msg.toInt();
  //servo Base
  if(BasePos < values[0]){
    BasePos += 1;
    servBase.write(BasePos);
  }
  else if(BasePos > values[0]){
    BasePos -= 1;
    servBase.write(BasePos);
  }
  
  //servo Shoulder
  if(ShoulderPos < values[1]){
    ShoulderPos += 1;
    servShoulder.write(ShoulderPos);
  }
  else if(ShoulderPos > values[1]){
    ShoulderPos -= 1;
    servShoulder.write(ShoulderPos);
  }

  //servo Elbow
  if(ElbowPos < values[2]){
    ElbowPos += 1;
    servElbow.write(ElbowPos);
  }
  else if(ElbowPos > values[2]){
    ElbowPos -= 1;
    servElbow.write(ElbowPos);
  }

  //servo Claw
  if(ClawPos < values[3]){
    ClawPos += 1;
    servClaw.write(ClawPos);
  }
  else if(ClawPos > values[3]){
    ClawPos -= 1;
    servClaw.write(ClawPos);
  }
  delay(5);


}


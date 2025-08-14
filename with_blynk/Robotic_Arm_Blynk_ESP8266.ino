#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6fjFYbpWl"
#define BLYNK_TEMPLATE_NAME "NodeMCU"
#define BLYNK_AUTH_TOKEN "ZQvFu2mudUBC-jHj4kOP03NK0wUoKLWY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "ZQvFu2mudUBC-jHj4kOP03NK0wUoKLWY"; // Auth token from the Blynk app
char ssid[] = "Evone 2.4"; // WiFi SSID
char pass[] = "2023evonej"; // WiFi password

int servBase, servShoulder, servElbow, servClaw;
int value, value1, value2, value3;

int currentPos, pos;

// Base Turn Right
BLYNK_WRITE(V0){
  value = param.asInt();
  servBase = value;
}
// Base Turn Left
BLYNK_WRITE(V1){
  value1 = param.asInt();
  servShoulder = value1;
}

// Shoulder Turn Right
BLYNK_WRITE(V2){
  value2 = param.asInt();
  servElbow = value2;
}
// Shoulder Turn Left
BLYNK_WRITE(V3){
  value3 = param.asInt();
  servClaw = value3;
}



void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  delay(15);
  Serial.print(servBase);
  Serial.print(",");
  Serial.print(servShoulder);
  Serial.print(",");
  Serial.print(servElbow);
  Serial.print(",");
  Serial.println(servClaw);
  delay(15);


}

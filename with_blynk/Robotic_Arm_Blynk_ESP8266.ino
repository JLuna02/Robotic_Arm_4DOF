#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "Your_Blynk_Template_ID"
#define BLYNK_TEMPLATE_NAME "Your_Template_Name"
#define BLYNK_AUTH_TOKEN "Your_Blynk_Auth_token"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "Your_Blynk_Auth_token"; // Auth token from the Blynk app
char ssid[] = "WiFi_SSID"; // WiFi SSID
char pass[] = "WiFi_password"; // WiFi password

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
  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}

void loop() {
  // Run Blynk
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

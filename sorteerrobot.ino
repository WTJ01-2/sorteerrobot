#include "Motor.h"

Motor motor1(7, 6, 240);

void setup() {
  Serial.begin(9600);
  Serial.println("--- BPP ROBOT ---");
  Serial.setTimeout(100);
  Serial.println("-----------------");
  pinMode(A2, INPUT);
  Serial.println("----- READY -----");
}

void loop() {
    if(Serial.available()){
      String ser = Serial.readString();
      if(ser == "commando-left"){
        motor1.driveLeft(750);        
        Serial.println("status-bpp-left-ok");
      } else if(ser == "commando-right"){
        motor1.driveRight(750);
        Serial.println("status-bpp-right-ok");
        }else{
        Serial.println("status-bpp-unknown");
      } 
      } 
}


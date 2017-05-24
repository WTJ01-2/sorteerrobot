#include "Motor.h"

Motor motor1(7, 6, 240);

Motor motor2(4, 5, 240);
int loc = 0;
int products = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("--- BPP ROBOT ---");
  Serial.setTimeout(100);
  Serial.println("-----------------");
  pinMode(A2, INPUT);
  Serial.println("----- READY -----");
}

void loop() {
  if (Serial.available()) {
    String ser = Serial.readString();
    if (ser == "command-rotate_left") {
      if(loc==0 || loc==2){
        loc=1;
        motor1.driveLeft(750);
        delay(200);
      }
      motor2.driveLeft(450);
      Serial.println("bpp-status-sort_succes");
    } else if (ser == "command-rotate_right") {
      if(loc==0 || loc==1){
        loc=2;
        motor1.driveRight(750);
        delay(200);
      }
      motor2.driveLeft(450);
      Serial.println("bpp-status-sort_succes");
    } else if (ser == "command-arm_reset") {
      motor2.driveLeft(2000);
      products = 0;
      Serial.println("status-arm-reset_ok");
    } else if (ser == "command-arm_out") {
      if (products == 0) {
        motor2.driveRight(2500);
      } else if (products == 1) {
        motor2.driveRight(900);
      } else if (products == 2) {
        motor2.driveRight(900);
      } else if (products == 3) {
        motor2.driveRight(900);
      } else {
        motor2.driveRight(900);
        //products = 0;
      }
      products++;
      Serial.println("bpp-status-arm_out_ok");

    } else if (ser == "command-arm_in") {
      if (products == 1) {
        motor2.driveLeft(1200);
      } else if (products == 2) {
        motor2.driveLeft(1200);
      } else if (products == 3) {
        motor2.driveLeft(1200);
      } else {
        motor2.driveLeft(1400);
      }
      Serial.println("bpp-status-arm_in_ok");
    } else if (ser == "command-arm_all_in") {
      motor2.driveLeft(2000);
      Serial.println("bpp-status-arm_all_in_ok");
    } else {
      Serial.println("status-bpp_unknown");
    }
  } 
}


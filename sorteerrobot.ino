#include "Motor.h"

Motor motor1(7, 6, 240);

Motor motor2(4, 5, 240);


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
    if(Serial.available()){
      String ser = Serial.readString();
      if(ser == "command-rotate_left"){
        motor1.driveLeft(750);
        motor2.driveLeft(500);        
        Serial.println("status-bpp-left_ok");
      } else if(ser == "command-rotate_right"){
        motor1.driveRight(750);
        delay(50);
        motor2.driveLeft(500);        
        Serial.println("status-bpp-right_ok");
        } else if(ser == "command-arm_reset"){
        products = 0;
        Serial.println("status-arm-reset_ok");
        } else if(ser == "command-arm_out"){
<<<<<<< HEAD
          if(products == 0){
          motor2.driveRight(2500);
          } else if(products == 1){
          motor2.driveRight(1000);          
          } else if(products == 2){
          motor2.driveRight(900);           
          } else {
          motor2.driveRight(900);    
          products = 0;          
          }
          products++;
          Serial.println("bpp-status-arm_out_ok");
          
        } else if(ser == "command-arm_in") {
          if(products == 1){
             motor2.driveLeft(1100);   
          } else if (products == 2){
            motor2.driveLeft(1100);
          } else if (products == 3){
            motor2.driveLeft(800);
          } else{
            motor2.driveLeft(1300);
          }
          Serial.println("bpp-status-arm_in_ok");
        } else if(ser == "command-arm_all_in"){
          motor2.driveLeft(2000);   
          Serial.println("bpp-status-arm_all_in_ok");
=======
        if(products == 0){
        motor2.driveRight(1650);
        } else if(products == 1){
        motor2.driveRight(950);          
        } else if(products == 2){
        motor2.driveRight(850);          
        } else {
        motor2.driveRight(1650);
        products = 0;          
        }
        products++;
        Serial.println("bpp-status-arm_out_ok");
        } else if(ser == "command-arm_in"){
        if(products == 1){
        motor2.driveLeft(975);     
        } else if (products == 2){
         motor2.driveLeft(700);
        } else if (products == 3){
         motor2.driveLeft(650);
>>>>>>> origin/master
        } else{
        motor2.driveLeft(800);
        }
        Serial.println("status-arm_in_ok");
        }else{
        Serial.println("status-bpp_unknown");
      } 
      } 
}


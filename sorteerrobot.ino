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
      if(ser == "commando-rotate-left"){
        motor1.driveLeft(750);        
        Serial.println("status-bpp-left-ok");
      } else if(ser == "commando-rotate-right"){
        motor1.driveRight(750);
        Serial.println("status-bpp-right-ok");
        } else if(ser == "commando-arm-reset"){
        products = 0;
        Serial.println("status-arm-reset-ok");
        } else if(ser == "commando-arm-out"){
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
        Serial.println("status-arm-out-ok");
        String p = "producten: ";
        p += products;
        Serial.println(p);
        } else if(ser == "commando-arm-in"){
        if(products == 1){
        motor2.driveLeft(975);     
        } else if (products == 2){
         motor2.driveLeft(700);
        } else if (products == 3){
         motor2.driveLeft(650);
        } else{
        motor2.driveLeft(800);
        }
        Serial.println("status-arm-in-ok");
        } else{
        Serial.println("status-bpp-unknown");
      } 
      } 
}


#include "Motor.h"

boolean rechts = false;
boolean links = true;

// Sensor pin
int sensor = analogRead(A2);
int products = 0;
Motor motor1(7, 6, 240);
int check = 0;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(A2, INPUT);
  Serial.println("--- FINISHED ---");
}

void loop() {
//    Serial.println(analogRead(A2));
//    delay(500);
    if(Serial.available()){
      String ser = Serial.readString();
      if(getStringPartByNr(ser, ' ', 0) == "commando"){
        if(getStringPartByNr(ser, ' ' , 1) == "left"){
          motor1.driveLeft(750);        
          Serial.println("status left ok");
          boxCheck();
          String st = "status products ";
          st += products;
          Serial.println(st);
        } else if(getStringPartByNr(ser, ' ', 1) == "right"){
          motor1.driveRight(750);
          Serial.println("status right ok");
          boxCheck();
          String st = "status products ";
          st += products;
          Serial.println(st);
        } else if(getStringPartByNr(ser, ' ', 1) == "reset"){
          products = 0;
          Serial.println("status reset ok");
        } else{
          Serial.println("status unknown command");
        }
      }
    }
    
}

void boxCheck(){
  sensor = analogRead(A2);
  if(sensor < 600 && sensor > 400){
      products++;
  } else{
    if(check < 3000){
      delay(1);
      check++;
      boxCheck();
    } else{
      Serial.println("status failed detection");
      check = 0;
    }
  }
}

// Source: https://github.com/BenTommyE/Arduino_getStringPartByNr/blob/master/getStringPartByNr.ino
// splitting a string and return the part nr index split by separator
String getStringPartByNr(String data, char separator, int index) {
    int stringData = 0;        //variable to count data part nr 
    String dataPart = "";      //variable to hole the return text

    for(int i = 0; i<data.length(); i++) {    //Walk through the text one letter at a time
        if(data[i]==separator) {
            //Count the number of times separator character appears in the text
            stringData++;
        } else if(stringData==index) {
            //get the text when separator is the rignt one
            dataPart.concat(data[i]);
        } else if(stringData>index) {
            //return text and stop if the next separator appears - to save CPU-time
            return dataPart;
            break;
        }
    }
    //return text if this is the last part
    return dataPart;
}


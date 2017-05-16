#include "Motor.h"

boolean rechts = false;
boolean links = true;

// Sensor pin
int sensor = analogRead(A0);
int products = 0;
Motor motor1(7, 6, 240);

void setup() {
  
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(A0, INPUT);
  Serial.println("--- FINISHED ---");
}

void loop() {
    if(Serial.available()){
      String ser = Serial.readString();
      if(getStringPartByNr(ser, ' ', 0) == "commando"){
        if(getStringPartByNr(ser, ' ' , 1) == "left"){
          motor1.driveLeft(750);        
          writeString("status left ok");
          boxCheck();
          String st = "status products ";
          st += products;
          writeString(st);
        } else if(getStringPartByNr(ser, ' ', 1) == "right"){
          motor1.driveRight(750);
          writeString("status right ok");
          boxCheck();
          String st = "status products ";
          st += products;
          writeString(st);
        } else if(getStringPartByNr(ser, ' ', 1) == "reset"){
          products = 0;
          writeString("status reset ok");
        }
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

void writeString(String s) { // Push elke char door
  for (int i = 0; i < s.length(); i++)
  {
    Serial.write(s[i]);
  }
}

void boxCheck(){
  sensor = analogRead(A0);
  if(sensor > 800){
      products++;
  } else{
    boxCheck();
  }
}


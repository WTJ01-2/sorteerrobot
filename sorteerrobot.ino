#include "Motor.h"

boolean rechts = false;
boolean links = true;
Motor motor1(7, 6, 240);

void setup() {
  
  Serial.begin(9600);
  Serial.setTimeout(500);
  Serial.println("Serial aan");
}

void loop() {
    if(Serial.available()){
    String ser = Serial.readString();
    if(getStringPartByNr(ser, ' ', 0) == "commando"){

      if(getStringPartByNr(ser, ' ' , 1) == "left"){
        motor1.driveLeft(750);        
      } else if(getStringPartByNr(ser, ' ', 1) == "right"){
        motor1.driveRight(750);
      }
      Serial.println("Commando succes: " + ser);
    }
    if(ser == "test"){
      motor1.driveLeft(750);
      Serial.println("hi");
    }      
    }

    //if(Serial.read() == 116){
    //  motor1.driveRight(750);
    //}
  //motor1.driveLeft(750);

  //motor1.driveRight(750);
  
  //draai(true);
  //delay(2000);
  //draai(false);
  //delay(2000);
}

void draai(boolean links){
    if (links) {
    digitalWrite(7, HIGH); 
  } else {
    digitalWrite(7, LOW);
  }
    analogWrite(6, 135);
    delay(750);
    analogWrite(6, 0);
}
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


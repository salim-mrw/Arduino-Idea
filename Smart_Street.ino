#include <SoftwareSerial.h>
 
const int US100_TX = 3;
const int US100_RX = 2;

SoftwareSerial US100Serial(US100_RX, US100_TX);

unsigned int MSByteDistance = 0;
unsigned int LSByteDistance = 0;
unsigned int mmDistance = 0;

void setup() {

//Leds

  //Led 1
    pinMode(12,OUTPUT);
  //Led 2
    pinMode(11,OUTPUT);
  //Led 3
    pinMode(10,OUTPUT);
  //Led 4
    pinMode(9,OUTPUT);
  //Led 5
    pinMode(8,OUTPUT);
  //Led 6
    pinMode(7,OUTPUT);

    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    
    Serial.begin(9600);
    US100Serial.begin(9600);

}
 
void loop() {
 
    US100Serial.flush();
    US100Serial.write(0x55); // Trig US-100 begin to measure the distance
 
    delay(50);
 
    if(US100Serial.available() >= 2)  // Check receive 2 bytes correctly
    {
        MSByteDistance = US100Serial.read(); 
        LSByteDistance = US100Serial.read();
        mmDistance  = MSByteDistance * 256 + LSByteDistance; 
        if((mmDistance > 1) && (mmDistance < 10000)) 
        {
          Serial.println(mmDistance);
            if(mmDistance < 190 && mmDistance > 140){
                  digitalWrite(12,HIGH);
                  digitalWrite(7,HIGH);
            }else{
                  digitalWrite(12,LOW);
                  digitalWrite(7,LOW);
            }
            if(mmDistance < 140 && mmDistance > 60){
                  digitalWrite(11,HIGH);
                  digitalWrite(8,HIGH);
            }else{
                  digitalWrite(11,LOW);
                  digitalWrite(8,LOW);
            }
            if(mmDistance < 60 && mmDistance > 1){
                  digitalWrite(10,HIGH);
                  digitalWrite(9,HIGH);
            }else{
                  digitalWrite(10,LOW);
                  digitalWrite(9,LOW);
            }
        }
    }
 
    delay(100);

}


 #include <GPRS_Shield_Arduino.h>
#include <sim900.h>
 #include <SoftwareSerial.h>
 #define IR  7
#define REC 4
#define PLAYE 5
#define PLAYL 6
SoftwareSerial mySerial(9, 10);
void setup(){
 pinMode(IR, INPUT);
 pinMode(REC, OUTPUT);
 Serial.begin(9600);
 mySerial.begin(9600);
 int count=0;
}
void loop(){
 
 int i = digitalRead(IR);
 
 if(i == 1)
 
 {
 
   Serial.println("Someone's here!!");
 
   digitalWrite(REC, 1);
 
   delay(10000);
 
   digitalWrite(REC, 0);
 
    delay(500);
 
    digitalWrite(PLAYE, 1);
 
   delay(10000);
 
   digitalWrite(PLAYE, 0);
 SendMessage();
 }
}
 

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917601019480\"\r"); //Sends message
  delay(1000);
  mySerial.println("We have an intruder");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 

#include <SoftwareSerial.h>
#include "dht.h"
#define dht_apin A0
dht DHT;
SoftwareSerial mySerial(9, 10);
const int sensor_pin = A1;
int pumpPin = 7; 
const int triggerPin = 4; 
const int ecPin = 8;
int buzzer = 13;
int smokeA0 = A5;
int sensorThres = 300;

void setup(){   
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  delay(1000);//Wait before accessing Sensor
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(pumpPin, OUTPUT); 
}
 
void loop(){ 
  int analogSensor = analogRead(smokeA0);
  Serial.print("Smoke Sensor: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 800, 200);
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
  DHT.read11(dht_apin);
  float moisture_percentage;
  int sensor_analog;
  long time, inches, cm;
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.println("%  ");
  Serial.print("Current Temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.println(moisture_percentage);
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(ecPin, INPUT);
  time = pulseIn(ecPin, HIGH);
  inches = microsecondsToInches(time);
  cm = microsecondsToCentimeters(time);
  Serial.print("Water Level:");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
  if (moisture_percentage<40)
  {
       if(inches>=3 )
            {
            Serial.println("Tank is almost Empty!! Please fill the water");
            mySerial.println("AT+CMGF=1");  
            delay(500);
            mySerial.println("AT+CMGS=\"+919972434486\"\r"); 
            delay(500);
            mySerial.println("Tank is almost Empty!! Please fill the water");
            delay(500);
            mySerial.println((char)26); 
            }
      else 
            {
            mySerial.println("AT+CMGF=1");
            delay(100);   
            mySerial.println("AT+CMGS=\"+918105128205\"\r"); 
            delay(100);
            Serial.println("Irrigation started");
            mySerial.println("Irrigation started");
            delay(100);
            mySerial.println((char)26);
            delay(100);
            if(DHT.temperature>35)
            {
            digitalWrite(pumpPin, HIGH);
            delay(100000);
            }
            else
            {
            digitalWrite(pumpPin, HIGH);
            delay(16000); 
            }
            digitalWrite(pumpPin, LOW);
            delay(500);
            }
  }
  else
    digitalWrite(pumpPin, LOW);
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

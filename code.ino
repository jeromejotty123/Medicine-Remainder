#include<SoftwareSerial.h>
#include <Servo.h>
Servo s1;
int sensor_pin = 4;
int servo_pin =5;
int val;
SoftwareSerial gsm(2,3);
void setup()
{
  delay(5);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("ATD9080271349;");
  gsm.println("AT+CMGF=1");
  gsm.println("AT+CMGS=\"+919080271349\"\r");
  delay(5);
  gsm.println("TIME TO CONSUME DOLO 650");
  gsm.println((char)26);
  pinMode(sensor_pin,INPUT);
  s1.attach(servo_pin);
  
}
void loop() {
  val=digitalRead(sensor_pin);
  if(val==0)
  {
    s1.write(0);
  }
  if(val==1)
  {
    s1.write(120);
  }
}

#include<Servo.h>
int servoPos=0;
int servoPin=11;
int TrPin=10;
int EcPin=9;
long time;
int distance;
int a=0;
int b=0;

Servo hinge;
//
void setup()
{
  
  pinMode(TrPin,OUTPUT);
  pinMode(EcPin,INPUT);
  Serial.begin(9600);
  hinge.attach(servoPin);
  
}

void loop()
{
  a=analogRead(A1);
  b=map(a,0,1023,0,255);
  digitalWrite(TrPin,LOW);
  delayMicroseconds(100);
  
  digitalWrite(TrPin,HIGH);
  delayMicroseconds(100);
  digitalWrite(TrPin,LOW);
  
  time=pulseIn(EcPin,HIGH);
  distance=time*0.034/2;
  
  if(distance<=50 && b>100)
  {
    servoPos=90;
  }
  else
  {
    servoPos=0;
  
  }
  
  Serial.println(distance);
  
  hinge.write(servoPos);
}

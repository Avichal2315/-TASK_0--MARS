#include<Servo.h>
int servoPos=0;
int servoPin=11;

int moistSoil;
int switchPin=7;
Servo dispenser;
void setup()
{
  pinMode(switchPin,INPUT);
  Serial.begin(9600);
  dispenser.attach(servoPin);
}

void loop()
{
 
  if(digitalRead(switchPin)==HIGH)
     {
        moistSoil=analogRead(A0);
  Serial.print("\n moisture value ");
  Serial.print(moistSoil);
  delay(500);
    
    if(moistSoil<200)
    {
      servoPos=90;
    }
    else
    {
      servoPos=0;
    }
    dispenser.write(servoPos);
      } 
}

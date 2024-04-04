#include<LiquidCrystal.h>
int rsPin=12,EPin=11,DB4Pin=5,DB5Pin=4,DB6Pin=3,DB7Pin=2;
LiquidCrystal lcd(rsPin,EPin,DB4Pin,DB5Pin,DB6Pin,DB7Pin);

int gasQ;
int ALSpin=A1;
int lightVal;
int temp;
char perfect[]="perfect weather ";
char okey[]="okey weather ";
char bad[]="bad weather ";
void setup()
{
 pinMode(A0,INPUT);
  pinMode(ALSpin,INPUT);
  pinMode(A2,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  
}

void loop()
{
  int i=0;
  
  
   lcd.clear();
   gasQ=analogRead(A0);
   temp=analogRead(A2);
 
   lightVal=analogRead(A1);
  
  
 Serial.println("Gas: " + String(gasQ));
  Serial.println("Light: " + String(lightVal));
  Serial.println("Temperature: " + String(temp));

  if (temp < 35 && gasQ < 350 && lightVal < 900) {
    for (int i = 0; perfect[i] != '\0'; i++) {
      lcd.print(perfect[i]);
    }
  } 
  else if (temp < 35 || gasQ < 350 || lightVal < 900) {
    for (int i = 0; okey[i] != '\0'; i++) {
      lcd.print(okey[i]);
    }
  } 
  else {
    for (int i = 0; bad[i] != '\0'; i++) {
      lcd.print(bad[i]);
    }
  }
  
  delay(200);

  }
  


#include <Ultrasonic.h>
int buzzer = 9;
int button=2;
int buttonState=0;
Ultrasonic ultrasonic(12,11);
void setup() {
  Serial.begin(9600); 
  pinMode(buzzer,OUTPUT);
  pinMode(button, INPUT);  
}
void loop()
{
  int distance = ultrasonic.Ranging(CM);
  if (distance<50){
   int dil = 2*distance;
   buttonState = digitalRead(button);
   digitalWrite(buzzer,HIGH);  
   delay(dil);
   digitalWrite(buzzer,LOW);
   delay(dil);
   if(buttonState == HIGH){
    digitalWrite(buzzer, LOW);
    delay(100);
   }
   else{
    digitalWrite(buzzer, HIGH);
   }
   }
}

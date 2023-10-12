
#include <Stepper.h>


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   int increase = digitalRead(13);
   int decrease =digitalRead(12);
   int start1=digitalRead(7);
   int stop1=digitalRead(6);
   Serial.print("current_angle: ");
   Serial.println(current_angle);
   if(increase==1)
   {
    Serial.println("blue button");
   }
   if(decrease==1)
   {
    Serial.println("blue button");
   }
   if(start1==1)
   {
    Serial.println("blue button");
   }
   if(stop1==1)
   {
    Serial.println("blue button");
   }
  delay(1000);
}

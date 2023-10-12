#include <Stepper.h>

int current_angle=0;

const int stepsPerRevolution = 57;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void dec_flow()
{
  if(current_angle>0)
  {
    myStepper.setSpeed(10);
    myStepper.step(stepsPerRevolution);
    current_angle=current_angle-10;

  //delay(1000);
  }

  else
  {
    Serial.print("value is max :");
    Serial.println(current_angle);
  }

}
void setup() 
{
  Serial.begin(9600);
  pinMode(12,INPUT);
}

void loop() 
{
  int decrease =digitalRead(12);
  Serial.print("current_angle: ");
  Serial.println(current_angle);
   if(decrease==1)
  {
     dec_flow();
  }
  delay(1000);
}
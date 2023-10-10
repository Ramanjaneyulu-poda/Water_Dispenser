#include <Stepper.h>
int current_angle=0;
// Defines the number of steps per rotation
//const int stepsPerRevolution = 2038;

const int stepsPerRevolution = 57*2;
// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
void start_flow()
{
 int  startStepsPerRevolution =170; // for 30 degrees
  myStepper.setSpeed(10);
	myStepper.step(startStepsPerRevolution);
  current_angle=current_angle+30;
  Serial.print("value of START :");
     Serial.println(current_angle);
}

void stop_flow()
{
  float stopStepsPerRevolution=(current_angle)*(5.66);
  myStepper.setSpeed(10);
	myStepper.step(-(int)stopStepsPerRevolution);
   current_angle=0;
   Serial.print("value of STOP :");
     Serial.println(current_angle);
}
void increase_flow()
{
  if(current_angle>0)
  {
    myStepper.setSpeed(10);
	myStepper.step(stepsPerRevolution);
  current_angle=current_angle-20;
	//delay(1000);
  }
  else
  {
   
    Serial.print("value is max :");
     Serial.println(current_angle);
  }
}
void decrease_flow()
{
  if(current_angle<360)
  {
    myStepper.setSpeed(10);
	myStepper.step(-stepsPerRevolution);
   current_angle=current_angle+20;
	//delay(1000);
  }
  else
  {
      Serial.print("min value");
      Serial.println(current_angle);
  }
  	
}
void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT);
   pinMode(12,INPUT);
   pinMode(0,INPUT);
   pinMode(1,INPUT);
    // Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {
	int increase = digitalRead(13);
  int decrease =digitalRead(12);
  int start=digitalRead(0);
  int stop=digitalRead(1);
//	increase_flow();
  //dec_flow();
 /* if(start==1)  //assuming 1 as button pressed
  {
    increase_flow();
  }*/
Serial.print("current_angle: ");
  Serial.println(current_angle);
  if(start==1)
  {
    start_flow();
  }

  if(stop==1)
  {
    stop_flow();
  }

  if(increase==1)
  {
   increase_flow(); 

  }
  if(decrease==1)
  {
     decrease_flow();
  }
  delay(1000);
}

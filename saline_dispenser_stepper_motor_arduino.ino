
#include <Stepper.h>

int current_angle=0;

// Defines the number of steps per rotation

//const int stepsPerRevolution = 2038;

const int stepsPerRevolution = 57;

// Creates an instance of stepper class

// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void start()
{
  
   myStepper.setSpeed(10);

  myStepper.step(-((stepsPerRevolution*3)/2));

  current_angle=current_angle+30;
}

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

void increase_flow()
{
  if(current_angle<360)
  {
    myStepper.setSpeed(10);
  myStepper.step(-stepsPerRevolution);
   current_angle=current_angle+10;

  //delay(1000);
  }
  else
  {
      Serial.print("min value");
      Serial.println(current_angle);
  }
}

void stop()
{
  //stepsPerRevolution=current_angle;
   myStepper.setSpeed(10);
  myStepper.step((current_angle*5.6));
   current_angle=0;
 //delay(1000);

}


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
    increase_flow();
    Serial.println("blue button");
   }
   if(decrease==1)
   {
    dec_flow();
    Serial.println("blue button");
   }
   if(start1==1)
   {
     start();
    Serial.println("blue button");
   }
   if(stop1==1)
   {
    stop();
    Serial.println("blue button");
   }
  delay(1000);
}

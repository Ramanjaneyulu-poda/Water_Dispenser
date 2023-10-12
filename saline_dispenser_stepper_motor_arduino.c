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

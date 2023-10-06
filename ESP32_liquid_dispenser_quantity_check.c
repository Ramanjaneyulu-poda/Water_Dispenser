[10:42 AM] Tejeswari Devireddy

/*

Deep Sleep with External Wake Up

=====================================

This code displays how to use deep sleep with

an external trigger as a wake up source and how

to store data in RTC memory to use it over reboots

 

 

 

Hardware Connections

======================

Push Button to GPIO 33,32 pulled down with a 10K Ohm

resistor

 

NOTE:

======

Only RTC IO can be used as a source for external wake

source. They are pins: 0,2,4,12-15,25-27,32-39.

*/

#define BUTTON_PIN_BITMASK 0x300000000 // 2^33,2^32 in hex

 

//RTC_DATA_ATTR int bootCount = 0;

RTC_DATA_ATTR int liquid_quantity=100;

int check_button_value()

{

  int button_value;

 int gpio_reason=esp_sleep_get_ext1_wakeup_status();

  Serial.print("test value:");

  Serial.println(gpio_reason);

  button_value=(log(gpio_reason)/log(2));

  Serial.print("GPIO that triggered the wakeup: GPIO");

  Serial.println(button_value);

  return button_value;

}

void check_liquid_quantity()

{

    if(liquid_quantity==0)

    {

      Serial.println("Tank is empty");

    }

    else if(liquid_quantity==5)

    {

       if(check_button_value()==32)

       {

        print_gpio_wakeup();

       }

       else

       {

         Serial.println("Quantity is not available and give indication");

       }

    }

    else if(liquid_quantity==10)

    {

      if(check_button_value()==33|32)

      {

        print_gpio_wakeup();

      }

    }

    else

    {

      print_gpio_wakeup();

    }

}

void print_gpio_wakeup()

{

  int value=check_button_value();

  switch(value)

  {

    case 32: Serial.println("wake up is caused by GPIO 32");

             digitalWrite(4,HIGH);

             delay(1000);

             digitalWrite(4,LOW);

             liquid_quantity-=5;

              break;

    case 33:  Serial.println("wake up is caused by GPIO 33");

              digitalWrite(4,HIGH);

               delay(2000);

              digitalWrite(4,LOW);

              liquid_quantity-=10;

              break;

    default: Serial.println("wakeup was not caused by deep sleep"); break;

 

  }

 

}

void setup(){

  Serial.begin(9600);

 

pinMode(32,INPUT_PULLDOWN);

pinMode(33,INPUT_PULLDOWN);

pinMode(4,OUTPUT);

 

print_gpio_wakeup();

 

  /*

  First we configure the wake up source

  We set our ESP32 to wake up for an external trigger.

  There are two types for ESP32, ext0 and ext1 .

  ext0 uses RTC_IO to wakeup thus requires RTC peripherals

  to be on while ext1 uses RTC Controller so doesnt need

  peripherals to be powered on.

  Note that using internal pullups/pulldowns also requires

  RTC peripherals to be turned on.

  */

 

  esp_sleep_enable_ext1_wakeup(BUTTON_PIN_BITMASK,ESP_EXT1_WAKEUP_ANY_HIGH);

 

  //Go to sleep now

  Serial.println("Going to sleep now");

  esp_deep_sleep_start();

}

 

void loop(){

  //This is not going to be called

}

 

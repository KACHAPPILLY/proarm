#include "IActuator.h"
#include <Servo.h>

class MotorActuator : public IActuator
{
 const int BAUD_RATE = 115200;
 const int DELAY_MS = 15;
 const int pos = 0;       //to store position of servo
 Servo servo1;    //Index finger
 Servo servo2;    //Middle finger
 Servo servo3;    //Ring finger
 Servo servo4;   //Tiny finger
 Servo servo5;    //Thumb finger

    void start()
    {
      Serial.begin(BAUD_RATE);
      servo1.attach(2);
      servo2.attach(3);
      servo3.attach(4);
      servo4.attach(5);
      servo5.attach(6);
    }

    void calibrate()
    {
      for(int pos=0; pos<=180 ; pos++)
      {
        servo1.write(pos);  //move all servo from min to max sweep possible
        servo2.write(pos);
        servo3.write(pos);
        servo4.write(pos);
        servo5.write(pos);
        delay(DELAY_MS);
      }
      for(int pos=180; pos>=1 ; pos--)
      {
        servo1.write(pos);  //move all servo back to original position
        servo2.write(pos);
        servo3.write(pos);
        servo4.write(pos);
        servo5.write(pos);
        delay(DELAY_MS);
      }
    }
    void perform_action(ACTION obj)
    {

    }
    void finish()
    {

    }
};

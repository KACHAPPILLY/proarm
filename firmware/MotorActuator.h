#ifndef MOTOR_ACTUATOR_H
#define MOTOR_ACTUATOR_H

#include "IActuator.h"
#include <Servo.h>

class MotorActuator : public IActuator
{
  const int MAX_POSITION = 180;
  const int MIN_POSITION = 0;

  Servo servo1; //Index finger
  Servo servo2; //Middle finger
  Servo servo3; //Ring finger
  Servo servo4; //Tiny finger
  Servo servo5; //Thumb finger

  void SetAllServos(int val)
  {
    servo1.write(val);
    servo2.write(val);
    servo3.write(val);
    servo4.write(val);
    servo5.write(val);
  }

  public:
    void start()
    {
      servo1.attach(2);
      servo2.attach(3);
      servo3.attach(4);
      servo4.attach(5);
      servo5.attach(6);
    }

    void calibrate()
    {
      for(int pos= MIN_POSITION; pos<=MAX_POSITION ; pos++)
      {
        SetAllServos(pos);  //move all servo from min to max sweep possible
        delay(DELAY_MS);
      }

      for(int pos=MAX_POSITION; pos>=MIN_POSITION; pos--)
      {
        SetAllServos(pos);  //move all servo back to original position
        delay(DELAY_MS);
      }
    }

    void perform_action(Action obj)
    {
      switch (obj)
      {
        case FOLD_ALL_FINGERS:
          SetAllServos(MAX_POSITION);
          break;
        case OPEN_ALL_FINGERS:
          SetAllServos(MIN_POSITION);
          break;
        default:
          break;
      }
    }

    void finish()
    {

    }
};
#endif

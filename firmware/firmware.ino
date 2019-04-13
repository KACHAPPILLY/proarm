#include "Action.h"
#include "ISensor.h"
#include "IActuator.h"
#include "BaseEmgSensor.h"
#include "MotorActuator.h"

ISensor   *sensor   = new BaseEMGSensor();
IActuator *actuator = new MotorActuator();

void setup() {
  // put your setup code here, to run once:
  sensor->start();
  sensor->calibrateStep1();
  sensor->calibrateStep2();

  actuator->start();
  actuator->calibrate();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Action action = NONE;

  action = sensor->get_action();
  actuator->perform_action(action);
}

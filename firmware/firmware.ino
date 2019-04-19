#include <SoftwareSerial.h>

#include "Action.h"
#include "ISensor.h"
#include "IActuator.h"
#include "BaseEmgSensor.h"
#include "MotorActuator.h"


ISensor   *sensor   = new BaseEMGSensor();
IActuator *actuator = new MotorActuator();
char state =0;


void setup() {
  // put your setup code here, to run once:
  sensor->start();
  actuator->start();
  actuator->calibrate();

}

void loop()
{
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
    state = Serial.read();
  }

  if(state == 'a')   //to control via bluetooth command
 { Serial.println("threshold.... ");
  sensor->calibrateStep1();
   Serial.println("threshold is set");

 }

 if(state == 'b')
 {
   Serial.println("peak ......");
   sensor->calibrateStep2();
   Serial.println("peak is set:");
 }
 sensor-> meanabsolutevalue();
 sensor-> meanvalueslope();
 sensor-> willisonamplitude();
 sensor-> variance();
 sensor-> zerocrossing();
 sensor-> waveformlength();
 sensor-> slopesignchange();



  Action action = NONE;

  action = sensor->get_action();
  actuator->perform_action(action);
}

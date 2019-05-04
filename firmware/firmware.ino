#include <SoftwareSerial.h>

#include "Action.h"
#include "ISensor.h"
#include "IActuator.h"
#include "BaseEmgSensor.h"
#include "MotorActuator.h"
#include "Myoware.h"


ISensor   *sensor   = new BaseEMGSensor();
ISensor   *sensor2   = new Myoware();
IActuator *actuator = new MotorActuator();

char state =0;


void setup() {
  // put your setup code here, to run once:
  //callinf functions of first emg sensor
  sensor->start();
  sensor-> meanabsolutevalue();
  sensor-> meanvalueslope();
  sensor-> willisonamplitude();
  sensor-> variance();
  sensor-> zerocrossing();
  sensor-> waveformlength();
  sensor-> slopesignchange();
//caling functions of second emg sensor
  sensor2->calibrateStep1();
  sensor2->calibrateStep2();
  sensor2-> meanabsolutevalue();
  sensor2-> meanvalueslope();
  sensor2-> willisonamplitude();
  sensor2-> variance();
  sensor2-> zerocrossing();
  sensor2-> waveformlength();
  sensor2-> slopesignchange();

  actuator->start();
  actuator->calibrate();

}

void loop()
{
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
    state = Serial.read();
  }

  if(state == 'a')   // trial method to control via bluetooth command
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




  Action action = NONE;

  action = sensor->get_action();
  actuator->perform_action(action);
}

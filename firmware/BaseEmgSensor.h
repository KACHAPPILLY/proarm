#ifndef BASE_EMG_SENSOR_H
#define BASE_EMG_SENSOR_H

#include "ISensor.h"
#include "Action.h"

#define WINDOW_SIZE (100)
#define BAUD_RATE (115200)
#define DELAY_MS (10)

class BaseEMGSensor : public ISensor
{

    const int EMG_PIN   = A1;

    float mThreshold = 0.0f;
    float mPeak      = 0.0f;

    public:

      void start()
      {
        Serial.begin(BAUD_RATE);
      }

      void calibrateStep1()
      {
        //Locals
        float values[WINDOW_SIZE];
        double sum = 0.0f;

        for(int i=0; i < WINDOW_SIZE; ++i)  //to find the average of emg values at rest
        {
          values[i] = analogRead(EMG_PIN);
          sum += values[i];
          delay(DELAY_MS);
        }

        mThreshold = sum/WINDOW_SIZE;
      }

      void calibrateStep2()
      {
        //Locals
        float peaks[WINDOW_SIZE];

        for(int i=0; i<WINDOW_SIZE; ++i)   //to find the peak emg value
        {
          peaks[i] = analogRead(EMG_PIN);
          mPeak = peaks[i] > mPeak ? peaks[i] : mPeak;
          delay(DELAY_MS);
        }
      }


      Action get_action()
      {
        //Locals
        float value = 0.0f;
        Action action = NONE;

        value = analogRead(EMG_PIN);

        if(value >= mThreshold)
        {
          action = FOLD_ALL_FINGERS;
        }
        else
        {
          action = OPEN_ALL_FINGERS;
        }
        
        return action;
      }

      void finish()
      {

      }

};

#endif
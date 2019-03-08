#include "ISensor.h"

#define WINDOW_SIZE 100

class BaseEMGSensor : public ISensor
{

    const int EMG_PIN   = A1;
    const int BAUD_RATE = 115200;
    const int DELAY_MS  = 10;

    float mThreshold = 0.0f;
    float mPeak     = 0.0f;

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
        delay(DELAY_MS)
      }
    }


    ACTION get_action()
    {

    }

    void finish()
    {

    }

};

#ifndef BASE_EMG_SENSOR_H
#define BASE_EMG_SENSOR_H

#include "ISensor.h"
#include "Action.h"

#define WINDOW_SIZE (100)
#define BAUD_RATE (9600)
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
        int sensorValue = analogRead(A0);
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
      void meanabsolutevalue() //MAV
      {
        float values[WINDOW_SIZE];
        float VAL[WINDOW_SIZE];
        double sum = 0.0f; //absolute value
        double N= WINDOW_SIZE;   //no of emg data
        int n;
        float MAV=0.0f;

            for(int i=1; i<=WINDOW_SIZE ; i++)
                {
                  values[i] = analogRead(EMG_PIN);
                  VAL[n]= abs(values[i]);
                  sum += VAL[n];
                }
                  MAV= abs(sum/N) ; //to find absolute mean value of emg data

      }

      void meanvalueslope()
      {
        float values[WINDOW_SIZE];
        double D = 0.0f;
        float VAL[WINDOW_SIZE];
        int n;

            for(int i=1; i<= WINDOW_SIZE; i++)
            {
              values[i]= analogRead(EMG_PIN);
              VAL[n]= abs(values[i]);
              D = VAL[n+1] - VAL[n];
              double DELTA = abs(D);

            }
      }

      void willisonamplitude()
      {
        float WAMP = 0.0f;
        float alpha = 0.0f;
        float values[WINDOW_SIZE];
        int count=0;
        float mThreshold;

            for(int i=1; i<= WINDOW_SIZE ; i++)
            {
              alpha = abs(mThreshold) - abs(values[i]);
              if(alpha<0)
              count++;
            }
             WAMP= count;
        }

        void variance()
        {
          float values[WINDOW_SIZE];
          float VAR = 0.0f;
          float sigma = 0.0f;
          double sum=0.0f;
          double N = WINDOW_SIZE-1 ;

            for(int i=1; i<=WINDOW_SIZE; i++)
             {
               sum += values[i];
             }
             sigma = sum*sum;
             VAR= sigma/N;

        }

        void zerocrossing()
        {
          float values[WINDOW_SIZE];
          float signum = 0.0f;
          double diff=0.0f;
          double mul=0.0f;
          int count = 0;

              for(int i=1; i<WINDOW_SIZE; i++)
              {
                diff = abs(values[i]-values[i+1]);
                mul = (-values[i] * values[i+1]);
                    /*  int sgn(double mul)
                      {
                         return(mul>0)?1 : ((mul<0)?0 : 0) ;
                      }*/

                  if(mul>0 && diff > mThreshold)
                  {
                    count++ ;
                  }
              }

          }

          void waveformlength()
          {
            float values[WINDOW_SIZE];
            double length=0;
            double WAVELENGTH=0;
            for(int i=0; i<WINDOW_SIZE; i++)
            {
              length = abs(values[i]-values[i-1]);
              WAVELENGTH+= length;
            }

          }

          void slopesignchange()
          {
            float values[WINDOW_SIZE];
            double slope=0;
            double SIGN=0;

              for(int i=1; i<=WINDOW_SIZE-1; i++)
              {
                  if(values[i] < values[i+1] && values[i] < values[i-1] || values[i] > values[i+1] && values[i]> values[i-1] )
                  {
                    slope++ ;
                  }
              }
                  SIGN = slope;
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

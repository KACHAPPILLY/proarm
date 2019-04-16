#ifndef SIGNAL_PARAMETER_H
#define SIGNAL_PARAMETER_H

#include "ISensor.h"
#include "Action.h"

#define WINDOW_SIZE = 1000;


class SignalParameter : public Isensor
{
public:
      void meanabsolutevalue() //MAV
      {
        float values[WINDOW_SIZE];
        double sum = 0.0f; //absolute value
        double N= WINDOW_SIZE;   //no of emg data

            for(int i=1; i<=WINDOW_SIZE ; i++)
                {
                  values[i] = analogRead(EMG_PIN);
                  float VAL= abs(value[i])
                  sum += VAL[i];
                }
                  MAV= abs(sum/N) ; //to find absolute mean value of emg data

      }

      void meanvalueslope()
      {
        float values[WINDOW_SIZE];
        double D = 0.0f;

            for(int i=1; i<= WINDOW_SIZE; i++)
            {
              values[i]= analogRead(EMG_PIN);
              float VAL= abs(values[i]);
              D = VAL[i+1] - VAL[i];
              float DELTA = abs(D);

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
          double diff=0.0f;]
          double mul=0.0f;
          float mThreshold;
          int count = 0;

              for(int i=1; i<WINDOW_SIZE; i++)
              {
                diff = abs(values[i]-values[i+1]);
                mul = (-value[i] * value[i+1]);
                      int sgn(double mul)
                      {
                         return(mul>0)?1 : ((mul<0)?0 : 0) ;
                      }

                  if(mul=1 && diff > mThreshold)
                  {
                    count++ ;
                  }
              }

          }

          void waveformlength()
          {
            float values[WINDOW_SIZE];
            double lenght=0;
            double WAVELENGTH=0;
            for(int i=0; i<WINDOW_SIZE; i++)
            {
              length= abs(values[i]-values[i-1]);
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




        }







      }



      }
}

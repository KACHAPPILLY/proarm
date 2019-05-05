#ifndef ISENSOR_H
#define ISENSOR_H

#include "Action.h"

class ISensor
{
	public:
		virtual void   start()=0;
		virtual void   calibrateStep1()=0;
		virtual void   calibrateStep2()=0;
	  	virtual void   meanabsolutevalue()=0;
		virtual void   meanvalueslope()=0;
		virtual void   willisonamplitude()=0;
		virtual void   variance()=0;
		virtual void   zerocrossing()=0;
		virtual void   waveformlength()=0;
		virtual void   slopesignchange()=0;
		virtual Action get_action()=0;
		virtual void   finish()=0;
};
#endif

#ifndef ISENSOR_H
#define ISENSOR_H

#include "Action.h"

class ISensor
{
	public: 
		virtual void start()=0;
		virtual void calibrateStep1()=0;
		virtual void calibrateStep2()=0;
		virtual Action get_action()=0;
		virtual void finish()=0;
};
#endif

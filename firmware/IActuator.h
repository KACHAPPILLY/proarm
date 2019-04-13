#ifndef IACTUATOR_H
#define IACTUATOR_H

#include "Action.h"

class IActuator
{
	public:
		virtual void start()=0;
		virtual void calibrate()=0;
		virtual void perform_action(Action obj)=0;
		virtual void finish()=0;
};
#endif

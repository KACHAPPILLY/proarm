class IActuator
{
  	virtual void start()=0;
  	virtual void calibrate()=0;
  	virtual void perform_action(ACTION obj)=0;
  	virtual void finish()=0;
};

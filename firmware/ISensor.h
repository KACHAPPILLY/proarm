class ISensor
{
	virtual void start()=0;
	virtual void calibrate()=0;
	virtual ACTION get_action()=0;
	virtual void finish()=0;
};

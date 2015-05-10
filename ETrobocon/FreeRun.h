
#ifndef FREERUN_H_
#define FREERUN_H_

#include "MyMotor.h"

namespace ecrobot
{

class FreeRun
{
public:
	void FreeRun::straight(S8 speed,S16 angle);
	void FreeRun::free(S8 speedL,S8 speedR,S16 angle);
	void FreeRun::f_control(S16 angle);
};

}

#endif

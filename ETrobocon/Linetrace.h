#ifndef LINETRACE_H_
#define LINETRACE_H_

#include "MyMotor.h"
#include "Calibration.h"
#include "LightFilter.h"
#include "FreeRun.h"

namespace ecrobot{

	class Linetrace
	{
	public:	
		S16 diff[2];
		F32 integral;
		F64 p,i,d;
		F32 turn;

		F32 Linetrace::PidCalc(S8 edge);
		void Linetrace::On_Off_right(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle);
		void Linetrace::On_Off_left(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle);
		void Linetrace::Pid_left(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle);
		void Linetrace::Pid_right(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle);

	};//class


}//


#endif

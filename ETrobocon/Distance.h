#ifndef DISTANCE_H_
#define DISTANCE_H_

#include "MyMotor.h"

extern "C"
{
	#include "ecrobot_interface.h"
	#include <Math.h>
};


namespace ecrobot{

	class Distance
	{
	public:
		F64 distance;
	
		F64 Distance::get(void);

	};//class

	extern Distance 	dist;

}//




#endif

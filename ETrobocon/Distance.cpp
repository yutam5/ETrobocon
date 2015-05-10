
#include "Distance.h"
using namespace ecrobot;

namespace ecrobot{
	Distance 	dist;
}

#define N 1

F64 Distance::get(void)
{
	distance = M_PI*4.1/180*((motorL.getCount() + motorR.getCount())/2) * N;//距離測定
	distance *= -1;
	return distance;
}

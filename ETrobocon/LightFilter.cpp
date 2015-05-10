
#include "LightFilter.h"
using namespace ecrobot;

LightSensor 	light(PORT_3,TRUE);

#define N 10

//=============================================================================
//光センサの平均化（外乱光対策）
S16 LightFilter::filter(void)
{
	S16 i;
	static S16 lightf[N] = {};
	static S16 ave = 0;
	S16 sum = 0;
	static U8 count = 0;
	
	for(i=0;i<N-1;i++){
		lightf[(N-1)-i] = lightf[(N-2)-i];
	}

	lightf[0] = light.get();

	for(i=0;i<N;i++){
		sum += lightf[i];
	}

	if(count < N)
		count ++;
	
	ave = sum/count;
	
	return ave;
}
//=============================================================================

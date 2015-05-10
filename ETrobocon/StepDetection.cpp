
#include "StepDetection.h"

using namespace ecrobot;

U8 StepDetection::step_detec(void){

	static S16 prev_motor = 0;
	static S16 now_motor = 0;
	static U16 i = 0;

	prev_motor = now_motor;//4ミリ秒前のタイヤの回転角度
	now_motor = motorL.getCount() + motorR.getCount();//現在のタイヤの回転角度

	if(now_motor == prev_motor){
		i++;
		if(i>125){
			flg = 1;
		}
	}else{
		i= 0;
	}

	return flg;

}

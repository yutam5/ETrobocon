
#include "FreeRun.h"

using namespace ecrobot;

#define P_GAIN             2.8F
#define PWM_ABS_MAX          100


//=============================================================================
//ストレート走行
void FreeRun::straight(S8 speed,S16 angle){
		motorL.setPWM(speed);
		motorR.setPWM(speed);
		f_control(angle);//前輪制御
}

//=============================================================================
//自由走行
void FreeRun::free(S8 speedL,S8 speedR,S16 angle){
	motorL.setPWM(speedL);
	motorR.setPWM(speedR);
	f_control(angle);//前輪制御
}

//=============================================================================
//前輪制御　前輪を引数の角度に指定する
void FreeRun::f_control(S16 angle)
{
	float pwm = (float)(angle - motorF.getCount())*P_GAIN; /* 比例制御 */
	/* PWM出力飽和処理 */
	if (pwm > PWM_ABS_MAX)
	{
		pwm = PWM_ABS_MAX;
	}
	else if (pwm < -PWM_ABS_MAX)
	{
		pwm = -PWM_ABS_MAX;
	}

	motorF.setPWM((signed char)pwm);
}

//=============================================================================

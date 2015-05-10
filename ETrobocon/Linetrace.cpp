
#include "Linetrace.h"
using namespace ecrobot;

#define KP 0.25
#define KI 0.00
#define KD 0.025
#define DELTA_T 0.004
#define N 50

	LightFilter 	lightfilt;
	FreeRun 		f;
	LightSensor 	l(PORT_3,TRUE);

//=============================================================================
//PID値算出

F32 Linetrace::PidCalc(S8 edge){
//l.get()光センサ
	diff[0] = diff[1];
	diff[1] = lightfilt.filter() - calib.get();
	integral += (diff[1] + diff[0]) / 2.0 * DELTA_T;

	p = KP * diff[1];//比例（線に近づこうとする力）横にぶらぶらする場合はp値を弱く、戻ってこない場合はｐ値を強く。直線はDはほぼ０
	i = KI * integral;//積分（滑らかな制御をするため）
	d = KD * (diff[1] - diff[0]) /DELTA_T;//微分（Pの値を＋したり−したりする＆今までの値のログをとっている）カーブがきつければきついほどD値が大きくなり、iがほぼなくなる

	turn = edge * (p + i + d);
	return turn;

}
//=============================================================================
//ON-OFF制御　右エッジ
void Linetrace::On_Off_right(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle)
{

	int count = motorF.getCount();//前輪の回転角度取得

	if(lightfilt.filter() < calib.get()){
		//白にいるとき
		if(count>-MaxLeftAngle){
			motorF.setPWM(-100);
		}else{
			motorF.setPWM(000);
		}
		motorR.setPWM(speed);
		motorL.setPWM(0);
	}else{
		//黒にいるとき
		if(count<MaxRightAngle){
			motorF.setPWM(100);
		}else{
			motorF.setPWM(000);
		}
		motorL.setPWM(speed);
		motorR.setPWM(0);
	}

}
//=============================================================================
//ON-OFF制御　左エッジ
void Linetrace::On_Off_left(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle)
{

	int count = motorF.getCount();//前輪の回転角度取得

	if(lightfilt.filter() < calib.get()){
		//白にいるとき
		if(count<MaxRightAngle){
			motorF.setPWM(100);
		}else{
			motorF.setPWM(000);
		}
		motorL.setPWM(speed);
		motorR.setPWM(0);
	}else{
		//黒にいるとき
		if(count>-MaxLeftAngle){
			motorF.setPWM(-100);
		}else{
			motorF.setPWM(000);
		}
		motorR.setPWM(speed);
		motorL.setPWM(0);
	}

}
//=============================================================================
//PID制御 右エッジ
void Linetrace::Pid_right(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle){

	int count = motorF.getCount();//前輪の回転角度取得

	if(lightfilt.filter() < calib.get()){
		//白にいるとき
		if(count>-MaxLeftAngle){
			//motorF.setPWM(-100);
			f.f_control(S16(PidCalc(1)*N));
		}else{
			motorF.setPWM(000);
		}
		motorR.setPWM(S8(speed+PidCalc(1)));
		motorL.setPWM(speed);
	}else{
		//黒にいるとき
		if(count<MaxRightAngle){
			//motorF.setPWM(100);
			f.f_control(S16(PidCalc(1)*N));
		}else{
			motorF.setPWM(000);
		}
		motorL.setPWM(S8(speed-PidCalc(1)));
		motorR.setPWM(speed);
	}

}
//=============================================================================
//PID制御 左エッジ
void Linetrace::Pid_left(S8 speed,S16 MaxLeftAngle,S16 MaxRightAngle){

	int count = motorF.getCount();//前輪の回転角度取得

	if(lightfilt.filter() < calib.get()){
		//白にいるとき
		if(count<MaxRightAngle){
			//motorF.setPWM(100);
			f.f_control(S16(PidCalc(-1)*N));
		}else{
			motorF.setPWM(000);
		}
		motorL.setPWM(S8(speed-PidCalc(-1)));
		motorR.setPWM(speed);
	}else{
		//黒にいるとき
		if(count>-MaxLeftAngle){
			//motorF.setPWM(-100);
			f.f_control(S16(PidCalc(-1)*N));
		}else{
			motorF.setPWM(000);
		}
		motorR.setPWM(S8(speed+PidCalc(-1)));
		motorL.setPWM(speed);
	}

}

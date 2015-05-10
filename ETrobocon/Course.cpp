
#include "Course.h"

using namespace ecrobot;

#define S 0;

	Linetrace 			line;
	FreeRun 			fr;
	StepDetection 		st;

	//ライントレース用の変数
	S8 speed;
	S16 MaxRightAngle;
	S16 MaxLeftAngle;
	//フリー走行用の変数
	S8 speedL;
	S8 speedR;
	S16 angle;


//走行体停止
void Course::stop(void){
	speedL = 0;
	speedR = 0;
	angle = 0;
	fr.free(speedL,speedR,angle);//speedL ,speedR ,Angle
}

//*****************************************************************************
//*********************************INコース**************************************
//*****************************************************************************



//=============================================================================
//inコース ストレート1
void Course::back_in(void){
	speed = 30;
	angle = 0;
	fr.straight(speed,angle);
}
//=============================================================================
//inコース ストレート1
void Course::straight1_in(void){
	speed = -30;
	MaxRightAngle = 30;
	MaxLeftAngle = 30;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ1
void Course::curve1_in(void){
	speed = -25;
	MaxRightAngle = 400;
	MaxLeftAngle = 0;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ2
void Course::curve2_in(void){
	speed = -40;
	MaxRightAngle = 50;
	MaxLeftAngle = 70;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ3
void Course::curve3_in(void){
	speed = -35;
	MaxRightAngle = 0;
	MaxLeftAngle = 300;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ4
void Course::curve4_in(void){
	speed = -25;
	MaxRightAngle = 300;
	MaxLeftAngle = -200;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ5
void Course::curve5_in(void){
	speed = -55;
	MaxRightAngle = 60;
	MaxLeftAngle = 60;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ6
void Course::curve6_in(void){
	speed = -30;
	MaxRightAngle = 0;
	MaxLeftAngle = 450;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ7
void Course::curve7_in(void){
	speed = -20;
	MaxRightAngle = 560;
	MaxLeftAngle = -250;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース グレー1
void Course::gray1_in(void){
	speed = -20;
	MaxRightAngle = 200;
	MaxLeftAngle = 30;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース ストレート2
void Course::straight2_in(void){
	speed = -40;
	MaxRightAngle = 60;
	MaxLeftAngle = 20;
	line.Pid_right(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース 180度回転
void Course::around_in(void){

	if(motorF.getCount() <= -618){
		speedL = 45;
		speedR = -30;
	}else{
		speedL = speedR = 0;
	}

	angle = -620;
	fr.free(speedL,speedR,angle);

}
//=============================================================================
//inコース 前輪を0度に設定
U8 Course::F_set0_in(void){

	static U8 flg = 0;
	speed = 0;
	angle = 0;

	if(motorF.getCount() >= -2){
		flg = 1;
	}

	fr.straight(speed,angle);

	return flg;
}
//=============================================================================
//inコース ストレート3
void Course::straight3_in(void){
	speed = -25;
	MaxRightAngle = 100;
	MaxLeftAngle = 100;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース グレー2
void Course::gray2_in(void){
	speed = -25;
	MaxRightAngle = 30;
	MaxLeftAngle = 50;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ8
void Course::curve8_in(void){
	speed = -15;
	MaxRightAngle = -250;
	MaxLeftAngle = 560;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ9
void Course::curve9_in(void){
	speed = -25;
	MaxRightAngle = 450;
	MaxLeftAngle = 0;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ10
void Course::curve10_in(void){
	speed = -40;
	MaxRightAngle = 60;
	MaxLeftAngle = 60;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ11
void Course::curve11_in(void){
	speed = -30;
	MaxRightAngle = -200;
	MaxLeftAngle = 300;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ12
void Course::curve12_in(void){
	speed = -30;
	MaxRightAngle = 300;
	MaxLeftAngle = 0;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ12_1
void Course::curve12_1_in(void){
	speed = -22;
	MaxRightAngle = 0;
	MaxLeftAngle = 400;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース ストレート4
void Course::straight4_in(void){
	speed = -30;
	MaxRightAngle = 60;
	MaxLeftAngle = 60;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース ストレート5
void Course::straight5_in(S8 sp){
	speed = sp+S;
	MaxRightAngle = 30;
	MaxLeftAngle = 30;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ13
void Course::curve13_in(void){
	speed = -23;
	MaxRightAngle = 400;
	MaxLeftAngle = 400;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース 角度調節2
void Course::adjust_angle2_in(void){
	speed = 0;
	angle = 0;
	fr.straight(speed,angle);
}
//=============================================================================
//inコース カーブ14
void Course::curve14_in(void){
	speed = -23;
	MaxRightAngle = 400;
	MaxLeftAngle = 400;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ15
void Course::curve15_in(void){
	speed = -23;
	MaxRightAngle = 400;
	MaxLeftAngle = 400;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ16
void Course::curve16_in(void){
	speed = -23;
	MaxRightAngle = 400;
	MaxLeftAngle = 400;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//inコース カーブ17
void Course::curve17_in(void){
	speed = -23;
	MaxRightAngle = 400;
	MaxLeftAngle = 300;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
	st.flg = 0;
}
//=============================================================================








//*****************************************************************************
//*********************************モーグル**************************************
//*****************************************************************************



//=============================================================================
//モーグル 段差検知
void Course::step_detec(void){
	speed = -15;
	MaxRightAngle = 60;
	MaxLeftAngle = 60;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//モーグル 右斜め前に進む
void Course::go_forward_1(void){//右斜め前に進む
	speed = -50+S;
	angle = 100;
	fr.straight(speed,angle);
}
//=============================================================================
//モーグル 線を見つける
void Course::find_line(void){//左斜め前に進みながら線をみつける

	if(motorF.getCount() <= -248){
		speed = -38;
	}else{
		speed = 0;
	}

	angle = -250;
	fr.straight(speed,angle);

}
//=============================================================================
//モーグル 直進する
void Course::go_forward_2(void){
	speed = -33+S;
	MaxRightAngle = 40;
	MaxLeftAngle = 40;
	line.Pid_left(speed,MaxLeftAngle,MaxRightAngle);
}
//=============================================================================
//モーグル 直進する
void Course::go_forward_3(void){

	if(motorF.getCount() >= -2){
		speed = -35+S;
	}else{
		speed = 0;
	}

	angle = 0;
	fr.straight(speed,angle);
}
//=============================================================================

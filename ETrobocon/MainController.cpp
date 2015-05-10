/* sample.cpp for TOPPERS/ATK(OSEK) */ 

// ECRobot++ API
#include "Lcd.h"
#include "Motor.h"
#include "Clock.h"
#include "LightSensor.h"

// MyAPI
//#include "Linetrace.h"
#include "Distance.h"
#include "Calibration.h"
#include "SelectCourse.h"
#include "LightFilter.h"
#include "GyroSensor.h"

using namespace ecrobot;

extern "C"
{
/*----------------------------------------------------------------------------*/
/*cのヘッダファイル*/
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "ecrobot_types.h"
#include "mytypes.h"
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/

	Lcd 			lcd;
	Clock 			clk;
	SelectCourse 	selectcourse;
	LightFilter 	lightfilt;

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Declaration and Data*/

//S8 signed char
//U8 unsigned char
//S16 signed short
//U16 unsigned short
//S32 signed long
//U32 unsigned long
//F32 float;
//F64 double;
	
enum IN_OUT{IN,TEST} in_out = IN;//INかOUTか設定
/*----------------------------------------------------------------------------*/

// nxtOSEK hook to be invoked from an ISR in category 2
void user_1ms_isr_type2(void)
{
	SleeperMonitor(); // needed for I2C device and Clock classes
}

TASK(TaskMain)
{
	//S8 speed = -60;//モータの回転速度　最大速100　逆最大速-100
	/*キャリブレーション*/
	//calib.set();
	/*比率設定*/
	calib.b = 1;calib.w = 1;calib.g = 0; //黒:白:灰 1:1:0
	/*calib.ratio()を呼び出す前に比率を設定する必要がある。*/
	calib.ratio();

	calib.start();//スタート指示

	while(1){
		switch(in_out){

			case IN:
			selectcourse.select_in();
			break;

			case TEST:
			selectcourse.select_mogul();
			break;

			default:
			break;
		}

		clk.sleep(4); // sleep 4msec
	}

}//TaskMain


TASK(TaskLcd)
{
	lcd.clear();
	clk.reset();
	while(1)
	{
		if(in_out == IN){
			lcd.cursor(0, 0);
			lcd.putf("s", "Course: IN");
			lcd.cursor(0, 1);
			lcd.putf("s","Edge: RIGHT");
		}
		if(in_out == TEST){
			lcd.cursor(0, 0);
			lcd.putf("s", "****TEST****");
			lcd.cursor(0, 1);
			lcd.putf("s", "****TEST****");
		}
		lcd.cursor(0, 2);
		lcd.putf("sd", "Black: ", calib.black ,2);
		lcd.cursor(0, 3);
		lcd.putf("sd", "White: ", calib.white ,2);
		lcd.cursor(0, 4);
		lcd.putf("sd", "Gray: ", calib.gray ,2);
		lcd.disp();

		clk.sleep(200); // sleep 200msec
	}
}//taskLcd

}//extern c

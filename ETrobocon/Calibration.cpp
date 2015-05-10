
#include "LightSensor.h"
#include "TouchSensor.h"
#include "Clock.h"
#include "Calibration.h"
#include "Speaker.h"

using namespace ecrobot;

namespace ecrobot{
	Calibration 	calib(645,541,600);//black = 711,white = 554,gray = 624   ***7・210***
}

LightSensor 	light1(PORT_3,TRUE);
TouchSensor		touch1(PORT_4);
Clock 			clk1;
Speaker			spk;


/*----------------------------------------------------------------------------*/
//コンストラクタ 1
Calibration::Calibration(){
	black = 0; white = 0; gray = 0;
}
/*----------------------------------------------------------------------------*/
//コンストラクタ 2
Calibration::Calibration(U16 blk,U16 wht,U16 gry){
	black = blk; white = wht; gray = gry;
}
/*----------------------------------------------------------------------------*/
//黒、白、灰それぞれの光量を設定
void Calibration::set(void)
{ 
	while(touch1.isPressed() == FALSE){
		black = light1.get();
	}

	spk.playTone(200,300,40);
	clk1.sleep(1000);

	while(touch1.isPressed() == FALSE){
		white = light1.get();
	}

	spk.playTone(400,300,40);
	clk1.sleep(1000);

	while(touch1.isPressed() == FALSE){
		gray = light1.get();
	}

	spk.playTone(600,300,40);
	clk1.sleep(1000);

}
/*----------------------------------------------------------------------------*/
//スタートさせる
void Calibration::start(void){
	while(touch1.isPressed() == FALSE){
		//ボタンを押すとスタート
	}
	spk.playTone(800,300,40);
}
/*----------------------------------------------------------------------------*/
//黒、白、灰の比率を設定する
void Calibration::ratio(void)
{
	target = (b * black + w * white + g * gray)/(b + w + g);
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
//比率に応じたターゲット値を返す
S16 Calibration::get(void)
{
	return target;
}
/*----------------------------------------------------------------------------*/

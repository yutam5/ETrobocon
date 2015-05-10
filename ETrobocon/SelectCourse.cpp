
#include "SelectCourse.h"

//#define N 0.991	

#define N 1
#define M 1

using namespace ecrobot;

//inコース
enum{back_in = 0 ,straight1_in ,curve1_in ,curve2_in ,curve3_in ,curve4_in ,curve5_in ,curve6_in ,
curve7_in ,gray1_in ,straight2_in ,around_in ,straight3_in ,F_set0_in ,gray2_in ,curve8_in,
curve9_in ,curve10_in ,curve11_in ,curve12_in ,curve12_1_in ,straight4_in ,straight5_in ,
curve13_in ,adjust_angle2_in ,curve14_in ,curve15_in ,curve16_in ,curve17_in ,straight6_in ,mogul
};
Course 			course;
Speaker			spk1;
LineDetection 	linedt;
GyroSensor 		gyro(PORT_1);
StepDetection 	step;


extern "C"{
//=============================================================================
void SelectCourse::select_in(void){
//コースを選択 inコース

	//staticがあると関数が呼ばれる度に値が初期化されない
	static S32 timeprev = 0;
	static U16 mode = 0;
	static S8 sp = -35;
	static S8 t = 0;

	switch (mode){
//=============================================================================
		case back_in:
		course.back_in();
		if(dist.get() <= -35*N) {// 練習:r 大会: t
			mode = straight1_in;
		}
		break;
//=============================================================================
		case straight1_in:
		course.straight1_in();
		if(dist.get() >= -3*N){
			mode = curve1_in;
		}
		break;
//=============================================================================
		case curve1_in:
		course.curve1_in();
		if(dist.get() >= 70*N){
			mode = curve2_in;
		}
		break;
//=============================================================================
		case curve2_in:
		course.curve2_in();
		if(dist.get() >= 100*N){
			mode = curve3_in;
		}
		break;
//=============================================================================
		case curve3_in:
		course.curve3_in();
		if(dist.get() >= 146*N){
			mode = curve4_in;
		}
		break;
//=============================================================================
		case curve4_in:
		course.curve4_in();
		if(dist.get() >= 175*N){
			mode = curve5_in;
		}
		break;
//=============================================================================		
		case curve5_in:
		course.curve5_in();
		if(dist.get() >= 270*N){
			mode = curve6_in;
		}
		break;
//=============================================================================		
		case curve6_in:
		course.curve6_in();
		if(dist.get() >= 310*N){
			mode = curve7_in;
		}
		break;
//=============================================================================
		case curve7_in:
		course.curve7_in();
		if(dist.get() >= 335*N){//灰色手前になったら
			calib.b = 0;calib.w = 1;calib.g = 1;//比率変更
			calib.ratio();
			mode = gray1_in;
		}
		break;
//=============================================================================
		case gray1_in:
		course.gray1_in();
		if(dist.get() >= 350*N){//灰色終わりになったら
			calib.b = 1;calib.w = 1;calib.g = 0;//比率変更
			calib.ratio();
			mode = straight2_in;
		}
		break;
//=============================================================================	
		case straight2_in:
		course.straight2_in();
		if(dist.get() >= 400*N){
			timeprev = systick_get_ms();
			mode = around_in;
		}
		break;
//=============================================================================
		case around_in://180度回転
		course.around_in();
		if((systick_get_ms() - timeprev) >= 1500){
			if(linedt.line_detec()){
				mode = F_set0_in;
			}
		}
		break;
//=============================================================================	
		case F_set0_in://前輪を0度に設定する
		if(course.F_set0_in()){
			mode = straight3_in;
		}
		break;
//=============================================================================	
		case straight3_in:
		course.straight3_in();
		if(dist.get() >= 427*N){//灰色手前になったら
			calib.b = 0;calib.w = 1;calib.g = 1;//比率変更
			calib.ratio();
			mode = gray2_in;
		}
		break;
//=============================================================================	
		case gray2_in:
			course.gray2_in();
		if(dist.get() >= 442*N){//灰色終わりになったら
			calib.b = 1;calib.w = 1;calib.g = 0;//比率変更
			calib.ratio();
			mode = curve8_in;
		}
		break;
//=============================================================================	
		case curve8_in:
		course.curve8_in();
		if(dist.get() >= 483*N){
			mode = curve9_in;
		}
		break;
//=============================================================================
		case curve9_in:
		course.curve9_in();
		if(dist.get() >= 520*N){
			mode = curve10_in;
		}
		break;
//=============================================================================
		case curve10_in:
		course.curve10_in();
		if(dist.get() >= 603*N){
			mode = curve11_in;
		}
		break;
//=============================================================================	
		case curve11_in:
		course.curve11_in();
		if(dist.get() >= 638*N){
			mode = curve12_in;
		}
		break;
//=============================================================================	
		case curve12_in:
		course.curve12_in();
		if(dist.get() >= 725*N){
			mode = curve12_1_in;
		}
		break;
//=============================================================================	
		case curve12_1_in:
		course.curve12_1_in();
		if(dist.get() >= 795*N){
			mode = straight4_in;
		}
		break;
//=============================================================================	
		case straight4_in:
		course.straight4_in();
		if(dist.get() >= 820*N){
			sp = -35;//35
			mode = straight5_in;
		}
		break;
//=============================================================================	
		case straight5_in:
		t++;
		if(sp >= -75){
			if(t >= 15){
				sp--;
				t = 0;
			}
		}
		course.straight5_in(sp);

		if(dist.get() >= 1085*N){
			mode = curve13_in;
			calib.b = 3;calib.w = 2;calib.g = 0;//比率変更
			calib.ratio();
		}
		break;
//=============================================================================		
		case curve13_in:
		course.curve13_in();
		if(dist.get() >= 1225*N){
			mode = adjust_angle2_in;
		}
		break;
//=============================================================================		
		case adjust_angle2_in:
		course.adjust_angle2_in();
		if(motorF.getCount() >= -3 || (systick_get_ms() - timeprev) >= 1000){
			mode = curve14_in;
		}
		break;
//=============================================================================		
		case curve14_in:
		course.curve14_in();
		if(dist.get() >= 1275*N){
			mode = curve15_in;
		}
		break;
//=============================================================================		
		case curve15_in:
		course.curve15_in();
		if(dist.get() >= 1330*N){
			calib.b = 1;calib.w = 1;calib.g = 0;//比率変更
			calib.ratio();
			mode = curve16_in;
		}
		break;
//=============================================================================		
		case curve16_in:
		course.curve16_in();
		if(dist.get() >= 1375*N){
			mode = curve17_in;
		}
		break;
//=============================================================================		
		case curve17_in:
		course.curve17_in();
		if(dist.get() >= 1425*N){
			mode = mogul;
		}
		break;
//=============================================================================
		case mogul:
		select_mogul();
		break;
//=============================================================================		
















		default:
		break;
//=============================================================================		
	}//switch

}//select_in()





//******************************************************************************
//******************************************************************************
//******************************************************************************



//モーグル
enum{step_detec = 0 ,go_forward_1 , find_line ,go_forward_2 ,go_forward_3 ,go_back_1};

void SelectCourse::select_mogul(void){
//モーグル

	static U16 mode = 0;

	switch (mode){
//=============================================================================		
		case step_detec://前輪が段差を上り、後輪が段差前で止まるまで
		course.step_detec();
		if(step.step_detec()){//step_detec()から1が返されたら
			spk1.playTone(800,300,40);
			motorR.reset();
			motorL.reset();
			mode = go_forward_1;
		}
		break;
//=============================================================================	
		case go_forward_1://前進して走行体が完全に登り切るまで
		course.go_forward_1();
		if(dist.get() >= 25){
			linedt.blkflg = 0;//linedetection使用前に必要
			linedt.lineflg = 0;//linedetection使用前に必要
			mode = find_line;
		}
		break;
//=============================================================================	
		case find_line:
		course.find_line();
		if(linedt.line_detec()){//ラインを検知したら
			mode = go_forward_2;
		}
		break;
//=============================================================================				
		case go_forward_2://走行体がモーグルから降りる前
		course.go_forward_2();
		if(dist.get() >= 70){
			mode = go_forward_3;
		}
		break;
//=============================================================================		
		case go_forward_3:
		course.go_forward_3();
		if(dist.get() >= 150){
			course.stop();
		}
		break;
//=============================================================================		

		default:
		break;
//=============================================================================		
	}//switch

}//mogul



}//extern c

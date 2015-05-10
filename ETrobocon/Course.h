#ifndef COURSE_H_
#define COURSE_H_

#include "Linetrace.h"
#include "Distance.h"
#include "MyMotor.h"
#include "FreeRun.h"
#include "Calibration.h"
#include "StepDetection.h"

namespace ecrobot{

	class Course
	{
	public:
		void Course::stop(void);

		//inコース
		void Course::back_in(void);
		void Course::straight1_in(void);
		void Course::curve1_in(void);
		void Course::curve2_in(void);
		void Course::curve3_in(void);
		void Course::curve4_in(void);
		void Course::curve5_in(void);
		void Course::curve6_in(void);
		void Course::curve7_in(void);
		void Course::gray1_in(void);
		void Course::straight2_in(void);
		void Course::around_in(void);
		U8 Course::F_set0_in(void);
		void Course::straight3_in(void);
		void Course::gray2_in(void);
		void Course::curve8_in(void);
		void Course::curve9_in(void);
		void Course::curve10_in(void);
		void Course::curve11_in(void);
		void Course::curve12_in(void);
		void Course::curve12_1_in(void);
		void Course::straight4_in(void);
		void Course::straight5_in(S8 sp);
		void Course::curve13_in(void);
		void Course::adjust_angle2_in(void);
		void Course::curve14_in(void);
		void Course::curve15_in(void);
		void Course::curve16_in(void);
		void Course::curve17_in(void);




		//モーグル
		void Course::step_detec(void);
		void Course::go_forward_1(void);
		void Course::find_line(void);
		void Course::go_forward_2(void);
		void Course::go_forward_3(void);

	};//class


}//




#endif

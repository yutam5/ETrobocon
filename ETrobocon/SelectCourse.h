
#ifndef SELECTCOURSE_H_
#define SELECTCOURSE_H_

#include "Distance.h"
#include "Course.h"
#include "Speaker.h"
#include "StepDetection.h"
#include "LineDetection.h"
#include "MyMotor.h"
#include "GyroSensor.h"


namespace ecrobot
{

class SelectCourse
{
public:
	void SelectCourse::select_in(void);
	void SelectCourse::select_out(void);
	void SelectCourse::select_mogul(void);
};
}

#endif

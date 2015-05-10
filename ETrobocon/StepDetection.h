
#ifndef STEPDETECTION_H_
#define STEPDETECTION_H_

#include "MyMotor.h"

namespace ecrobot
{


class StepDetection
{
public:
	U8 flg;

	U8 step_detec(void);
};
}

#endif

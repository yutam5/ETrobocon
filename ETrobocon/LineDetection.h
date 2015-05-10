
#ifndef LINEDETECTION_H_
#define LINEDETECTION_H_

#include "Calibration.h"
#include "LightFilter.h"

namespace ecrobot
{

class LineDetection
{
public:
	U8 LineDetection::line_detec(void);
	U8 blkflg;
	U8 lineflg;

};
}

#endif


#include "LineDetection.h"

using namespace ecrobot;

LightFilter 	filt;

U8 LineDetection::line_detec(void){


	if(filt.filter() >= (calib.black - 20) ){
		blkflg = 1;
	}

	if( blkflg == 1 && filt.filter() <= calib.target ){
		lineflg = 1;
	}else{
		lineflg = 0;
	}

	return lineflg;

}

#ifndef CALIBRATION_H_
#define CALIBRATION_H_

#include "LightSensor.h"

namespace ecrobot{
	class Calibration{

	public:
		U16		target;//黒と白の間の値
		U16 	black,white,gray;//それぞれの値
		U8 		b,w,g;//比率

		void set (void);
		void start(void);
		void ratio(void);
		S16 get(void);
		Calibration();
		Calibration(U16 blk,U16 wht,U16 gry);
	};

	extern Calibration 		calib;

}

#endif

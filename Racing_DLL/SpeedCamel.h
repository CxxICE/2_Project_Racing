#pragma once

#include "DLL_EXP.h"
#include "GroundVehicle.h"

class CL_DLL_API SpeedCamel : public GroundVehicle
{
public:
	SpeedCamel();
	double raceTime(int distance) override;
private:
	double restTime_1 = 5;
	double restTime_2 = 6.5;
	double restTime_3more = 8;
};


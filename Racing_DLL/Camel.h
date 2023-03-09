#pragma once

#include "DLL_EXP.h"
#include "GroundVehicle.h"

class CL_DLL_API Camel : public GroundVehicle
{
public:
	Camel();
	double raceTime(int distance) override;
private:
	double restTime_1 = 5;
	double restTime_2more = 8;
};


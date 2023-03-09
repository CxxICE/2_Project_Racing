#pragma once

#include "DLL_EXP.h"
#include "GroundVehicle.h"

class CL_DLL_API SpecialBoots : public GroundVehicle
{
public:
	SpecialBoots();
	double raceTime(int distance) override;
private:
	double restTime_1 = 10;
	double restTime_2more = 5;
};


#pragma once

#include "DLL_EXP.h"
#include "GroundVehicle.h"

class CL_DLL_API Centaur : public GroundVehicle
{
public:
	Centaur();
	double raceTime(int distance) override;
private:
	double restTime_all = 2;
};


#pragma once

#include "DLL_EXP.h"
#include "AirVehicle.h"

class CL_DLL_API Eagle : public AirVehicle
{
public:
	Eagle();
	double raceTime(int distance) override;
private:
	double distanceFactor_all = 0.06;
};


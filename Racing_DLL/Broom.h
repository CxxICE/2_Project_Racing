#pragma once

#include "DLL_EXP.h"
#include "AirVehicle.h"

class CL_DLL_API Broom : public AirVehicle
{
public:
	Broom();
	double raceTime(int distance) override;
private:
	double distanceFactorProgressive = 0.01;
};


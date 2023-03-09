#pragma once

#include "DLL_EXP.h"
#include "AirVehicle.h"

class CL_DLL_API FlyingCarpet : public AirVehicle
{
public:
	FlyingCarpet();
	double raceTime(int distance) override;
private:
	double distanceFactor_less1000 = 0;
	double distanceFactor_less5000 = 0.03;
	double distanceFactor_less10000 = 0.1;
	double distanceFactor_10000more = 0.05;
};


#pragma once

#include "DLL_EXP.h"
#include "Vehicle.h"

class CL_DLL_API GroundVehicle : public Vehicle
{
public:
	GroundVehicle();
	virtual double raceTime(int distance) override;
protected:
	double timeToRest = 0;
};


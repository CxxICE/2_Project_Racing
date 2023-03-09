#pragma once

#include "DLL_EXP.h"
#include "Vehicle.h"

class CL_DLL_API AirVehicle : public Vehicle
{
public:
	AirVehicle();
	virtual double raceTime(int distance) override;	
};


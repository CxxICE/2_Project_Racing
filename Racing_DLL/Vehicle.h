#pragma once

#include "DLL_EXP.h"
#include "TypeReg.h"
#include "TypeEnvironment.h"

class CL_DLL_API Vehicle
{
public:
	Vehicle();
	static Vehicle* creation(TypeReg type);
	virtual double raceTime(int distance);
	const char* getName();
	TypeReg getType();
	void setReg(bool reg_);
	bool getReg();
	TypeEnvironment getEnviroment();
protected:
	const char* name;
	double speed = 0;
	TypeReg type{};
	TypeEnvironment enviroment{};
	bool reg = 0;
};


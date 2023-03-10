#include "Vehicle.h"

#include "Camel.h"
#include "SpeedCamel.h"
#include "Centaur.h"
#include "SpecialBoots.h"
#include "Eagle.h"
#include "Broom.h"
#include "FlyingCarpet.h"

Vehicle::Vehicle()
{
	name = "";
}

const char* Vehicle::getName()
{
	return name;
}

TypeReg Vehicle::getType()
{
	return type;
}

void Vehicle::setReg(bool reg_)
{
	reg = reg_;
}

bool Vehicle::getReg()
{
	return reg;
}

TypeEnvironment Vehicle::getEnviroment()
{
	return enviroment;
}

double Vehicle::raceTime(int distance) { return 0; }

Vehicle* Vehicle::creation(TypeReg type)
{
	Vehicle *outVehicle = nullptr;
	switch (type)
	{
	case(TypeReg::CAMEL):
		outVehicle = new Camel();
		break;
	case(TypeReg::SPEEDCAMEL):
		outVehicle = new SpeedCamel();
		break;
	case(TypeReg::CENTAUR):
		outVehicle = new Centaur();
		break;
	case(TypeReg::BOOTS):
		outVehicle = new SpecialBoots();
		break;
	case(TypeReg::EAGLE):
		outVehicle = new Eagle();
		break;
	case(TypeReg::BROOM):
		outVehicle = new Broom();
		break;
	case(TypeReg::CARPET):
		outVehicle = new FlyingCarpet();
		break;
	}
	return outVehicle;
}
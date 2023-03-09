#include "Eagle.h"

Eagle::Eagle()
{
	name = "Îð¸ë";
	speed = 8;
	type = TypeReg::EAGLE;
}

double Eagle::raceTime(int distance)
{
	double distance_new = distance * (1-distanceFactor_all);
	return distance_new / speed;
}
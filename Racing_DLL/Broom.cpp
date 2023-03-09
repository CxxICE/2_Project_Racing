#include "Broom.h"

Broom::Broom()
{
	name = "Метла";
	speed = 20;
	type = TypeReg::BROOM;
}

double Broom::raceTime(int distance)
{
	double distanceFactor_new;
	int k = distance / 1000;
	distanceFactor_new = distanceFactorProgressive * k;
	double distance_new = distance * (1 - distanceFactor_new);
	return distance_new / speed;
}
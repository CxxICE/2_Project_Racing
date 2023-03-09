#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet()
{
	name = "Ковёр-самолёт";
	speed = 10;
	type = TypeReg::CARPET;
}

double FlyingCarpet::raceTime(int distance)
{
	double distance_new;
	if (distance < 1000)
	{
		distance_new = distance *(1 - distanceFactor_less1000);
	}
	else if (distance < 5000)
	{
		distance_new = distance * (1 - distanceFactor_less5000);
	}
	else if (distance < 10000)
	{
		distance_new = distance * (1 - distanceFactor_less10000);
	}
	else
	{
		distance_new = distance * (1 - distanceFactor_10000more);
	}	
	return distance_new / speed;
}
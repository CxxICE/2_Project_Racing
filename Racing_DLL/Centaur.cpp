#include "Centaur.h"

Centaur::Centaur()
{
	name = "Кентавр";
	speed = 15;
	timeToRest = 8;
	type = TypeReg::CENTAUR;
}

double Centaur::raceTime(int distance)
{
	double time, goTime;
	int restCount;
	goTime = distance / speed;
	restCount = static_cast<int>(goTime / timeToRest);

	//проверка остатка == 0, если true, значит последний отдых будет за пределами времени гонки и его учитывать не нужно
	if (goTime - restCount * timeToRest == 0) { restCount--; }

	time = goTime + restTime_all * restCount;
	return time;
}
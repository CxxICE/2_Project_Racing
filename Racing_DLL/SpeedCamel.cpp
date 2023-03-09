#include "SpeedCamel.h"

SpeedCamel::SpeedCamel()
{
	name = "Верблюд-быстроход";
	speed = 40;
	timeToRest = 10;
	type = TypeReg::SPEEDCAMEL;
}

double SpeedCamel::raceTime(int distance)
{
	double time, goTime;
	int restCount;
	goTime = distance / speed;
	restCount = static_cast<int>(goTime / timeToRest);

	//проверка остатка == 0, если true, значит последний отдых будет за пределами времени гонки и его учитывать не нужно
	if (goTime - restCount * timeToRest == 0) { restCount--; }

	if (restCount == 0)										//дистанция меньше времени до первого отдыха или первый отдых на границе конца гонки
	{
		time = goTime;
	}
	else if (restCount == 1)								//дистанция требует ровно одного отдыха и он не на границе конца гонки
	{
		time = goTime + restTime_1;
	}
	else if (restCount == 2)								//дистанция требует ровно двух отдыхов и последний не на границе конца гонки
	{
		time = goTime + restTime_1 + restTime_2;
	}
	else													//дистанция требует более или ровно три отдыха и последний не на границе конца гонки
	{
		time = goTime + restTime_1 + restTime_2 + restTime_3more * (restCount - 2);
	}
	return time;
}
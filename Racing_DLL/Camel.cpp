#include "Camel.h"

Camel::Camel()
{
	name = "Верблюд";
	speed = 10;
	timeToRest = 30;
	type = TypeReg::CAMEL;
}

double Camel::raceTime(int distance)
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
	else													//дистанция требует более или ровно два отдыха и последний не на границе конца гонки
	{
		time = goTime + restTime_1 + restTime_2more * (restCount - 1);
	}
	return time;
}